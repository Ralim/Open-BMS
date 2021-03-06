EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:ISL94202
LIBS:openbmsriser
LIBS:mechanical
LIBS:OpenBMSFrontEnd-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 2
Title "Open BMS Front End"
Date "2017-06-17"
Rev "1"
Comp "Ralim TEk"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 "By Ben V. Browm"
$EndDescr
$Comp
L ISL94202 U101
U 1 1 59170B53
P 5400 3700
F 0 "U101" H 5400 3700 50  0000 C CNN
F 1 "ISL94202" H 5400 4050 50  0000 C CNN
F 2 "Housings_DFN_QFN:UQFN-48-1EP_6x6mm_Pitch0.4mm" H 5400 3850 50  0001 C CNN
F 3 "DOCUMENTATION" H 5400 3950 50  0001 C CNN
F 4 "968-ISL94202IRTZ-T7A" H 5400 3700 60  0001 C CNN "bom_partno"
	1    5400 3700
	1    0    0    -1  
$EndComp
$Sheet
S 3200 3150 1100 2050
U 59170C93
F0 "Cell Frontend" 60
F1 "CellFrontend.sch" 60
F2 "C0" I L 3200 4800 60 
F3 "C1" I L 3200 4700 60 
F4 "C2" I L 3200 4600 60 
F5 "C3" I L 3200 4500 60 
F6 "C4" I L 3200 4400 60 
F7 "VC8" I R 4300 3200 60 
F8 "CB8" I R 4300 3300 60 
F9 "VC7" I R 4300 3400 60 
F10 "CB7" I R 4300 3500 60 
F11 "VC6" I R 4300 3600 60 
F12 "VC3" I R 4300 4200 60 
F13 "CB3" I R 4300 4300 60 
F14 "VC2" I R 4300 4750 60 
F15 "CB2" I R 4300 4850 60 
F16 "VC1" I R 4300 4950 60 
F17 "CB1" I R 4300 5050 60 
F18 "VC0" I R 4300 5150 60 
F19 "CB6" I R 4300 3700 60 
F20 "VC5" I R 4300 3800 60 
F21 "CB5" I R 4300 3900 60 
F22 "VC4" I R 4300 4000 60 
F23 "CB4" I R 4300 4100 60 
F24 "C6" I L 3200 4200 60 
F25 "C7" I L 3200 4100 60 
F26 "C8" I L 3200 4000 60 
F27 "C5" I L 3200 4300 60 
$EndSheet
$Comp
L GND #PWR01
U 1 1 591894B2
P 6500 4400
F 0 "#PWR01" H 6500 4150 50  0001 C CNN
F 1 "GND" H 6500 4250 50  0000 C CNN
F 2 "" H 6500 4400 50  0001 C CNN
F 3 "" H 6500 4400 50  0001 C CNN
	1    6500 4400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 5918954B
P 5400 4750
F 0 "#PWR02" H 5400 4500 50  0001 C CNN
F 1 "GND" H 5400 4600 50  0000 C CNN
F 2 "" H 5400 4750 50  0001 C CNN
F 3 "" H 5400 4750 50  0001 C CNN
	1    5400 4750
	1    0    0    -1  
$EndComp
$Comp
L C C102
U 1 1 5918994C
P 5500 5350
F 0 "C102" H 5525 5450 50  0000 L CNN
F 1 "100n" H 5525 5250 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 5538 5200 50  0001 C CNN
F 3 "" H 5500 5350 50  0001 C CNN
F 4 "710-885012206071" H 5500 5350 60  0001 C CNN "bom_partno"
	1    5500 5350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 59189BFD
P 5500 5500
F 0 "#PWR03" H 5500 5250 50  0001 C CNN
F 1 "GND" H 5500 5350 50  0000 C CNN
F 2 "" H 5500 5500 50  0001 C CNN
F 3 "" H 5500 5500 50  0001 C CNN
	1    5500 5500
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 5918A19D
P 6000 4750
F 0 "#PWR04" H 6000 4500 50  0001 C CNN
F 1 "GND" H 6000 4600 50  0000 C CNN
F 2 "" H 6000 4750 50  0001 C CNN
F 3 "" H 6000 4750 50  0001 C CNN
	1    6000 4750
	1    0    0    -1  
$EndComp
Text Label 6750 4150 0    60   ~ 0
SDA
Text Label 6750 4300 0    60   ~ 0
SCL
$Comp
L GND #PWR05
U 1 1 5918C1EC
P 7050 4400
F 0 "#PWR05" H 7050 4150 50  0001 C CNN
F 1 "GND" H 7050 4250 50  0000 C CNN
F 2 "" H 7050 4400 50  0001 C CNN
F 3 "" H 7050 4400 50  0001 C CNN
	1    7050 4400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR06
U 1 1 5918C281
P 7150 4400
F 0 "#PWR06" H 7150 4150 50  0001 C CNN
F 1 "GND" H 7150 4250 50  0000 C CNN
F 2 "" H 7150 4400 50  0001 C CNN
F 3 "" H 7150 4400 50  0001 C CNN
	1    7150 4400
	1    0    0    -1  
$EndComp
$Comp
L R R107
U 1 1 5918F88C
P 3900 2700
F 0 "R107" V 3980 2700 50  0000 C CNN
F 1 "100" V 3900 2700 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 3830 2700 50  0001 C CNN
F 3 "" H 3900 2700 50  0001 C CNN
F 4 "660-RK73H1JTTD1000F" H 3900 2700 60  0001 C CNN "bom_partno"
	1    3900 2700
	0    1    1    0   
$EndComp
$Comp
L GND #PWR07
U 1 1 59191316
P 2250 1925
F 0 "#PWR07" H 2250 1675 50  0001 C CNN
F 1 "GND" H 2250 1775 50  0000 C CNN
F 2 "" H 2250 1925 50  0001 C CNN
F 3 "" H 2250 1925 50  0001 C CNN
	1    2250 1925
	1    0    0    -1  
$EndComp
$Comp
L R R102
U 1 1 59191EC2
P 2850 1500
F 0 "R102" V 2930 1500 50  0000 C CNN
F 1 "0.002" V 2850 1500 50  0000 C CNN
F 2 "Resistors_SMD:R_2512" V 2780 1500 50  0001 C CNN
F 3 "" H 2850 1500 50  0001 C CNN
	1    2850 1500
	0    -1   -1   0   
$EndComp
$Comp
L FDMS8050 Q101
U 1 1 591940C4
P 3650 1700
F 0 "Q101" H 3450 2000 50  0000 L CNN
F 1 "FDMS8050" H 3450 1450 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:TDSON-8-1" H 3650 1356 50  0001 C CIN
F 3 "" V 3650 1700 50  0001 L CNN
F 4 "726-BSC882N03LSG" H 3650 1700 60  0001 C CNN "bom_partno"
	1    3650 1700
	1    0    0    -1  
$EndComp
$Comp
L R R101
U 1 1 59195560
P 2700 2050
F 0 "R101" V 2780 2050 50  0000 C CNN
F 1 "100" V 2700 2050 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 2630 2050 50  0001 C CNN
F 3 "" H 2700 2050 50  0001 C CNN
F 4 "660-RK73H1JTTD1000F" H 2700 2050 60  0001 C CNN "bom_partno"
	1    2700 2050
	1    0    0    -1  
$EndComp
$Comp
L R R104
U 1 1 59195613
P 3000 2050
F 0 "R104" V 3080 2050 50  0000 C CNN
F 1 "100" V 3000 2050 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 2930 2050 50  0001 C CNN
F 3 "" H 3000 2050 50  0001 C CNN
F 4 "660-RK73H1JTTD1000F" H 3000 2050 60  0001 C CNN "bom_partno"
	1    3000 2050
	-1   0    0    1   
$EndComp
$Comp
L C C101
U 1 1 59196A2F
P 2850 2300
F 0 "C101" H 2875 2400 50  0000 L CNN
F 1 "4.7n" H 2875 2200 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 2888 2150 50  0001 C CNN
F 3 "" H 2850 2300 50  0001 C CNN
F 4 "710-885012206087" H 2850 2300 60  0001 C CNN "bom_partno"
	1    2850 2300
	0    1    1    0   
$EndComp
$Comp
L FDMS8050 Q102
U 1 1 5919A45C
P 4450 1700
F 0 "Q102" H 4250 2000 50  0000 L CNN
F 1 "FDMS8050" H 4250 1450 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:TDSON-8-1" H 4450 1356 50  0001 C CIN
F 3 "" V 4450 1700 50  0001 L CNN
F 4 "726-BSC882N03LSG" H 4450 1700 60  0001 C CNN "bom_partno"
	1    4450 1700
	-1   0    0    -1  
$EndComp
$Comp
L R R105
U 1 1 5919AF49
P 3150 1650
F 0 "R105" V 3230 1650 50  0000 C CNN
F 1 "1M" V 3150 1650 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 3080 1650 50  0001 C CNN
F 3 "" H 3150 1650 50  0001 C CNN
F 4 "71-CRCW0603-1.0M-E3" H 3150 1650 60  0001 C CNN "bom_partno"
	1    3150 1650
	-1   0    0    1   
$EndComp
$Comp
L R R106
U 1 1 5919BB30
P 3150 1950
F 0 "R106" V 3230 1950 50  0000 C CNN
F 1 "100" V 3150 1950 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 3080 1950 50  0001 C CNN
F 3 "" H 3150 1950 50  0001 C CNN
F 4 "660-RK73H1JTTD1000F" H 3150 1950 60  0001 C CNN "bom_partno"
	1    3150 1950
	-1   0    0    1   
$EndComp
$Comp
L R R108
U 1 1 5919D122
P 4900 1650
F 0 "R108" V 4980 1650 50  0000 C CNN
F 1 "1M" V 4900 1650 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 4830 1650 50  0001 C CNN
F 3 "" H 4900 1650 50  0001 C CNN
F 4 "71-CRCW0603-1.0M-E3" H 4900 1650 60  0001 C CNN "bom_partno"
	1    4900 1650
	-1   0    0    1   
$EndComp
$Comp
L R R109
U 1 1 5919D228
P 4900 1950
F 0 "R109" V 4980 1950 50  0000 C CNN
F 1 "100" V 4900 1950 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 4830 1950 50  0001 C CNN
F 3 "" H 4900 1950 50  0001 C CNN
F 4 "660-RK73H1JTTD1000F" H 4900 1950 60  0001 C CNN "bom_partno"
	1    4900 1950
	-1   0    0    1   
$EndComp
$Comp
L R R110
U 1 1 5919FBEE
P 5900 1850
F 0 "R110" V 5980 1850 50  0000 C CNN
F 1 "1k" V 5900 1850 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 5830 1850 50  0001 C CNN
F 3 "" H 5900 1850 50  0001 C CNN
F 4 "71-CRCW0603-1.0K-E3" H 5900 1850 60  0001 C CNN "bom_partno"
	1    5900 1850
	-1   0    0    1   
$EndComp
$Comp
L C C106
U 1 1 591A1D4A
P 5800 2300
F 0 "C106" H 5825 2400 50  0000 L CNN
F 1 "4.7n" H 5825 2200 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 5838 2150 50  0001 C CNN
F 3 "" H 5800 2300 50  0001 C CNN
F 4 "710-885012206087" H 5800 2300 60  0001 C CNN "bom_partno"
	1    5800 2300
	-1   0    0    1   
$EndComp
$Comp
L C C105
U 1 1 591A1FE3
P 5600 2500
F 0 "C105" H 5625 2600 50  0000 L CNN
F 1 "4.7n" H 5625 2400 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 5638 2350 50  0001 C CNN
F 3 "" H 5600 2500 50  0001 C CNN
F 4 "710-885012206087" H 5600 2500 60  0001 C CNN "bom_partno"
	1    5600 2500
	-1   0    0    1   
$EndComp
$Comp
L Jumper_NO_Small JP101
U 1 1 591A9C77
P 1875 5125
F 0 "JP101" H 1875 5205 50  0000 C CNN
F 1 "." H 1885 5065 50  0000 C CNN
F 2 "conn-test:JUMPER-SOLDER-SMD" H 1875 5125 50  0001 C CNN
F 3 "" H 1875 5125 50  0001 C CNN
	1    1875 5125
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR08
U 1 1 591B86DD
P 6500 1925
F 0 "#PWR08" H 6500 1675 50  0001 C CNN
F 1 "GND" H 6500 1775 50  0000 C CNN
F 2 "" H 6500 1925 50  0001 C CNN
F 3 "" H 6500 1925 50  0001 C CNN
	1    6500 1925
	1    0    0    -1  
$EndComp
Text Notes 6800 2800 2    60   ~ 0
VREF=1.8V\nRGO=2.5V\n
$Comp
L GND #PWR09
U 1 1 591BDC3F
P 7350 4400
F 0 "#PWR09" H 7350 4150 50  0001 C CNN
F 1 "GND" H 7350 4250 50  0000 C CNN
F 2 "" H 7350 4400 50  0001 C CNN
F 3 "" H 7350 4400 50  0001 C CNN
	1    7350 4400
	1    0    0    -1  
$EndComp
$Comp
L R R113
U 1 1 591C0A45
P 6600 5200
F 0 "R113" V 6680 5200 50  0000 C CNN
F 1 "22k" V 6600 5200 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 6530 5200 50  0001 C CNN
F 3 "" H 6600 5200 50  0001 C CNN
F 4 "652-CR0603FX-2202ELF" H 6600 5200 60  0001 C CNN "bom_partno"
	1    6600 5200
	-1   0    0    1   
$EndComp
$Comp
L R R114
U 1 1 591C0B7A
P 6950 5200
F 0 "R114" V 7030 5200 50  0000 C CNN
F 1 "22k" V 6950 5200 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 6880 5200 50  0001 C CNN
F 3 "" H 6950 5200 50  0001 C CNN
F 4 "652-CR0603FX-2202ELF" H 6950 5200 60  0001 C CNN "bom_partno"
	1    6950 5200
	-1   0    0    1   
$EndComp
$Comp
L Thermistor TH101
U 1 1 591C1467
P 6600 5700
F 0 "TH101" V 6700 5750 50  0000 C CNN
F 1 "Thermistor" V 6500 5700 50  0000 C BNN
F 2 "Resistors_SMD:R_0603" H 6600 5700 50  0001 C CNN
F 3 "" H 6600 5700 50  0001 C CNN
F 4 "NCP18XH103J03RB" H 6600 5700 60  0001 C CNN "bom_partno"
	1    6600 5700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR010
U 1 1 591C20D1
P 6750 6050
F 0 "#PWR010" H 6750 5800 50  0001 C CNN
F 1 "GND" H 6750 5900 50  0000 C CNN
F 2 "" H 6750 6050 50  0001 C CNN
F 3 "" H 6750 6050 50  0001 C CNN
	1    6750 6050
	1    0    0    -1  
$EndComp
$Comp
L R R115
U 1 1 591C2799
P 7200 5700
F 0 "R115" V 7280 5700 50  0000 C CNN
F 1 "10k" V 7200 5700 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 7130 5700 50  0001 C CNN
F 3 "" H 7200 5700 50  0001 C CNN
F 4 "71-CRCW0603-10K-E3" H 7200 5700 60  0001 C CNN "bom_partno"
	1    7200 5700
	-1   0    0    1   
$EndComp
$Comp
L R R112
U 1 1 591C28D3
P 6350 5700
F 0 "R112" V 6430 5700 50  0000 C CNN
F 1 "10k" V 6350 5700 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 6280 5700 50  0001 C CNN
F 3 "" H 6350 5700 50  0001 C CNN
F 4 "71-CRCW0603-10K-E3" H 6350 5700 60  0001 C CNN "bom_partno"
	1    6350 5700
	-1   0    0    1   
$EndComp
Text Label 6600 3200 0    60   ~ 0
RGO
Text Label 6600 3700 0    60   ~ 0
~INT
$Comp
L C C107
U 1 1 591852C0
P 7800 4250
F 0 "C107" H 7825 4350 50  0000 L CNN
F 1 "100n" H 7825 4150 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 7838 4100 50  0001 C CNN
F 3 "" H 7800 4250 50  0001 C CNN
F 4 "710-885012206071" H 7800 4250 60  0001 C CNN "bom_partno"
	1    7800 4250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR011
U 1 1 59185407
P 7800 4400
F 0 "#PWR011" H 7800 4150 50  0001 C CNN
F 1 "GND" H 7800 4250 50  0000 C CNN
F 2 "" H 7800 4400 50  0001 C CNN
F 3 "" H 7800 4400 50  0001 C CNN
	1    7800 4400
	1    0    0    -1  
$EndComp
$Comp
L C C119
U 1 1 5918D1C3
P 5300 5350
F 0 "C119" H 5325 5450 50  0000 L CNN
F 1 "1u" H 5325 5250 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 5338 5200 50  0001 C CNN
F 3 "" H 5300 5350 50  0001 C CNN
F 4 "710-885012106022" H 5300 5350 60  0001 C CNN "bom_partno"
	1    5300 5350
	1    0    0    -1  
$EndComp
$Comp
L C C120
U 1 1 5918D69C
P 7600 4250
F 0 "C120" H 7625 4350 50  0000 L CNN
F 1 "1u" H 7625 4150 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 7638 4100 50  0001 C CNN
F 3 "" H 7600 4250 50  0001 C CNN
F 4 "710-885012106022" H 7600 4250 60  0001 C CNN "bom_partno"
	1    7600 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 4850 5000 4750
Wire Wire Line
	5100 4950 5100 4750
Wire Wire Line
	5200 5050 5200 4750
Wire Wire Line
	5300 5150 5300 4750
Wire Wire Line
	4900 4750 4300 4750
Wire Wire Line
	5500 5200 5500 4750
Wire Wire Line
	6750 4150 6600 4150
Wire Wire Line
	6600 4100 6600 4200
Connection ~ 6600 4150
Wire Wire Line
	6750 4300 6600 4300
Wire Wire Line
	6600 4000 7050 4000
Wire Wire Line
	7050 4000 7050 4400
Wire Wire Line
	6600 3900 7150 3900
Wire Wire Line
	7150 3900 7150 4400
Wire Wire Line
	2700 1500 2700 1900
Wire Wire Line
	2250 1600 2700 1600
Connection ~ 2700 1600
Wire Wire Line
	3000 1500 3000 1900
Connection ~ 3000 1650
Connection ~ 2700 1650
Wire Wire Line
	5000 2700 5000 2500
Wire Wire Line
	5000 2500 2700 2500
Connection ~ 2700 2300
Wire Wire Line
	5100 2700 5100 2450
Wire Wire Line
	5100 2450 3000 2450
Connection ~ 3000 2300
Wire Wire Line
	4150 1800 3950 1800
Wire Wire Line
	4150 1700 3950 1700
Wire Wire Line
	4150 1600 3950 1600
Wire Wire Line
	3950 1500 4150 1500
Connection ~ 4050 1600
Connection ~ 4050 1500
Connection ~ 4050 1700
Connection ~ 4050 1800
Wire Wire Line
	3000 1500 3350 1500
Connection ~ 3150 1500
Wire Wire Line
	3350 1700 3000 1700
Connection ~ 3000 1700
Wire Wire Line
	3350 1600 3000 1600
Connection ~ 3000 1600
Wire Wire Line
	3350 1800 3150 1800
Wire Wire Line
	5200 2700 5200 2400
Wire Wire Line
	5200 2400 3150 2400
Wire Wire Line
	3150 2400 3150 2100
Wire Wire Line
	4900 1800 4750 1800
Wire Wire Line
	4750 1500 5100 1500
Wire Wire Line
	4750 1600 6500 1600
Connection ~ 4900 1500
Wire Wire Line
	5100 1700 4750 1700
Wire Wire Line
	5100 1500 5100 1700
Connection ~ 5100 1600
Wire Wire Line
	5500 2700 5500 2100
Wire Wire Line
	5500 2100 4900 2100
Wire Wire Line
	5400 2150 5400 2700
Wire Wire Line
	5900 2000 5900 2700
Wire Wire Line
	5900 1700 5900 1600
Connection ~ 5900 1600
Wire Wire Line
	5800 2150 5400 2150
Wire Wire Line
	5800 2450 5800 2700
Wire Wire Line
	5600 2350 5700 2350
Wire Wire Line
	5700 2350 5700 2700
Wire Wire Line
	5600 2650 5600 2700
Connection ~ 4900 1800
Wire Wire Line
	7350 4100 7350 3500
Wire Wire Line
	7350 3500 6600 3500
Wire Wire Line
	6600 3200 8100 3200
Wire Wire Line
	5800 5050 6950 5050
Wire Wire Line
	5800 5050 5800 4750
Connection ~ 6600 5050
Connection ~ 6950 5400
Wire Wire Line
	5700 4750 5700 5150
Wire Wire Line
	5700 5150 6400 5150
Wire Wire Line
	6400 5150 6400 5400
Wire Wire Line
	6400 5400 7200 5400
Wire Wire Line
	6600 5500 6600 5350
Wire Wire Line
	6600 5450 6250 5450
Wire Wire Line
	6250 5450 6250 5200
Wire Wire Line
	6250 5200 5600 5200
Wire Wire Line
	5600 5200 5600 4750
Connection ~ 6600 5450
Wire Wire Line
	6350 6050 7200 6050
Wire Wire Line
	6600 5900 6600 6050
Connection ~ 6750 6050
Wire Wire Line
	6350 5550 6350 5450
Connection ~ 6350 5450
Wire Wire Line
	6350 5850 6350 6050
Connection ~ 6600 6050
Wire Wire Line
	7200 6050 7200 5850
Wire Wire Line
	7200 5400 7200 5550
Connection ~ 3250 1800
Connection ~ 4800 1800
Wire Wire Line
	7800 3200 7800 4100
Connection ~ 7700 3200
Wire Wire Line
	5300 5200 5500 5200
Wire Wire Line
	5300 5500 5500 5500
Wire Wire Line
	7800 4100 7600 4100
Wire Wire Line
	7600 4400 7800 4400
Connection ~ 4300 5150
Connection ~ 4300 5050
Connection ~ 4300 4950
Connection ~ 4300 4850
Connection ~ 4300 4300
Connection ~ 4300 4200
Connection ~ 4300 3600
Connection ~ 4300 3500
Connection ~ 4300 3400
Connection ~ 4300 3300
Connection ~ 4300 3200
Wire Wire Line
	4300 4850 5000 4850
Wire Wire Line
	5100 4950 4300 4950
Wire Wire Line
	4300 5050 5200 5050
Wire Wire Line
	5300 5150 4300 5150
$Comp
L CONN_02X05 J1
U 1 1 5945D9D3
P 1725 4325
F 0 "J1" H 1725 4625 50  0000 C CNN
F 1 "CONN_02X05" H 1725 4025 50  0000 C CNN
F 2 "Connectors:IDC_Header_Straight_10pins" H 1725 3125 50  0001 C CNN
F 3 "" H 1725 3125 50  0001 C CNN
	1    1725 4325
	-1   0    0    1   
$EndComp
Text Label 3200 4000 2    60   ~ 0
C8
Text Label 3200 4100 2    60   ~ 0
C7
Text Label 3200 4200 2    60   ~ 0
C6
Text Label 3200 4300 2    60   ~ 0
C5
Text Label 3200 4400 2    60   ~ 0
C4
Text Label 3200 4500 2    60   ~ 0
C3
Text Label 3200 4600 2    60   ~ 0
C2
Text Label 3200 4700 2    60   ~ 0
C1
Text Label 3200 4800 2    60   ~ 0
C0
Text Label 1475 4125 2    60   ~ 0
C8
Text Label 1475 4225 2    60   ~ 0
C6
Text Label 1475 4325 2    60   ~ 0
C4
Text Label 1475 4425 2    60   ~ 0
C2
Text Label 1475 4525 2    60   ~ 0
C0
Text Label 1975 4125 0    60   ~ 0
C7
Text Label 1975 4225 0    60   ~ 0
C5
Text Label 1975 4325 0    60   ~ 0
C3
Text Label 1975 4425 0    60   ~ 0
C1
Text Label 1975 4525 0    60   ~ 0
RemoteTemp
Text Label 3750 2700 2    60   ~ 0
C8
Wire Wire Line
	4900 2700 4050 2700
Connection ~ 4300 4100
Connection ~ 4300 4000
Connection ~ 4300 3900
Connection ~ 4300 3800
Connection ~ 4300 3700
Connection ~ 4300 4750
Text Label 7200 5400 0    60   ~ 0
RemoteTemp
Wire Wire Line
	6950 5350 6950 5400
Text Notes 6825 5550 3    60   ~ 0
FET Temp
Wire Wire Line
	4050 2325 5400 2325
Wire Wire Line
	5300 2325 5300 2700
Text Notes 2575 5850 2    60   ~ 0
<=7 Cells\n\n<=6 Cells\n\n<=5 Cells\n\n<=4 Cells\n\n==3 Cells
Text Label 1775 5125 2    60   ~ 0
C5
Text Label 1975 5125 0    60   ~ 0
C4
$Comp
L Jumper_NO_Small JP1
U 1 1 59471FC3
P 1875 5300
F 0 "JP1" H 1875 5380 50  0000 C CNN
F 1 "." H 1885 5240 50  0000 C CNN
F 2 "conn-test:JUMPER-SOLDER-SMD" H 1875 5300 50  0001 C CNN
F 3 "" H 1875 5300 50  0001 C CNN
	1    1875 5300
	1    0    0    -1  
$EndComp
Text Label 1775 5300 2    60   ~ 0
C4
Text Label 1975 5300 0    60   ~ 0
C3
$Comp
L Jumper_NO_Small JP2
U 1 1 59472311
P 1875 5475
F 0 "JP2" H 1875 5555 50  0000 C CNN
F 1 "." H 1885 5415 50  0000 C CNN
F 2 "conn-test:JUMPER-SOLDER-SMD" H 1875 5475 50  0001 C CNN
F 3 "" H 1875 5475 50  0001 C CNN
	1    1875 5475
	1    0    0    -1  
$EndComp
Text Label 1775 5475 2    60   ~ 0
C6
Text Label 1975 5475 0    60   ~ 0
C5
$Comp
L Jumper_NO_Small JP3
U 1 1 594728B5
P 1875 5650
F 0 "JP3" H 1875 5730 50  0000 C CNN
F 1 "." H 1885 5590 50  0000 C CNN
F 2 "conn-test:JUMPER-SOLDER-SMD" H 1875 5650 50  0001 C CNN
F 3 "" H 1875 5650 50  0001 C CNN
	1    1875 5650
	1    0    0    -1  
$EndComp
Text Label 1775 5650 2    60   ~ 0
C3
Text Label 1975 5650 0    60   ~ 0
C2
$Comp
L Jumper_NO_Small JP4
U 1 1 59472C0D
P 1875 5825
F 0 "JP4" H 1875 5905 50  0000 C CNN
F 1 "." H 1885 5765 50  0000 C CNN
F 2 "conn-test:JUMPER-SOLDER-SMD" H 1875 5825 50  0001 C CNN
F 3 "" H 1875 5825 50  0001 C CNN
	1    1875 5825
	1    0    0    -1  
$EndComp
Text Label 1775 5825 2    60   ~ 0
C7
Text Label 1975 5825 0    60   ~ 0
C6
Text Notes 1275 4725 3    60   ~ 0
Short these jumpers when cell count < 8
Text Notes 7825 6375 2    60   ~ 0
R115 =5K when no remote temp
$Comp
L OpenBMSRiser J2
U 1 1 5947A060
P 9325 3575
F 0 "J2" H 9325 3575 60  0000 C CNN
F 1 "OpenBMSRiser" H 9325 3475 60  0000 C CNN
F 2 "BMSFootprints:OpenBMSRiser" H 9325 3575 60  0001 C CNN
F 3 "" H 9325 3575 60  0001 C CNN
	1    9325 3575
	1    0    0    -1  
$EndComp
Text Label 8725 4425 2    60   ~ 0
RGO
Text Label 6600 3400 0    60   ~ 0
SD
Text Label 8725 4325 2    60   ~ 0
SD
Text Label 7350 3500 0    60   ~ 0
FETSOFF
Text Label 8725 4225 2    60   ~ 0
FETSOFF
Text Label 8725 4125 2    60   ~ 0
~INT
Text Label 8725 4025 2    60   ~ 0
SDA
Text Label 8725 3925 2    60   ~ 0
SCL
Text Label 8725 3825 2    60   ~ 0
GND
$Comp
L R R18
U 1 1 5947B974
P 7550 3300
F 0 "R18" V 7630 3300 50  0000 C CNN
F 1 "10k" V 7550 3300 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 7480 3300 50  0001 C CNN
F 3 "" H 7550 3300 50  0001 C CNN
F 4 "71-CRCW0603-10K-E3" H 7550 3300 60  0001 C CNN "bom_partno"
	1    7550 3300
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6600 3400 7400 3400
Wire Wire Line
	7400 3400 7400 3300
$Comp
L R R17
U 1 1 5947BFE8
P 7350 4250
F 0 "R17" V 7430 4250 50  0000 C CNN
F 1 "10k" V 7350 4250 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 7280 4250 50  0001 C CNN
F 3 "" H 7350 4250 50  0001 C CNN
F 4 "71-CRCW0603-10K-E3" H 7350 4250 60  0001 C CNN "bom_partno"
	1    7350 4250
	1    0    0    -1  
$EndComp
$Comp
L R R19
U 1 1 5947CA92
P 7550 3700
F 0 "R19" V 7630 3700 50  0000 C CNN
F 1 "10k" V 7550 3700 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 7480 3700 50  0001 C CNN
F 3 "" H 7550 3700 50  0001 C CNN
F 4 "71-CRCW0603-10K-E3" H 7550 3700 60  0001 C CNN "bom_partno"
	1    7550 3700
	0    -1   -1   0   
$EndComp
Connection ~ 7700 3300
Wire Wire Line
	6600 3700 7400 3700
Wire Wire Line
	7700 3200 7700 3700
$Comp
L R R20
U 1 1 5947D372
P 7925 3350
F 0 "R20" V 8005 3350 50  0000 C CNN
F 1 "10k" V 7925 3350 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 7855 3350 50  0001 C CNN
F 3 "" H 7925 3350 50  0001 C CNN
F 4 "71-CRCW0603-10K-E3" H 7925 3350 60  0001 C CNN "bom_partno"
	1    7925 3350
	1    0    0    -1  
$EndComp
$Comp
L R R21
U 1 1 5947D4CB
P 8100 3350
F 0 "R21" V 8180 3350 50  0000 C CNN
F 1 "10k" V 8100 3350 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 8030 3350 50  0001 C CNN
F 3 "" H 8100 3350 50  0001 C CNN
F 4 "71-CRCW0603-10K-E3" H 8100 3350 60  0001 C CNN "bom_partno"
	1    8100 3350
	1    0    0    -1  
$EndComp
Connection ~ 7800 3200
Connection ~ 7925 3200
Text Label 7925 3500 3    60   ~ 0
SDA
Text Label 8100 3500 3    60   ~ 0
SCL
Wire Wire Line
	5900 2700 6000 2700
Connection ~ 5900 2700
Connection ~ 5400 2325
Connection ~ 5300 2325
$Comp
L Mounting_Hole MK1
U 1 1 594841F3
P 9100 6225
F 0 "MK1" H 9100 6425 50  0000 C CNN
F 1 "Mounting_Hole" H 9100 6350 50  0000 C CNN
F 2 "Mounting_Holes:MountingHole_3.2mm_M3" H 9100 6225 50  0001 C CNN
F 3 "" H 9100 6225 50  0001 C CNN
	1    9100 6225
	1    0    0    -1  
$EndComp
$Comp
L Mounting_Hole MK2
U 1 1 59485358
P 9650 6225
F 0 "MK2" H 9650 6425 50  0000 C CNN
F 1 "Mounting_Hole" H 9650 6350 50  0000 C CNN
F 2 "Mounting_Holes:MountingHole_3.2mm_M3" H 9650 6225 50  0001 C CNN
F 3 "" H 9650 6225 50  0001 C CNN
	1    9650 6225
	1    0    0    -1  
$EndComp
$Comp
L Mounting_Hole MK3
U 1 1 59485495
P 10200 6225
F 0 "MK3" H 10200 6425 50  0000 C CNN
F 1 "Mounting_Hole" H 10200 6350 50  0000 C CNN
F 2 "Mounting_Holes:MountingHole_3.2mm_M3" H 10200 6225 50  0001 C CNN
F 3 "" H 10200 6225 50  0001 C CNN
	1    10200 6225
	1    0    0    -1  
$EndComp
$Comp
L Mounting_Hole MK4
U 1 1 594855DB
P 10750 6225
F 0 "MK4" H 10750 6425 50  0000 C CNN
F 1 "Mounting_Hole" H 10750 6350 50  0000 C CNN
F 2 "Mounting_Holes:MountingHole_3.2mm_M3" H 10750 6225 50  0001 C CNN
F 3 "" H 10750 6225 50  0001 C CNN
	1    10750 6225
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 1500 4050 2325
$Comp
L CONN_01X01 J3
U 1 1 59491371
P 2050 1600
F 0 "J3" H 2050 1700 50  0000 C CNN
F 1 "VBATT+" V 2150 1600 50  0000 C CNN
F 2 "Wire_Pads:SolderWirePad_single_2mmDrill" H 2050 1600 50  0001 C CNN
F 3 "" H 2050 1600 50  0001 C CNN
	1    2050 1600
	-1   0    0    1   
$EndComp
$Comp
L CONN_01X01 J4
U 1 1 59491D1C
P 2050 1925
F 0 "J4" H 2050 2025 50  0000 C CNN
F 1 "VBATT-" V 2150 1925 50  0000 C CNN
F 2 "Wire_Pads:SolderWirePad_single_2mmDrill" H 2050 1925 50  0001 C CNN
F 3 "" H 2050 1925 50  0001 C CNN
	1    2050 1925
	-1   0    0    1   
$EndComp
$Comp
L CONN_01X01 J5
U 1 1 59493A23
P 6700 1600
F 0 "J5" H 6700 1700 50  0000 C CNN
F 1 "PACK+" V 6800 1600 50  0000 C CNN
F 2 "Wire_Pads:SolderWirePad_single_2mmDrill" H 6700 1600 50  0001 C CNN
F 3 "" H 6700 1600 50  0001 C CNN
	1    6700 1600
	1    0    0    1   
$EndComp
$Comp
L CONN_01X01 J6
U 1 1 59493A29
P 6700 1925
F 0 "J6" H 6700 2025 50  0000 C CNN
F 1 "PACK-" V 6800 1925 50  0000 C CNN
F 2 "Wire_Pads:SolderWirePad_single_2mmDrill" H 6700 1925 50  0001 C CNN
F 3 "" H 6700 1925 50  0001 C CNN
	1    6700 1925
	1    0    0    1   
$EndComp
Wire Wire Line
	2700 2500 2700 2200
Wire Wire Line
	3000 2450 3000 2200
$Comp
L GND #PWR?
U 1 1 594980C9
P 1475 4525
F 0 "#PWR?" H 1475 4275 50  0001 C CNN
F 1 "GND" H 1475 4375 50  0000 C CNN
F 2 "" H 1475 4525 50  0001 C CNN
F 3 "" H 1475 4525 50  0001 C CNN
	1    1475 4525
	1    0    0    -1  
$EndComp
$EndSCHEMATC
