#ifndef _STATUS_H
#define _STATUS_H
#include "project.h"

static uint8 status;

enum SPI_protocol {
    
    // Commands from DK8k to PSoC
    GET_STATUS      = 0x00,
    LOCATE_BOTTLE   = 0x01,
    OPEN_BOTTLE     = 0x05,
    
    // Feedback messages from PSoC-master to DK8k
    VALID_TYPE      = 0x10,
    READY_TO_DRINK  = 0x11,
    INVALID_TYPE    = 0x20,
    NO_BOTTLE       = 0x21,
    DEFAULT         = 0x30,
    WRONG_COMMAND   = 0x31,
    WRONG_DEVICE    = 0x32,
    IN_PROCESS      = 0x33,
};

enum bottleInfo {
    MIN_WIDTH       = 2,        // Random value
    MAX_WIDTH       = 5,        // Random value
    HEIGHT          = 10,       // Random value
};

enum motorSensorInfo {
    LOW             = 1200,     // Output voltage from sensor when not detecting an object
    STEPS           = 25,       // 10 steps
};

enum openingMechanism {
    STEPS_X         = 200,
    STEPS_Y         = 200,
    STEPS_Z         = 200,
    STEPS_CORK      = 200,
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
    /*UART_1_ClearTxBuffer();
    UART_1_WriteTxData(status);*/
}

#endif // _STATUS_H
