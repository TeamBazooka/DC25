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
LIBS:DC25
LIBS:switches
LIBS:DC25-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L CONN_02X03 ISP1
U 1 1 58C86AD1
P 2300 3950
F 0 "ISP1" H 2300 4150 50  0000 C CNN
F 1 "CONN_02X03" H 2300 3750 50  0001 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x03_Pitch2.54mm" H 2300 2750 50  0001 C CNN
F 3 "" H 2300 2750 50  0000 C CNN
	1    2300 3950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR01
U 1 1 58C8725D
P 2650 4100
F 0 "#PWR01" H 2650 3850 50  0001 C CNN
F 1 "GND" H 2650 3950 50  0000 C CNN
F 2 "" H 2650 4100 50  0000 C CNN
F 3 "" H 2650 4100 50  0000 C CNN
	1    2650 4100
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR02
U 1 1 58C87286
P 2650 3800
F 0 "#PWR02" H 2650 3650 50  0001 C CNN
F 1 "+5V" H 2650 3940 50  0000 C CNN
F 2 "" H 2650 3800 50  0000 C CNN
F 3 "" H 2650 3800 50  0000 C CNN
	1    2650 3800
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR03
U 1 1 58C8747B
P 800 750
F 0 "#PWR03" H 800 600 50  0001 C CNN
F 1 "+5V" H 800 890 50  0000 C CNN
F 2 "" H 800 750 50  0000 C CNN
F 3 "" H 800 750 50  0000 C CNN
	1    800  750 
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 58C874D0
P 850 3150
F 0 "#PWR04" H 850 2900 50  0001 C CNN
F 1 "GND" H 850 3000 50  0000 C CNN
F 2 "" H 850 3150 50  0000 C CNN
F 3 "" H 850 3150 50  0000 C CNN
	1    850  3150
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 58C87518
P 600 1450
F 0 "C1" H 625 1550 50  0000 L CNN
F 1 "100n" H 625 1350 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 638 1300 50  0001 C CNN
F 3 "" H 600 1450 50  0000 C CNN
	1    600  1450
	1    0    0    -1  
$EndComp
$Comp
L Crystal Y1
U 1 1 58C8765C
P 1150 4000
F 0 "Y1" H 1150 4150 50  0000 C CNN
F 1 "16MHz" H 1150 3850 50  0000 C CNN
F 2 "Crystals:Crystal_SMD_HC49-SD_HandSoldering" H 1150 4000 50  0001 C CNN
F 3 "" H 1150 4000 50  0000 C CNN
	1    1150 4000
	1    0    0    -1  
$EndComp
$Comp
L C C2
U 1 1 58C87714
P 800 4250
F 0 "C2" H 825 4350 50  0000 L CNN
F 1 "22p" H 825 4150 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 838 4100 50  0001 C CNN
F 3 "" H 800 4250 50  0000 C CNN
	1    800  4250
	1    0    0    -1  
$EndComp
$Comp
L C C3
U 1 1 58C8775F
P 1450 4250
F 0 "C3" H 1475 4350 50  0000 L CNN
F 1 "22p" H 1475 4150 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 1488 4100 50  0001 C CNN
F 3 "" H 1450 4250 50  0000 C CNN
	1    1450 4250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR05
U 1 1 58C87A0E
P 1100 4450
F 0 "#PWR05" H 1100 4200 50  0001 C CNN
F 1 "GND" H 1100 4300 50  0000 C CNN
F 2 "" H 1100 4450 50  0000 C CNN
F 3 "" H 1100 4450 50  0000 C CNN
	1    1100 4450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR06
U 1 1 58C8A13C
P 3250 1250
F 0 "#PWR06" H 3250 1000 50  0001 C CNN
F 1 "GND" H 3250 1100 50  0000 C CNN
F 2 "" H 3250 1250 50  0000 C CNN
F 3 "" H 3250 1250 50  0000 C CNN
	1    3250 1250
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR07
U 1 1 58C8A195
P 3400 1250
F 0 "#PWR07" H 3400 1100 50  0001 C CNN
F 1 "+5V" H 3400 1390 50  0000 C CNN
F 2 "" H 3400 1250 50  0000 C CNN
F 3 "" H 3400 1250 50  0000 C CNN
	1    3400 1250
	-1   0    0    1   
$EndComp
NoConn ~ 3500 1250
Text Label 800  3700 0    60   ~ 0
CLK1
Text Label 1450 3700 0    60   ~ 0
CLK2
Text Label 2850 1400 0    60   ~ 0
CLK1
Text Label 2850 1500 0    60   ~ 0
CLK2
Text Label 2050 3850 2    60   ~ 0
ISP1
Text Label 2050 3950 2    60   ~ 0
ISP3
Text Label 2050 4050 2    60   ~ 0
ISP5
Text Label 2550 3950 0    60   ~ 0
ISP4
Text Label 2850 1100 0    60   ~ 0
ISP4
Text Label 2850 1200 0    60   ~ 0
ISP1
Text Label 2850 1300 0    60   ~ 0
ISP3
Text Label 2850 2250 0    60   ~ 0
ISP5
Text Label 3600 1250 3    60   ~ 0
RS
Text Label 3700 1250 3    60   ~ 0
RW
Text Label 3800 1250 3    60   ~ 0
E
Text Label 3900 1250 3    60   ~ 0
DB0
Text Label 4000 1250 3    60   ~ 0
DB1
Text Label 4100 1250 3    60   ~ 0
DB2
Text Label 4200 1250 3    60   ~ 0
DB3
Text Label 4300 1250 3    60   ~ 0
DB4
Text Label 4400 1250 3    60   ~ 0
DB5
Text Label 4500 1250 3    60   ~ 0
DB6
Text Label 4600 1250 3    60   ~ 0
DB7
Text Label 2850 1850 0    60   ~ 0
RS
Text Label 2850 1750 0    60   ~ 0
RW
Text Label 2850 1000 0    60   ~ 0
DB0
Text Label 2850 900  0    60   ~ 0
DB1
Text Label 2850 800  0    60   ~ 0
DB2
Text Label 2850 3100 0    60   ~ 0
DB3
Text Label 2850 3000 0    60   ~ 0
DB4
Text Label 2850 2900 0    60   ~ 0
DB5
Text Label 2850 2800 0    60   ~ 0
DB6
Text Label 2850 2700 0    60   ~ 0
DB7
$Comp
L WS2812B LED2
U 1 1 58C8AB60
P 8600 5300
F 0 "LED2" H 8600 4900 60  0000 C CNN
F 1 "WS2812B" H 8600 5700 60  0000 C CNN
F 2 "WS2812B:WS2812B" V 8550 5300 60  0001 C CNN
F 3 "" V 8550 5300 60  0000 C CNN
	1    8600 5300
	1    0    0    -1  
$EndComp
$Comp
L WS2812B LED1
U 1 1 58C8B2F9
P 9800 5300
F 0 "LED1" H 9800 4900 60  0000 C CNN
F 1 "WS2812B" H 9800 5700 60  0000 C CNN
F 2 "WS2812B:WS2812B" V 9750 5300 60  0001 C CNN
F 3 "" V 9750 5300 60  0000 C CNN
	1    9800 5300
	1    0    0    -1  
$EndComp
$Comp
L WS2812B LED4
U 1 1 58C8B5EE
P 6200 5300
F 0 "LED4" H 6200 4900 60  0000 C CNN
F 1 "WS2812B" H 6200 5700 60  0000 C CNN
F 2 "WS2812B:WS2812B" V 6150 5300 60  0001 C CNN
F 3 "" V 6150 5300 60  0000 C CNN
	1    6200 5300
	1    0    0    -1  
$EndComp
$Comp
L WS2812B LED3
U 1 1 58C8B5F4
P 7400 5300
F 0 "LED3" H 7400 4900 60  0000 C CNN
F 1 "WS2812B" H 7400 5700 60  0000 C CNN
F 2 "WS2812B:WS2812B" V 7350 5300 60  0001 C CNN
F 3 "" V 7350 5300 60  0000 C CNN
	1    7400 5300
	1    0    0    -1  
$EndComp
Text Label 10300 5100 0    60   ~ 0
RGB1
Text Label 2850 2600 0    60   ~ 0
RGB1
NoConn ~ 2850 1950
NoConn ~ 2850 2050
$Comp
L GND #PWR08
U 1 1 58C8D7B0
P 600 1700
F 0 "#PWR08" H 600 1450 50  0001 C CNN
F 1 "GND" H 600 1550 50  0000 C CNN
F 2 "" H 600 1700 50  0000 C CNN
F 3 "" H 600 1700 50  0000 C CNN
	1    600  1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	800  800  950  800 
Wire Wire Line
	800  750  800  1400
Wire Wire Line
	600  1100 950  1100
Connection ~ 800  800 
Connection ~ 800  1100
Wire Wire Line
	850  2900 850  3150
Wire Wire Line
	950  3100 850  3100
Connection ~ 850  3100
Wire Wire Line
	800  1400 950  1400
Wire Wire Line
	800  4400 1450 4400
Wire Wire Line
	1100 4400 1100 4450
Connection ~ 1100 4400
Wire Wire Line
	1000 4000 800  4000
Wire Wire Line
	800  3700 800  4100
Wire Wire Line
	1300 4000 1450 4000
Wire Wire Line
	1450 3700 1450 4100
Connection ~ 800  4000
Connection ~ 1450 4000
Wire Wire Line
	2550 4050 2650 4050
Wire Wire Line
	2650 4050 2650 4100
Wire Wire Line
	2550 3850 2650 3850
Wire Wire Line
	2650 3850 2650 3800
Wire Wire Line
	9300 5500 9150 5500
Wire Wire Line
	9150 5500 9150 5100
Wire Wire Line
	9150 5100 9100 5100
Wire Wire Line
	8100 5500 7950 5500
Wire Wire Line
	7950 5500 7950 5100
Wire Wire Line
	7950 5100 7900 5100
Wire Wire Line
	6900 5500 6750 5500
Wire Wire Line
	6750 5500 6750 5100
Wire Wire Line
	6750 5100 6700 5100
Wire Wire Line
	5700 5100 5600 5100
Wire Wire Line
	8100 5100 8050 5100
Wire Wire Line
	9300 5100 9250 5100
Wire Wire Line
	6900 5100 6850 5100
Wire Wire Line
	600  1300 600  1100
Wire Wire Line
	600  1700 600  1600
Wire Wire Line
	850  3000 950  3000
Text Label 2850 1650 0    60   ~ 0
E
NoConn ~ 2850 2150
$Comp
L CONN_01X04 P2
U 1 1 58C975BB
P 5050 900
F 0 "P2" H 5050 1150 50  0000 C CNN
F 1 "CONN_01X04" V 5150 900 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04_Pitch2.54mm" H 5050 900 50  0001 C CNN
F 3 "" H 5050 900 50  0000 C CNN
	1    5050 900 
	0    -1   -1   0   
$EndComp
$Comp
L +5V #PWR09
U 1 1 58C97942
P 4750 1250
F 0 "#PWR09" H 4750 1100 50  0001 C CNN
F 1 "+5V" H 4750 1390 50  0000 C CNN
F 2 "" H 4750 1250 50  0000 C CNN
F 3 "" H 4750 1250 50  0000 C CNN
	1    4750 1250
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR010
U 1 1 58C9797A
P 4950 1250
F 0 "#PWR010" H 4950 1000 50  0001 C CNN
F 1 "GND" H 4950 1100 50  0000 C CNN
F 2 "" H 4950 1250 50  0000 C CNN
F 3 "" H 4950 1250 50  0000 C CNN
	1    4950 1250
	1    0    0    -1  
$EndComp
$Comp
L +BATT #PWR011
U 1 1 58C983F1
P 5650 950
F 0 "#PWR011" H 5650 800 50  0001 C CNN
F 1 "+BATT" H 5650 1090 50  0000 C CNN
F 2 "" H 5650 950 50  0000 C CNN
F 3 "" H 5650 950 50  0000 C CNN
	1    5650 950 
	0    -1   -1   0   
$EndComp
$Comp
L +BATT #PWR012
U 1 1 58C984A1
P 5400 1250
F 0 "#PWR012" H 5400 1100 50  0001 C CNN
F 1 "+BATT" H 5400 1390 50  0000 C CNN
F 2 "" H 5400 1250 50  0000 C CNN
F 3 "" H 5400 1250 50  0000 C CNN
	1    5400 1250
	-1   0    0    1   
$EndComp
$Comp
L GNDA #PWR013
U 1 1 58C9851F
P 5150 1250
F 0 "#PWR013" H 5150 1000 50  0001 C CNN
F 1 "GNDA" H 5150 1100 50  0000 C CNN
F 2 "" H 5150 1250 50  0000 C CNN
F 3 "" H 5150 1250 50  0000 C CNN
	1    5150 1250
	1    0    0    -1  
$EndComp
$Comp
L GNDA #PWR014
U 1 1 58C985CF
P 6650 850
F 0 "#PWR014" H 6650 600 50  0001 C CNN
F 1 "GNDA" H 6650 700 50  0000 C CNN
F 2 "" H 6650 850 50  0000 C CNN
F 3 "" H 6650 850 50  0000 C CNN
	1    6650 850 
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6050 950  6150 950 
Wire Wire Line
	5650 950  5750 950 
Wire Wire Line
	5150 1250 5150 1200
Wire Wire Line
	5150 1200 5100 1200
Wire Wire Line
	5100 1200 5100 1100
Wire Wire Line
	4950 1250 4950 1200
Wire Wire Line
	4950 1200 5000 1200
Wire Wire Line
	5000 1200 5000 1100
Wire Wire Line
	4900 1100 4900 1150
Wire Wire Line
	4900 1150 4750 1150
Wire Wire Line
	4750 1150 4750 1250
Wire Wire Line
	5200 1100 5200 1150
Wire Wire Line
	5200 1150 5400 1150
Wire Wire Line
	5400 1150 5400 1250
$Comp
L Battery_Cell BT1
U 1 1 58C995B5
P 5950 950
F 0 "BT1" H 6050 1050 50  0000 L CNN
F 1 "18650" H 6050 950 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" V 5950 1010 50  0001 C CNN
F 3 "" V 5950 1010 50  0001 C CNN
	1    5950 950 
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6550 850  6650 850 
NoConn ~ 6550 1050
$Comp
L SW_DPDT_x2 SW1
U 1 1 58C99AEC
P 6350 950
F 0 "SW1" H 6350 1120 50  0000 C CNN
F 1 "SW_DPDT_x2" H 6350 750 50  0000 C CNN
F 2 "footprints:switch_EG2219" H 6350 950 50  0001 C CNN
F 3 "" H 6350 950 50  0001 C CNN
	1    6350 950 
	1    0    0    -1  
$EndComp
Wire Wire Line
	3250 1250 3300 1250
Wire Wire Line
	7900 5500 7900 5800
Wire Wire Line
	1850 5800 10300 5800
Connection ~ 6700 5800
Wire Wire Line
	8050 5100 8050 5750
Wire Wire Line
	750  5750 9250 5750
Connection ~ 5600 5750
Wire Wire Line
	9250 5750 9250 5100
Wire Wire Line
	9100 5800 9100 5500
Connection ~ 7900 5800
Wire Wire Line
	10300 5800 10300 5500
Connection ~ 9100 5800
Connection ~ 8050 5750
$Comp
L WS2812B LED6
U 1 1 58CDB2F1
P 3750 5300
F 0 "LED6" H 3750 4900 60  0000 C CNN
F 1 "WS2812B" H 3750 5700 60  0000 C CNN
F 2 "WS2812B:WS2812B" V 3700 5300 60  0001 C CNN
F 3 "" V 3700 5300 60  0000 C CNN
	1    3750 5300
	1    0    0    -1  
$EndComp
$Comp
L WS2812B LED5
U 1 1 58CDB2F7
P 4950 5300
F 0 "LED5" H 4950 4900 60  0000 C CNN
F 1 "WS2812B" H 4950 5700 60  0000 C CNN
F 2 "WS2812B:WS2812B" V 4900 5300 60  0001 C CNN
F 3 "" V 4900 5300 60  0000 C CNN
	1    4950 5300
	1    0    0    -1  
$EndComp
$Comp
L WS2812B LED8
U 1 1 58CDB2FD
P 1350 5300
F 0 "LED8" H 1350 4900 60  0000 C CNN
F 1 "WS2812B" H 1350 5700 60  0000 C CNN
F 2 "WS2812B:WS2812B" V 1300 5300 60  0001 C CNN
F 3 "" V 1300 5300 60  0000 C CNN
	1    1350 5300
	1    0    0    -1  
$EndComp
$Comp
L WS2812B LED7
U 1 1 58CDB303
P 2550 5300
F 0 "LED7" H 2550 4900 60  0000 C CNN
F 1 "WS2812B" H 2550 5700 60  0000 C CNN
F 2 "WS2812B:WS2812B" V 2500 5300 60  0001 C CNN
F 3 "" V 2500 5300 60  0000 C CNN
	1    2550 5300
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR015
U 1 1 58CDB309
P 1850 5850
F 0 "#PWR015" H 1850 5600 50  0001 C CNN
F 1 "GND" H 1850 5700 50  0000 C CNN
F 2 "" H 1850 5850 50  0000 C CNN
F 3 "" H 1850 5850 50  0000 C CNN
	1    1850 5850
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR016
U 1 1 58CDB30F
P 750 5800
F 0 "#PWR016" H 750 5650 50  0001 C CNN
F 1 "+5V" H 750 5940 50  0000 C CNN
F 2 "" H 750 5800 50  0000 C CNN
F 3 "" H 750 5800 50  0000 C CNN
	1    750  5800
	-1   0    0    1   
$EndComp
NoConn ~ 850  5500
Wire Wire Line
	4450 5500 4300 5500
Wire Wire Line
	4300 5500 4300 5100
Wire Wire Line
	4300 5100 4250 5100
Wire Wire Line
	3250 5500 3100 5500
Wire Wire Line
	3100 5500 3100 5100
Wire Wire Line
	3100 5100 3050 5100
Wire Wire Line
	2050 5500 1900 5500
Wire Wire Line
	1900 5500 1900 5100
Wire Wire Line
	1900 5100 1850 5100
Wire Wire Line
	850  5100 750  5100
Wire Wire Line
	3250 5100 3200 5100
Wire Wire Line
	4450 5100 4400 5100
Wire Wire Line
	2050 5100 2000 5100
Wire Wire Line
	1850 5500 1850 5850
Wire Wire Line
	3050 5500 3050 5800
Connection ~ 1850 5800
Wire Wire Line
	750  5100 750  5800
Wire Wire Line
	3200 5100 3200 5750
Connection ~ 750  5750
Wire Wire Line
	4400 5100 4400 5750
Wire Wire Line
	4250 5800 4250 5500
Connection ~ 3050 5800
Wire Wire Line
	5450 5800 5450 5500
Connection ~ 4250 5800
Connection ~ 3200 5750
Wire Wire Line
	5450 5100 5500 5100
Wire Wire Line
	5500 5100 5500 5500
Wire Wire Line
	5500 5500 5700 5500
Wire Wire Line
	5600 5100 5600 5750
Connection ~ 4400 5750
Wire Wire Line
	6700 5500 6700 5800
Connection ~ 5450 5800
Wire Wire Line
	6850 5100 6850 5750
Connection ~ 6850 5750
Wire Wire Line
	2000 5100 2000 5750
Connection ~ 2000 5750
$Comp
L ATMEGA328P-AU U1
U 1 1 58CDC7AF
P 1850 1900
F 0 "U1" H 1100 3150 50  0000 L BNN
F 1 "ATMEGA328P-AU" H 2250 500 50  0000 L BNN
F 2 "Housings_QFP:TQFP-32_7x7mm_Pitch0.8mm" H 1850 1900 50  0001 C CIN
F 3 "" H 1850 1900 50  0001 C CNN
	1    1850 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	850  2900 950  2900
Connection ~ 850  3000
NoConn ~ 950  2150
NoConn ~ 950  2250
Wire Wire Line
	950  900  800  900 
Connection ~ 800  900 
$Comp
L VFD DIS1
U 1 1 58D4713E
P 3950 850
F 0 "DIS1" H 4450 900 60  0000 C CNN
F 1 "VFD" H 3400 900 60  0000 C CNN
F 2 "" H 3500 950 60  0001 C CNN
F 3 "" H 3500 950 60  0001 C CNN
	1    3950 850 
	1    0    0    -1  
$EndComp
Text Label 2850 2400 0    60   ~ 0
RX
Text Label 2850 2500 0    60   ~ 0
TX
$Comp
L CONN_01X04 P1
U 1 1 58D6E005
P 4650 1850
F 0 "P1" H 4650 2100 50  0000 C CNN
F 1 "CONN_01X04" V 4750 1850 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04_Pitch2.54mm" H 4650 1850 50  0001 C CNN
F 3 "" H 4650 1850 50  0000 C CNN
	1    4650 1850
	0    -1   -1   0   
$EndComp
$Comp
L +5V #PWR?
U 1 1 58D6E00B
P 4350 2200
F 0 "#PWR?" H 4350 2050 50  0001 C CNN
F 1 "+5V" H 4350 2340 50  0000 C CNN
F 2 "" H 4350 2200 50  0000 C CNN
F 3 "" H 4350 2200 50  0000 C CNN
	1    4350 2200
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR?
U 1 1 58D6E011
P 4550 2200
F 0 "#PWR?" H 4550 1950 50  0001 C CNN
F 1 "GND" H 4550 2050 50  0000 C CNN
F 2 "" H 4550 2200 50  0000 C CNN
F 3 "" H 4550 2200 50  0000 C CNN
	1    4550 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 2200 4750 2150
Wire Wire Line
	4750 2150 4700 2150
Wire Wire Line
	4700 2150 4700 2050
Wire Wire Line
	4550 2200 4550 2150
Wire Wire Line
	4550 2150 4600 2150
Wire Wire Line
	4600 2150 4600 2050
Wire Wire Line
	4500 2050 4500 2100
Wire Wire Line
	4500 2100 4350 2100
Wire Wire Line
	4350 2100 4350 2200
Wire Wire Line
	4800 2050 4800 2100
Wire Wire Line
	4800 2100 5000 2100
Wire Wire Line
	5000 2100 5000 2200
Text Label 5000 2200 0    60   ~ 0
TX
Text Label 4750 2200 0    60   ~ 0
RX
$EndSCHEMATC
