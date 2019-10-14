EESchema Schematic File Version 4
EELAYER 26 0
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
L Device:R_Small_US R?
U 1 1 5DA3C41E
P 3300 4000
F 0 "R?" H 3368 4046 50  0001 L CNN
F 1 "1R" H 3368 4000 50  0000 L CNN
F 2 "" H 3300 4000 50  0001 C CNN
F 3 "~" H 3300 4000 50  0001 C CNN
	1    3300 4000
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R?
U 1 1 5DA3C4C2
P 3550 3800
F 0 "R?" V 3345 3800 50  0001 C CNN
F 1 "10K" V 3437 3800 50  0000 C CNN
F 2 "" H 3550 3800 50  0001 C CNN
F 3 "~" H 3550 3800 50  0001 C CNN
	1    3550 3800
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5DA3C691
P 3850 4000
F 0 "C?" H 3942 4046 50  0001 L CNN
F 1 "10uF" H 3942 4000 50  0000 L CNN
F 2 "" H 3850 4000 50  0001 C CNN
F 3 "~" H 3850 4000 50  0001 C CNN
	1    3850 4000
	1    0    0    -1  
$EndComp
$Comp
L Device:Battery BT?
U 1 1 5DA3C73D
P 2600 3900
F 0 "BT?" H 2708 3946 50  0001 L CNN
F 1 "+5V" H 2708 3900 50  0000 L CNN
F 2 "" V 2600 3960 50  0001 C CNN
F 3 "~" V 2600 3960 50  0001 C CNN
	1    2600 3900
	1    0    0    -1  
$EndComp
$Comp
L Motor:Motor_Servo M?
U 1 1 5DA3CA98
P 3200 3350
F 0 "M?" H 3531 3415 50  0001 L CNN
F 1 "Motor_Servo" H 3531 3324 50  0001 L CNN
F 2 "" H 3200 3160 50  0001 C CNN
F 3 "http://forums.parallax.com/uploads/attachments/46831/74481.png" H 3200 3160 50  0001 C CNN
	1    3200 3350
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR?
U 1 1 5DA3CBF8
P 2600 4200
F 0 "#PWR?" H 2600 3950 50  0001 C CNN
F 1 "Earth" H 2600 4050 50  0001 C CNN
F 2 "" H 2600 4200 50  0001 C CNN
F 3 "~" H 2600 4200 50  0001 C CNN
	1    2600 4200
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR?
U 1 1 5DA3CC29
P 3300 4200
F 0 "#PWR?" H 3300 3950 50  0001 C CNN
F 1 "Earth" H 3300 4050 50  0001 C CNN
F 2 "" H 3300 4200 50  0001 C CNN
F 3 "~" H 3300 4200 50  0001 C CNN
	1    3300 4200
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR?
U 1 1 5DA3CC5A
P 3850 4200
F 0 "#PWR?" H 3850 3950 50  0001 C CNN
F 1 "Earth" H 3850 4050 50  0001 C CNN
F 2 "" H 3850 4200 50  0001 C CNN
F 3 "~" H 3850 4200 50  0001 C CNN
	1    3850 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 4200 3850 4100
Wire Wire Line
	3300 4200 3300 4100
Wire Wire Line
	3850 3900 3850 3800
Wire Wire Line
	3850 3800 3650 3800
Wire Wire Line
	2900 3450 2900 3800
Wire Wire Line
	2900 3800 3300 3800
Wire Wire Line
	3300 3800 3300 3900
Wire Wire Line
	3300 3800 3450 3800
Connection ~ 3300 3800
Wire Wire Line
	2600 3700 2600 3350
Wire Wire Line
	2600 3350 2900 3350
Wire Wire Line
	2600 4200 2600 4100
Wire Wire Line
	2600 3250 2900 3250
Wire Wire Line
	4200 3800 3850 3800
Connection ~ 3850 3800
Text GLabel 2600 3250 0    50   Input ~ 0
PWMout
Text GLabel 4200 3800 2    50   Output ~ 0
ADCin
$EndSCHEMATC
