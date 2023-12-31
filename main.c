/*
Setup
uno	GND.1	lcd	VSS
uno	GND.1	lcd	RW
uno	5V		lcd	VDD
uno	2		lcd	RS
uno	3		lcd	E
uno	4		lcd	D4
uno	5		lcd	D5
uno	6		lcd	D6
uno	7		lcd	D7
atmodem	TX	uno	0
atmodem	RX	uno	1
uno	GND.1	atmodem	GND
uno	5V		atmodem	VCC
pot  GND	uno	GND.1
pot  VCC	uno	5V
pot  SIG	lcd	V0

 https://wokwi.com/projects/376921405150878721
 */

#define F_CPU 16000000UL 

#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"
#include "ESP8266.h"

unsigned int getPulseData(void);
unsigned int getOximetryData(void);

int main (void)
{
	char LCDbuffer[20];

    lcd_init();
	lcd_clear(); 
    lcd_enable_blinking();
    lcd_enable_cursor();

    
    lcd_puts("Starting:");

	_delay_ms(1000);					 	// Delay on startup
	

	int pulse, oximetry;

	
	init_serial();		
    lcd_set_cursor(0,1);
	lcd_puts("RESET         ");
	ESPinit();								// Setup ESP8266
	printf("Setup complete, running program\n");


	while(1)
	{
		pulse = getPulseData();				// Get dummy data
		addData("field1",pulse);
		oximetry = getOximetryData();				// Get dummy data
		addData("field2",oximetry);

		pushData();							// Push data to Firebase

		lcd_set_cursor(0,0);
        sprintf(LCDbuffer, "Pulse: %d BPM", pulse);
        lcd_puts(LCDbuffer);

		lcd_set_cursor(0,1);
        sprintf(LCDbuffer, "Oximetry: %d%%", oximetry);
        lcd_puts(LCDbuffer);

		pushData();							// Push data to Firebase
		_delay_ms(500); // Works with 1000 ms
		lcd_clear(); 
	}
}

int pulseData[] = {70, 72, 68, 74, 76, 73, 71};
int oximetryData[] = {97, 98, 96, 99, 95, 96, 98};
int dataSize = sizeof(pulseData) / sizeof(pulseData[0]);
int currentIndex = 0;

unsigned int getPulseData(void)
{
// Normal resting heart rate is between 60 and 100 beats per minute
	int data = pulseData[currentIndex];
	currentIndex = (currentIndex + 1) % dataSize;
    return data;
}

unsigned int getOximetryData(void)
{
// Normal resting heart rate is between 60 and 100 beats per minute
	int data = oximetryData[currentIndex];
	currentIndex = (currentIndex + 1) % dataSize;
    return data;
}