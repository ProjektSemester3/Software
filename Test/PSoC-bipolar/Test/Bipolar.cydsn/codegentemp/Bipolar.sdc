# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\Bettefanden\Documents\IHA\Semester 3\Semesterprojekt 3\Software\Test\PSoC-bipolar\Test\Bipolar.cydsn\Bipolar.cyprj
# Date: Thu, 01 Dec 2016 20:27:28 GMT
#set_units -time ns
create_clock -name {ADC_SAR_Seq_IntClock(routed)} -period 833.33333333333326 -waveform {0 416.666666666667} [list [get_pins {ClockBlock/dclk_0}]]
create_clock -name {CyILO} -period 1000000 -waveform {0 500000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyIMO} -period 333.33333333333331 -waveform {0 166.666666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyMASTER_CLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]
create_generated_clock -name {ADC_SAR_Seq_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 21 41} -nominal_period 833.33333333333326 [list [get_pins {ClockBlock/dclk_glb_0}]]
create_generated_clock -name {UART_1_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 27 53} -nominal_period 1083.3333333333333 [list [get_pins {ClockBlock/dclk_glb_1}]]
create_generated_clock -name {Clock_1} -source [get_pins {ClockBlock/clk_sync}] -edges {1 121 241} [list [get_pins {ClockBlock/dclk_glb_2}]]


# Component constraints for C:\Users\Bettefanden\Documents\IHA\Semester 3\Semesterprojekt 3\Software\Test\PSoC-bipolar\Test\Bipolar.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\Bettefanden\Documents\IHA\Semester 3\Semesterprojekt 3\Software\Test\PSoC-bipolar\Test\Bipolar.cydsn\Bipolar.cyprj
# Date: Thu, 01 Dec 2016 20:27:14 GMT