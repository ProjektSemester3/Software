#include "project.h"
#include "motors.h"
#include <stdio.h>

uint8 enabled = DEFAULT;
uint8 screwDirection;
uint8 openDirection;

/*
CY_ISR(isr_1)
{
    uint16 rxvalue;
	uint8 cmd;
	uint8 addr;
    
    rxvalue = SPIS_1_ReadRxData(); // This also clears Rx Status Register
    SPIS_1_ClearRxBuffer();
    
    * Protocol - Write 8-bit: 
	 * |CMD|  ADDR  |    DATA    |
	 *  1 1 1      8 7          0
	 *	5 4 3
	 *

	* Protocol - Read 16-bit: 
	 * |CMD|  ADDR  |  Not Used  |       |           DATA          |
	 *  1 1 1      8 7          0         1                       0
	 *	5 4 3                             5
	 *
    
    cmd = (rxvalue >> 14) & 0x3;  // cmd = rdvalue[15:14]
	addr = (rxvalue >> 8) & 0x3f; // addr = rdvalue[13:8]
    
    switch (addr) {
		case 0x01:
			switch(cmd) {
                
                // Write status of bottle to DK8k
				case GET_STATUS:
					updateStatus(status);
                    
                    if(status != IN_PROCESS || status != VALID_TYPE) {
                        status = DEFAULT;
                    }
					break;
                
                // Registrate bottle
				case LOCATE_BOTTLE:
                    updateStatus(IN_PROCESS);
                    
                    // Validate thickness of bottle neck
                    enabled = cmd;
					break;
                
                // Open bottle
                case OPEN_BOTTLE:
                    updateStatus(IN_PROCESS);
                    
                    // Open bottle
                    enabled = cmd;
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
*/

CY_ISR(isr_RxD)
{
    enabled = LOCATE_BOTTLE;
    /*
    Direction_Z_Write(FW);
    Enable_Z_Write(MOTOR_RUN);*/
}

int main()
{
    updateStatus(DEFAULT);
    CyGlobalIntEnable;
    /*
    SPIS_1_Start();
	SPIS_1_EnableRxInt();
    //isr_1_StartEx(isr_1);
	SPIS_1_ClearFIFO();
	SPIS_1_ClearTxBuffer();*/
    
    UART_1_Start();
    isr_RxD_StartEx(isr_RxD);
    /*
    isr_x_home_StartEx(isr_x_home);
    isr_y_home_StartEx(isr_y_home);
    isr_xy_end_StartEx(isr_xy_end);
    isr_z_home_StartEx(isr_z_home);
    isr_z_end_StartEx(isr_z_end);
    isr_cork_StartEx(isr_cork);
    */
    PWM_X_Start();
    PWM_Y_Start();
    PWM_Z_Start();
    //PWM_S_Start();
    
    for(;;)
    {
        switch(enabled) {
            case LOCATE_BOTTLE:
                updateStatus(IN_PROCESS);
                
                if(locateX() || locateY()) {
                    reset();
                    enabled = DEFAULT;
                    break;
                }
                
                if(confirmHeight()) {
                    reset();
                    enabled = DEFAULT;
                    break;
                }
                break;
            default:
                break;
        }
        enabled = DEFAULT;           
    }
}

/* [] END OF FILE */
