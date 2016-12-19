#ifndef _STATUS_H
#define _STATUS_H
#include "project.h"

static uint8 status;

enum SPI_protocol {
    
    // Command from DK8k to master-PSoC
    GET_STATUS      = 0x00,
    
    // Command from master-PSoC to slave-PSoC
    DISPOSE         = 0x01,
    
    // Command from DK8k to master-PSoC/master-PSoC to slave-PSoC
    OPEN_BOTTLE     = 0x05,
    
    // Feedback messages from master-PSoC to DK8k
    VALID_TYPE      = 0x10,
    READY_TO_DRINK  = 0x11,
    INVALID_TYPE    = 0x20,
    NO_BOTTLE       = 0x21,
    DEFAULT         = 0x30,
    WRONG_COMMAND   = 0x31,
    WRONG_DEVICE    = 0x32,
    IN_PROCESS      = 0x33,
    
    // Feedback messages from master-PSoC to slave-PSoC
    BOTTLE_OPENED   = 0x40,
    CORK_DISPOSED   = 0x41,
};

enum bottleInfo {
    MIN_WIDTH       = 2,        // Random value
    MAX_WIDTH       = 5,        // Random value
    HEIGHT          = 10,       // Random value
};

enum motorSensorInfo {
    LOW             = 1200,     // Output voltage from sensor when not detecting an object
    STEPS           = 25,       // 10 steps. Is adjusted to the PWM-signal
};

enum openingMechanism {
    STEPS_X         = 200,      // Random value
    STEPS_Y         = 200,      // Random value
    UNDER_TOP       = 200,      // Random value
    ABOVE_TOP       = 200,      // Random value
};

enum axes {
    X               = 0,
    Y               = 1,
    Z               = 2,
};

enum operation {
    MOTOR_RUN       = 0,
    MOTOR_STOP      = 1,
};

enum dir {
    FW              = 0,
    BW              = 1,
};

// Update status of master-PSoC/message to be sent to DK8k
void updateStatus(uint8 stat)
{
    status = stat;
    SPIS_1_ClearTxBuffer();
    SPIS_1_WriteTxData(status);
}

// Update status of master-PSoC/message to be sent to slave-PSoC
void sendCommand(uint8 cmd)
{
    SPIM_1_ClearTxBuffer();
    SPIM_1_WriteTxData(cmd);
}

#endif // _STATUS_H
