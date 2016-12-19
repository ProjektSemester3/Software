#ifndef _SWITCHES_H
#define _SWITCHES_H
#include "project.h"
#include "Status.h"

static uint8 xHomeStop = 0;
static uint8 xEndStop = 0;
static uint8 yHomeStop = 0;
static uint8 yEndStop = 0;
static uint8 zHomeStop = 0;
static uint8 zEndStop = 0;

CY_ISR(isr_x_home)
{
    xHomeStop = 1;
    Pin_int_x_home_ClearInterrupt();
}

CY_ISR(isr_x_end)
{
    xEndStop = 1;
    Pin_int_x_end_ClearInterrupt();
}

CY_ISR(isr_y_home)
{
    yHomeStop = 1;
    Pin_int_y_home_ClearInterrupt();
}

CY_ISR(isr_y_end)
{
    yEndStop = 1;
    Pin_int_y_end_ClearInterrupt();
}

CY_ISR(isr_z_home)
{
    zHomeStop = 1;
    Pin_int_z_home_ClearInterrupt();
}

CY_ISR(isr_z_end)
{
    zEndStop = 1;
    Pin_int_z_end_ClearInterrupt();
}

#endif // _SWITCHES_H
