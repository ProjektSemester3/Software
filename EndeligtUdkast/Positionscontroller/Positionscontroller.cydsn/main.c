#include "project.h"
#include "MotorsXY.h"
#include "MotorZ.h"
#include <stdio.h>

uint8 enabled = DEFAULT;

CY_ISR(isr_1)
{
    uint16 rxvalue;
	uint8 addr;
    uint8 data;
    
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
    
    addr = (rxvalue >> 8) & 0x3f; // addr = rdvalue[13:8]
    data = rxvalue & 0xff;
    
    switch (addr) {
		case 0x01:
			switch(data) {
                
                // Write status of bottle to DK8k
				case GET_STATUS:
					updateStatus(status);
                    break;
                
                // Open bottle
                case OPEN_BOTTLE:
                    updateStatus(IN_PROCESS);
                    
                    // Open bottle
                    enabled = data;
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
        case BOTTLE_OPENED:
            enabled = fb;
            break;
        case CORK_DISPOSED:
            updateStatus(READY_TO_DRINK);
            break;
        default:
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
    
    isr_x_home_StartEx(isr_x_home);
    isr_x_end_StartEx(isr_x_end);
    isr_y_home_StartEx(isr_y_home);
    isr_y_end_StartEx(isr_y_end);
    isr_z_home_StartEx(isr_z_home);
    isr_z_end_StartEx(isr_z_end);
    
    PWM_X_Start();
    PWM_Y_Start();
    PWM_Z_Start();
    
    for(;;)
    {
        switch(enabled) {
            
            case OPEN_BOTTLE:
                updateStatus(IN_PROCESS);
                
                if(locateX() || locateY()) {
                    resetXY();
                    enabled = DEFAULT;
                    break;
                }
                
                if(confirmHeight()) {
                    resetZ();
                    enabled = DEFAULT;
                    break;
                }
                
                positionOpMech();
                lockBottle();
                
                sendCommand(OPEN_BOTTLE);
                
                enabled = DEFAULT;
                break;
            case BOTTLE_OPENED:
                resetZ();
                resetXY();
                sendCommand(DISPOSE);
                break;
            default:
                break;
        }
        enabled = DEFAULT;           
    }
}

/* [] END OF FILE */
