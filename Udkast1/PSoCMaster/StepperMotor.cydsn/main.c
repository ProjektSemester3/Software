#include "project.h"
#include <stdio.h>

uint8 status;

void updateStatus(uint8);
void writeToXY(uint8);
void writeToZ(uint8);   // Sensor used on x-axis is also used on z-axis

enum SPI_protocol {
    
    // Commands from DK8k to PSoC-master/from PSoC-master to -slaves
    GET_STATUS = 0x00,
    LOCATE_XY = 0x01,
    LOCATE_Z_1 = 0x02,
    LOCATE_Z_2 = 0x03,
    OPEN_BOTTLE = 0x04,
    
    // Command from PSoC-master to -slaves
    RESET = 0x05,
    DISPENSE_CORK = 0x06,
    
    // Feedback messages from PSoC-slaves to -master
    VALID_XY = 0x10,
    INVALID_XY = 0x20,
    RESET_XY_ON_SUCCESS = 0x35, // Only if bottle has been opened
    MOVED_Z_1 = 0x11,
    MOVED_Z_2 = 0x12,
    VALID_Z = 0x13,
    RESET_Z = 0x34,
    OPENING_SUCCESSFUL = 0x15,
    CORK_DISPENSED = 0x16,
    READY_TO_DRINK = 0x17,
    
    // Feedback messages from PSoC-master to DK8k/from PSoC-slaves to -master
    VALID_TYPE = 0x14,
    INVALID_TYPE = 0x21,
    NO_BOTTLE = 0x22,
    DEFAULT = 0x30,
    WRONG_COMMAND = 0x31,
    WRONG_DEVICE = 0x32,
    IN_PROCESS = 0x33,
};

CY_ISR(isr_1)
{
    uint16 rxvalue;
	uint8 cmd;
	uint8 addr;
    
    rxvalue = SPIS_1_ReadRxData(); // This also clears Rx Status Register
    SPIS_1_ClearRxBuffer();
    
    /* Protocol - Write 8-bit: 
	 * |CMD|  ADDR  |    DATA    |
	 *  1 1 1      8 7          0
	 *	5 4 3
	 */

	/* Protocol - Read 16-bit: 
	 * |CMD|  ADDR  |  Not Used  |       |           DATA          |
	 *  1 1 1      8 7          0         1                       0
	 *	5 4 3                             5
	 */
    
    cmd = (rxvalue >> 14) & 0x3;  // cmd = rdvalue[15:14]
	addr = (rxvalue >> 8) & 0x3f; // addr = rdvalue[13:8]
    
    switch (addr) {
		case 0x1:
			switch(cmd) {
                
                // Write status of bottle to DK8k
				case GET_STATUS:
					updateStatus(status);
                    
                    if(status != IN_PROCESS || status != VALID_TYPE) {
                        status = DEFAULT;
                    }
					break;
                
                // Registrate bottle
				case LOCATE_XY:
                    updateStatus(IN_PROCESS);
                    
                    // Validate thickness of bottle neck
                    writeToXY(cmd);
					break;
                
                // Open bottle
                case OPEN_BOTTLE:
                    updateStatus(IN_PROCESS);
                    
                    // Open bottle
                    writeToXY(cmd);
                    break;
                
                // Unidentified command
                default:
                    updateStatus(WRONG_COMMAND);
                    break;
            }
			break;
        
        // Unidentified address
		default:
			updateStatus(WRONG_DEVICE);
			break;
	}
}

CY_ISR(isr_2)
{
    uint8 fb;
    fb = SPIM_1_ReadRxData();
    SPIM_1_ClearRxBuffer();
    
    switch(fb) {
        
        // Thickness of bottle neck OK
        case VALID_XY:
            
            // Position x-sensor to just under top of bottle
            writeToZ(LOCATE_Z_1);
            break;
        
        // X-sensor positioned to just under top of bottle
        case MOVED_Z_1:
            
            // Validate top of bottle detected
            writeToXY(LOCATE_Z_1);
            break;
        
        // Top of bottle detected
        case VALID_Z:
            
            // Position x-sensor to just over top of bottle
            writeToZ(LOCATE_Z_2);
            break;
        
        // X-sensor positioned to just over top of bottle
        case MOVED_Z_2:
            
            // Validate no bottle detected
            writeToXY(LOCATE_Z_2);
            break;
        
        // Valid bottle
        case VALID_TYPE:
            updateStatus(fb);
            break;
        
        // Bottle open and ready to drink
        case OPENING_SUCCESSFUL:
            writeToZ(RESET);
            break;
        
        // X-sensor positioned to start-position on z-axis
        case RESET_Z:
            
            // Position x- and y-sensor to start-positions on respectively x- and y-axes
            writeToXY(RESET);
            break;
        
        // X- and y-sensor positioned to start-positions on respectively x- and y-axes
        case RESET_XY_ON_SUCCESS:
            
            // Dispense of cork
            writeToXY(DISPENSE_CORK);
            break;
        
        // Cork dispensed of
        case CORK_DISPENSED:
            updateStatus(READY_TO_DRINK);
            break;
        
        // No bottle detected
        case NO_BOTTLE:
            updateStatus(fb);
            
            // Position x- and y-sensor to start positions on respectively x- and y-axes
            writeToXY(RESET);
            break;
        
        // Invalid object inserted
        case INVALID_XY:
            updateStatus(INVALID_TYPE);
            
            // Position x- and y-sensor to start positions on respectively x- and y-axes
            writeToXY(RESET);
            break;
        
        // Invalid object inserted/Bottle open
        case INVALID_TYPE:
            updateStatus(fb);
            
            // Position x-sensor to start-position on z-axis
            writeToZ(RESET);
            break;
        
        default:
            updateStatus(fb);
            break;
    }
}

int main()
{
    updateStatus(DEFAULT);
    CyGlobalIntEnable;
    
    SPIS_1_Start();
	SPIS_1_EnableRxInt();
    isr_1_StartEx(isr_1);
	SPIS_1_ClearFIFO();
	SPIS_1_ClearTxBuffer();
    
    SPIM_1_Start();
    SPIM_1_EnableRxInt();
    isr_2_StartEx(isr_2);
	SPIM_1_ClearFIFO();
	SPIM_1_ClearTxBuffer();

    for(;;)
    {
    }
}

// Update status of master-PSoC/message to be sent to DK8k
void updateStatus(uint8 stat)
{
    status = stat;
    SPIS_1_ClearTxBuffer();
    SPIS_1_WriteTxData(status);
}

// Write command to PSoC-slave 1
void writeToXY(uint8 cmd)
{
    SPIM_1_ClearTxBuffer();
    SS_XY_Write(0);
    SPIM_1_WriteTxData(cmd);
    SS_XY_Write(1);
}

// Write command to PSoC-slave 2
void writeToZ(uint8 cmd)
{
    SPIM_1_ClearTxBuffer();
    SS_Z_Write(0);
    SPIM_1_WriteTxData(cmd);
    SS_Z_Write(1);
}

/* [] END OF FILE */
