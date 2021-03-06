# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\Bettefanden\Documents\IHA\Semester 3\Semesterprojekt 3\Software\Udkast2\PSoCMaster\StepperMotor.cydsn\StepperMotor.cyprj
# Date: Fri, 09 Dec 2016 18:45:53 GMT
#set_units -time ns
create_clock -name {ADC_SAR_Seq_IntClock(routed)} -period 833.33333333333326 -waveform {0 416.666666666667} [list [get_pins {ClockBlock/dclk_1}]]
create_clock -name {CyILO} -period 1000000 -waveform {0 500000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyIMO} -period 333.33333333333331 -waveform {0 166.666666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyMASTER_CLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]
create_generated_clock -name {SPIS_1_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 13 25} [list [get_pins {ClockBlock/dclk_glb_0}]]
create_generated_clock -name {ADC_SAR_Seq_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 21 41} -nominal_period 833.33333333333326 [list [get_pins {ClockBlock/dclk_glb_1}]]
create_generated_clock -name {Clock_2} -source [get_pins {ClockBlock/clk_sync}] -edges {1 121 241} [list [get_pins {ClockBlock/dclk_glb_2}]]
create_generated_clock -name {Clock_1} -source [get_pins {ClockBlock/clk_sync}] -edges {1 121 241} [list [get_pins {ClockBlock/dclk_glb_3}]]
create_generated_clock -name {Clock_3} -source [get_pins {ClockBlock/clk_sync}] -edges {1 121 241} [list [get_pins {ClockBlock/dclk_glb_4}]]
create_generated_clock -name {Clock_5} -source [get_pins {ClockBlock/clk_sync}] -edges {1 121 241} [list [get_pins {ClockBlock/dclk_glb_5}]]
create_generated_clock -name {Clock_4} -source [get_pins {ClockBlock/clk_sync}] -edges {1 121 241} [list [get_pins {ClockBlock/dclk_glb_6}]]


# Component constraints for C:\Users\Bettefanden\Documents\IHA\Semester 3\Semesterprojekt 3\Software\Udkast2\PSoCMaster\StepperMotor.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\Bettefanden\Documents\IHA\Semester 3\Semesterprojekt 3\Software\Udkast2\PSoCMaster\StepperMotor.cydsn\StepperMotor.cyprj
# Date: Fri, 09 Dec 2016 18:45:29 GMT
