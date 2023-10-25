/*
 * Hausmeistergeraet.c
 *
 * Created: 20.12.2020 10:48:43
 * Author : Maximilian Frank
 */ 

#include <avr/io.h>

#include <avr/interrupt.h>
#include <avr/wdt.h>
#include <avr/eeprom.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <util/delay.h>
#include <string.h>

#include "objects.hpp"

#ifndef F_CPU
	#define 	F_CPU		16000000UL
#endif

using namespace OBJECTS;

//zwischen speicher für die measurementResult
volatile uint16_t firstNumber = 0;
volatile uint16_t secondNumber = 0;
volatile uint16_t betweenMeasureResult; 
uint16_t savedMeasuredValue[3];


//Festlegen des Elements zur Anzeige von Interger-Werten (die Funktion itoa() wird verwendet)
//https://stackoverflow.com/questions/8257714/how-can-i-convert-an-int-to-a-string-in-c
//https://cplusplus.com/reference/cstdlib/itoa/
char measurementResult [5];
char printFirstNumber[5], printSecondNumber[5];
char printSavedValue1[5], printSavedValue2[5],printSavedValue3[5];



void init(void)
{
	PORTS::Selfretention.setHigh();
	
	wdt_reset();
	wdt_enable(WDTO_8S);
	
	WDTCSR = (1<<WDIE);

	Display.init();
	Display.gotoXY(0,0);
	while(!Display.clrScreen()) Display.restart();
	Display.setFontSize(0); 

	uint8_t lang = eeprom_read_byte((uint8_t*) 1000); //die (unter gesetzte neue) sprache wird gesezt
	switch (lang)
	{
		case 0:
			SysLanguage.setEnglish();
			break;
		case 1:
			SysLanguage.setGerman();
			break;
		case 2:
			SysLanguage.setFrench();
			break;
		case 3:
			SysLanguage.setSpanish();
			break;
		default:
			SysLanguage.setEnglish();
			break;
	}

}




int main(void)
{	
	
	init();   //selfretention--->high

	bool displayOn =false;
	bool set = false;
	uint8_t state = 0;
	volatile uint8_t savedValueIndex = 0;
	
	//Speicherplatz der gemessenen   Daten 
	//ACHTUNG!!: EEPROM-SPeicher (ATmega2561) von 4 KBytes
	//uint16_t SavedValue1= eeprom_read_word((uint16_t*) 1804);  
	//uint16_t SavedValue2= eeprom_read_word((uint16_t*) 1805);
	//uint16_t SavedValue3= eeprom_read_word((uint16_t*) 1806);
	





	while(BUTTONS::Links.isPressed())
	{
		if (!displayOn)
		{
			Display.gotoXY(0,3);
			Display.writeString("     GOSSEN     ");
			Display.gotoXY(0,4);
			Display.writeString("    METRAWATT   ");
			displayOn=true;
		}
		wdt_reset();
	}


    _delay_ms(3000);

	while(!Display.clrScreen()) Display.restart();
 

	sei();

	while(1)
    {
		if (BUTTONS::Oben.isActivated()) // scroll nach oben bei MENU
		{
			state++;
			if (state > 2)
			{
				state = 0;
			}
			while(!Display.clrScreen()) Display.restart();
		}
		if (BUTTONS::Unten.isActivated() )  // scroll nach unten bei MENU
		{
			if (state >= 1){state--;}
			else{state=2;}
			while(!Display.clrScreen()) Display.restart();
		}
		switch (state)
		{
			case 0:
				Display.gotoXY(14,0);
				Display.drawArrowUp();
				Display.gotoXY(0,3);
				Display.writeString(SysLanguage.getmessung());  //MENÜ-MEASURE
				Display.gotoXY(14,7);
				Display.drawArrowDown();
				if ( BUTTONS::Rechts.isActivated())
				{
					while(!Display.clrScreen()) Display.restart();
					while(!set)
					{
						if (BUTTONS::Oben.isActivated()) 
						{
							firstNumber++;
							if(firstNumber > 9)
							{
								firstNumber=0;
							}
							while(!Display.clrScreen()) Display.restart();
							
						}
						if (BUTTONS::Unten.isActivated() ) 
						{
							if (firstNumber >= 1){firstNumber--;}
							else{firstNumber=9;}
							while(!Display.clrScreen()) Display.restart();
						}
						if ( BUTTONS::Mitte.isActivated())   //Mitte Taste bei der Messung-MENÜ ist [OK]
						{   
							while(!Display.clrScreen()) Display.restart();
							while(!set)
							{	
								if (BUTTONS::Oben.isActivated()) 
								{
									secondNumber++;
									if(secondNumber > 9)
									{
										secondNumber=0;
									}
									while(!Display.clrScreen()) Display.restart();
									
								}
								if (BUTTONS::Unten.isActivated() ) 
								{
									if (secondNumber >= 1){secondNumber--;}
									else{secondNumber=9;}
									while(!Display.clrScreen()) Display.restart();
								}
								if (BUTTONS::Mitte.isActivated())
								{	
									savedMeasuredValue[savedValueIndex]=firstNumber + secondNumber; //andere speicherungsmöglichkeit
									savedValueIndex++;
									if(savedValueIndex>2){savedValueIndex=0;}
									while(!Display.clrScreen()) Display.restart();
									while(!set)
									{	
										
										betweenMeasureResult = firstNumber + secondNumber;
										//eeprom_write_word bei nicht verändernare Datein (Überschreibt immer)
										//eeprom_update_word überschreibt nur bei Änderung (Spart Schreibzyklen)
										//eeprom_update_word((uint16_t*) savedValueIndex,betweenMeasureResult);

										itoa(betweenMeasureResult, measurementResult,10);

										Display.gotoXY(0,3);
										Display.writeString(printFirstNumber);
										Display.gotoXY(1,3);
										Display.writeString(" + ");
										Display.gotoXY(4,3);
										Display.writeString(printSecondNumber);
										Display.gotoXY(4,7);
										Display.gotoXY(5,3);
										Display.writeString("=");
										Display.gotoXY(7,3);
										Display.writeString(measurementResult);
										

										if (BUTTONS::Links.isActivated())
										{
											while(!Display.clrScreen()) Display.restart();
											set=true;
										}
										wdt_reset();
									}
									set=false;
								}
								if (BUTTONS::Links.isActivated())
								{
									while(!Display.clrScreen()) Display.restart();
									set=true;
								}
							switch (secondNumber)
							{
							case 0:   //0
								itoa(firstNumber,printFirstNumber,10);
								itoa(secondNumber,printSecondNumber,10);
								Display.gotoXY(4,0);
								Display.drawArrowUp();
								Display.gotoXY(0,3);
								Display.writeString(printFirstNumber);
								Display.gotoXY(1,3);
								Display.writeString(" + ");
								Display.gotoXY(4,3);
								Display.writeString(printSecondNumber);
								Display.gotoXY(4,7);
								Display.drawArrowDown();
								break;
							case 1:  //1
								itoa(firstNumber,printFirstNumber,10);
								itoa(secondNumber,printSecondNumber,10);
								Display.gotoXY(4,0);
								Display.drawArrowUp();
								Display.gotoXY(0,3);
								Display.writeString(printFirstNumber);
								Display.gotoXY(1,3);
								Display.writeString(" + ");
								Display.gotoXY(4,3);
								Display.writeString(printSecondNumber);
								Display.gotoXY(4,7);
								Display.drawArrowDown();
								break;
							case 2:
								itoa(firstNumber,printFirstNumber,10);
								itoa(secondNumber,printSecondNumber,10);
								Display.gotoXY(4,0);
								Display.drawArrowUp();
								Display.gotoXY(0,3);
								Display.writeString(printFirstNumber);
								Display.gotoXY(1,3);
								Display.writeString(" + ");
								Display.gotoXY(4,3);
								Display.writeString(printSecondNumber);
								Display.gotoXY(4,7);
								Display.drawArrowDown();
								break;
							case 3:
								itoa(firstNumber,printFirstNumber,10);
								itoa(secondNumber,printSecondNumber,10);
								Display.gotoXY(4,0);
								Display.drawArrowUp();
								Display.gotoXY(0,3);
								Display.writeString(printFirstNumber);
								Display.gotoXY(1,3);
								Display.writeString(" + ");
								Display.gotoXY(4,3);
								Display.writeString(printSecondNumber);
								Display.gotoXY(4,7);
								Display.drawArrowDown();
								break;
							case 4:
								itoa(firstNumber,printFirstNumber,10);
								itoa(secondNumber,printSecondNumber,10);
								Display.gotoXY(4,0);
								Display.drawArrowUp();
								Display.gotoXY(0,3);
								Display.writeString(printFirstNumber);
								Display.gotoXY(1,3);
								Display.writeString(" + ");
								Display.gotoXY(4,3);
								Display.writeString(printSecondNumber);
								Display.gotoXY(4,7);
								Display.drawArrowDown();
								break;
							case 5:
								itoa(firstNumber,printFirstNumber,10);
								itoa(secondNumber,printSecondNumber,10);
								Display.gotoXY(4,0);
								Display.drawArrowUp();
								Display.gotoXY(0,3);
								Display.writeString(printFirstNumber);
								Display.gotoXY(1,3);
								Display.writeString(" + ");
								Display.gotoXY(4,3);
								Display.writeString(printSecondNumber);
								Display.gotoXY(4,7);
								Display.drawArrowDown();
								break;
							case 6:
								itoa(firstNumber,printFirstNumber,10);
								itoa(secondNumber,printSecondNumber,10);
								Display.gotoXY(4,0);
								Display.drawArrowUp();
								Display.gotoXY(0,3);
								Display.writeString(printFirstNumber);
								Display.gotoXY(1,3);
								Display.writeString(" + ");
								Display.gotoXY(4,3);
								Display.writeString(printSecondNumber);
								Display.gotoXY(4,7);
								Display.drawArrowDown();
								break;
							case 7:
								itoa(firstNumber,printFirstNumber,10);
								itoa(secondNumber,printSecondNumber,10);
								Display.gotoXY(4,0);
								Display.drawArrowUp();
								Display.gotoXY(0,3);
								Display.writeString(printFirstNumber);
								Display.gotoXY(1,3);
								Display.writeString(" + ");
								Display.gotoXY(4,3);
								Display.writeString(printSecondNumber);
								Display.gotoXY(4,7);
								Display.drawArrowDown();
								break;
							case 8:
								itoa(firstNumber,printFirstNumber,10);
								itoa(secondNumber,printSecondNumber,10);Display.gotoXY(4,0);
								Display.drawArrowUp();
								Display.gotoXY(0,3);
								Display.writeString(printFirstNumber);
								Display.gotoXY(1,3);
								Display.writeString(" + ");
								Display.gotoXY(4,3);
								Display.writeString(printSecondNumber);
								Display.gotoXY(4,7);
								Display.drawArrowDown();
								break;
							case 9:
								itoa(firstNumber,printFirstNumber,10);
								itoa(secondNumber,printSecondNumber,10);
								Display.gotoXY(4,0);
								Display.drawArrowUp();
								Display.gotoXY(0,3);
								Display.writeString(printFirstNumber);
								Display.gotoXY(1,3);
								Display.writeString(" + ");
								Display.gotoXY(4,3);
								Display.writeString(printSecondNumber);
								Display.gotoXY(4,7);
								Display.drawArrowDown();
								break;
		
							}
							wdt_reset();
							}
							while(!Display.clrScreen()) Display.restart();
							set = false;
						}
						if (BUTTONS::Links.isActivated())
						{
							while(!Display.clrScreen()) Display.restart();
							set=true;
						}
						switch (firstNumber)
						{
							case 0:
								itoa(firstNumber,printFirstNumber,10);
								itoa(secondNumber,printSecondNumber,10);
								Display.gotoXY(0,0);
								Display.drawArrowUp();
								Display.gotoXY(0,3);
								Display.writeString(printFirstNumber);
								Display.gotoXY(1,3);
								Display.writeString(" + ");
								Display.gotoXY(4,3);
								Display.writeString(printSecondNumber);
								Display.gotoXY(0,7);
								Display.drawArrowDown();
								break;
							case 1:
								itoa(firstNumber,printFirstNumber,10);
								itoa(secondNumber,printSecondNumber,10);
								Display.gotoXY(0,0);
								Display.drawArrowUp();
								Display.gotoXY(0,3);
								Display.writeString(printFirstNumber);
								Display.gotoXY(1,3);
								Display.writeString(" + ");
								Display.gotoXY(4,3);
								Display.writeString(printSecondNumber);
								Display.gotoXY(0,7);
								Display.drawArrowDown();
								break;
							case 2:
								itoa(firstNumber,printFirstNumber,10);
								itoa(secondNumber,printSecondNumber,10);
								Display.gotoXY(0,0);
								Display.drawArrowUp();
								Display.gotoXY(0,3);
								Display.writeString(printFirstNumber);
								Display.gotoXY(1,3);
								Display.writeString(" + ");
								Display.gotoXY(4,3);
								Display.writeString(printSecondNumber);
								Display.gotoXY(0,7);
								Display.drawArrowDown();
								break;
							case 3:
								itoa(firstNumber,printFirstNumber,10);
								itoa(secondNumber,printSecondNumber,10);
								Display.gotoXY(0,0);
								Display.drawArrowUp();
								Display.gotoXY(0,3);
								Display.writeString(printFirstNumber);
								Display.gotoXY(1,3);
								Display.writeString(" + ");
								Display.gotoXY(4,3);
								Display.writeString(printSecondNumber);
								Display.gotoXY(0,7);
								Display.drawArrowDown();
								break;
							case 4:
								itoa(firstNumber,printFirstNumber,10);
								itoa(secondNumber,printSecondNumber,10);
								Display.gotoXY(0,0);
								Display.drawArrowUp();
								Display.gotoXY(0,3);
								Display.writeString(printFirstNumber);
								Display.gotoXY(1,3);
								Display.writeString(" + ");
								Display.gotoXY(4,3);
								Display.writeString(printSecondNumber);
								Display.gotoXY(0,7);
								Display.drawArrowDown();
								break;
							case 5:
								itoa(firstNumber,printFirstNumber,10);
								itoa(secondNumber,printSecondNumber,10);
								Display.gotoXY(0,0);
								Display.drawArrowUp();
								Display.gotoXY(0,3);
								Display.writeString(printFirstNumber);
								Display.gotoXY(1,3);
								Display.writeString(" + ");
								Display.gotoXY(4,3);
								Display.writeString(printSecondNumber);
								Display.gotoXY(0,7);
								Display.drawArrowDown();
								break;
							case 6:
								itoa(firstNumber,printFirstNumber,10);
								itoa(secondNumber,printSecondNumber,10);							
								Display.gotoXY(0,0);
								Display.drawArrowUp();
								Display.gotoXY(0,3);
								Display.writeString(printFirstNumber);
								Display.gotoXY(1,3);
								Display.writeString(" + ");
								Display.gotoXY(4,3);
								Display.writeString(printSecondNumber);
								Display.gotoXY(0,7);
								Display.drawArrowDown();
								break;
							case 7:
								itoa(firstNumber,printFirstNumber,10);
								itoa(secondNumber,printSecondNumber,10);
								Display.gotoXY(0,0);
								Display.drawArrowUp();
								Display.gotoXY(0,3);
								Display.writeString(printFirstNumber);
								Display.gotoXY(1,3);
								Display.writeString(" + ");
								Display.gotoXY(4,3);
								Display.writeString(printSecondNumber);
								Display.gotoXY(0,7);
								Display.drawArrowDown();
								break;
							case 8:
								itoa(firstNumber,printFirstNumber,10);
								itoa(secondNumber,printSecondNumber,10);
								Display.gotoXY(0,0);
								Display.drawArrowUp();
								Display.gotoXY(0,3);
								Display.writeString(printFirstNumber);
								Display.gotoXY(1,3);
								Display.writeString(" + ");
								Display.gotoXY(4,3);
								Display.writeString(printSecondNumber);
								Display.gotoXY(0,7);
								Display.drawArrowDown();
								break;
							case 9:
								itoa(firstNumber,printFirstNumber,10);
								itoa(secondNumber,printSecondNumber,10);
								Display.gotoXY(0,0);
								Display.drawArrowUp();
								Display.gotoXY(0,3);
								Display.writeString(printFirstNumber);
								Display.gotoXY(1,3);
								Display.writeString(" + ");
								Display.gotoXY(4,3);
								Display.writeString(printSecondNumber);
								Display.gotoXY(0,7);
								Display.drawArrowDown();
								break;
						}
						
						wdt_reset(); //watch dog 8s reset, damit er in der Schleife bleibt und nicht der ISR(WDT_vect) (unten Definiert) auslöst. 
					}
					while(!Display.clrScreen()) Display.restart();
					set = false;
				}
				break;
			case 1:
				Display.gotoXY(14,0);
				Display.drawArrowUp();
				Display.gotoXY(0,3);
				Display.writeString(SysLanguage.getSettingslang_3());  //MENÜ-EINSTELLUNG
				Display.gotoXY(14,7);
				Display.drawArrowDown();
				if ( BUTTONS::Rechts.isActivated()) //Nur Taste Rechts [OK] 
				{
					uint8_t stateParameter = 0;
					while(!Display.clrScreen()) Display.restart();
					while(!set)
					{
						if (BUTTONS::Oben.isActivated()) 
						{
							stateParameter++;
							if (stateParameter > 1)
							{
								stateParameter = 0;
							}
							while(!Display.clrScreen()) Display.restart();	
						}
						if (BUTTONS::Unten.isActivated() ) 
						{
							if (stateParameter >= 1){stateParameter--;}
							else{stateParameter=1;}
							while(!Display.clrScreen()) Display.restart();
						}
						if (BUTTONS::Links.isActivated())
						{
							set=true;
							while(!Display.clrScreen()) Display.restart();
						}
						if (BUTTONS::Rechts.isActivated())
						{	
							uint8_t state_sprach = 0;
							while(!Display.clrScreen()) Display.restart();
							switch (stateParameter)
							{
							case 0:
								while(!set)
								{
									Display.gotoXY(14,0);
									Display.drawArrowUp();
									Display.gotoXY(0,3);
									Display.writeString(SysLanguage.getInfo_1());//Informationen in Info anzeigen
									Display.gotoXY(0,4);
									Display.writeString(SysLanguage.getInfo_2());
									Display.gotoXY(14,7);
									Display.drawArrowDown();
									if (BUTTONS::Links.isActivated())
									{
										set=true; 
										while(!Display.clrScreen()) Display.restart();
									}

								}
								set=false;
								break;
							case 1: 
								while(!set)
								{
									if (BUTTONS::Oben.isActivated()) 
									{
										if(state_sprach <=2){state_sprach++;}
										else{state_sprach=0;}
										while(!Display.clrScreen()) Display.restart();
										
									}
									if (BUTTONS::Unten.isActivated()) 
									{
										if (state_sprach >= 1){state_sprach--;}
										else{state_sprach=3;}
										while(!Display.clrScreen()) Display.restart();
									}
									if (BUTTONS::Links.isActivated())
									{
										while(!Display.clrScreen()) Display.restart();
										set=true;        //sprache---->einsteluung
									}
									if (BUTTONS::Rechts.isActivated())
									{
										switch(state_sprach)
										{
											case 0: 
												SysLanguage.setEnglish();
												break;
											case 1: 
												SysLanguage.setGerman();
												break;
											case 2: 
												SysLanguage.setFrench();
												break;
											case 3:
												SysLanguage.setSpanish();
												break;
										}	

										eeprom_write_byte((uint8_t*) 1000, state_sprach); //speichern der Wert von State_sprache in diespeicherzelle 1000 , die sprache wird oben gesetzt
										set=true;  //kommt züruck zu einstellung
									}
									switch (state_sprach)
									{
										case 0:
											Display.gotoXY(14,0);
											Display.drawArrowUp();
											Display.gotoXY(0,3);
											Display.writeString(SysLanguage.getEnglish());  
											Display.gotoXY(14,7);
											Display.drawArrowDown();
											break;
										case 1:
											Display.gotoXY(14,0);
											Display.drawArrowUp();
											Display.gotoXY(0,3);
											Display.writeString(SysLanguage.getGerman());  
											Display.gotoXY(14,7);
											Display.drawArrowDown();
											break;
										case 2:
											Display.gotoXY(14,0);
											Display.drawArrowUp();
											Display.gotoXY(0,3);
											Display.writeString(SysLanguage.getFrench());  
											Display.gotoXY(14,7);
											Display.drawArrowDown();
											break;	
										case 3:
											Display.gotoXY(14,0);
											Display.drawArrowUp();
											Display.gotoXY(0,3);
											Display.writeString(SysLanguage.getSpanish());  
											Display.gotoXY(14,7);
											Display.drawArrowDown();
											break;								
									}
									wdt_reset();
								}
								set=false;
								break;
							}
						}
						switch (stateParameter)
						{
							case 0:
								Display.gotoXY(14,0);
								Display.drawArrowUp();
								Display.gotoXY(0,3);
								Display.writeString(SysLanguage.getInfo());  //INFO-MENÜ
								Display.gotoXY(14,7);
								Display.drawArrowDown();
								break;
							case 1:
								Display.gotoXY(14,0);
								Display.drawArrowUp();
								Display.gotoXY(0,3);
								Display.writeString(SysLanguage.getSettingslang_1());//SPRACHE-MENÜ
								Display.gotoXY(0,4);
								Display.writeString(SysLanguage.getSettingslang_2());
								Display.gotoXY(14,7);
								Display.drawArrowDown();
								break;
						}
						wdt_reset(); //watch dog 8s reset  
					}
					while(!Display.clrScreen()) Display.restart();
					set=false;
				}
				break;
			case 2:
				Display.gotoXY(14,0);
				Display.drawArrowUp();
				Display.gotoXY(0,3);
				Display.writeString(SysLanguage.getSavedvalues_1()); //MENÜ-SavedValueD_DATA
				Display.gotoXY(0,4);
				Display.writeString(SysLanguage.getSavedvalues_2());
				Display.gotoXY(14,7);
				Display.drawArrowDown();
				if ( BUTTONS::Rechts.isActivated())
				{  
					while(!Display.clrScreen()) Display.restart();
					while(!set)
					{
						Display.gotoXY(0,3);
						Display.writeString(SysLanguage.getSaved1());
						Display.gotoXY(12,3);
						itoa(savedMeasuredValue[0], printSavedValue1,10);
						Display.writeString(printSavedValue1);    
						Display.gotoXY(0,4);
						Display.writeString(SysLanguage.getSaved2());
						Display.gotoXY(12,4);
						itoa(savedMeasuredValue[1], printSavedValue2,10);
						Display.writeString(printSavedValue2);
						Display.gotoXY(0,5);
						Display.writeString(SysLanguage.getSaved3());
						Display.gotoXY(12,5);
						itoa(savedMeasuredValue[2], printSavedValue3,10);
						Display.writeString(printSavedValue3);
						if(BUTTONS::Links.isPressed())
						{
							 set=true;
							 while(!Display.clrScreen()) Display.restart();
							 }
						wdt_reset();
					}
					set= false;
				}
				break;
				
		}
		wdt_reset();
    }
}

ISR(TIMER0_OVF_vect)
{
    TIMER::Hz0.resetPreload();
    static uint16_t timer_overflow_counter_Mitte;
	static uint16_t timer_overflow_counter_Links;
	static uint16_t timer_overflow_counter_Rechts;
	static uint16_t timer_overflow_counter_Oben;
	static uint16_t timer_overflow_counter_Unten;
   
	if (BUTTONS::Mitte.isPressed())  
		{timer_overflow_counter_Mitte++; }
	if ((timer_overflow_counter_Mitte >= 100) && (BUTTONS::Mitte.isNotPressed()))
		{
			timer_overflow_counter_Mitte= 0;
			BUTTONS::Mitte.activate();

			BUTTONS::Links.deactivate();
			BUTTONS::Rechts.deactivate();
			BUTTONS::Oben.deactivate();
			BUTTONS::Unten.deactivate();
		}


	if (BUTTONS::Links.isPressed())  
		{timer_overflow_counter_Links++;}
	if ((timer_overflow_counter_Links >= 100) && BUTTONS::Links.isNotPressed())
		{
			timer_overflow_counter_Links= 0;
			BUTTONS::Links.activate();

			BUTTONS::Mitte.deactivate();
			BUTTONS::Rechts.deactivate();
			BUTTONS::Oben.deactivate();
			BUTTONS::Unten.deactivate();
		}
	if((timer_overflow_counter_Links >= 2000)) //2000
	{
		Display.clrScreen(); 
		PORTS::Selfretention.setLow();
	}



	if (BUTTONS::Oben.isPressed())  
		{timer_overflow_counter_Oben++;
					}
	if ((timer_overflow_counter_Oben >= 100) && BUTTONS::Oben.isNotPressed())
		{
			timer_overflow_counter_Oben= 0;
			BUTTONS::Oben.activate();

			BUTTONS::Mitte.deactivate();
			BUTTONS::Links.deactivate();
			BUTTONS::Rechts.deactivate();
			BUTTONS::Unten.deactivate();
		}




	if (BUTTONS::Unten.isPressed())  
		{timer_overflow_counter_Unten++; }
	if ((timer_overflow_counter_Unten >= 100) && BUTTONS::Unten.isNotPressed())
		{
			timer_overflow_counter_Unten= 0;
			BUTTONS::Unten.activate();

			BUTTONS::Mitte.deactivate();
			BUTTONS::Links.deactivate();
			BUTTONS::Rechts.deactivate();
			BUTTONS::Oben.deactivate(); 
			
		}
	

	if (BUTTONS::Rechts.isPressed())  
		{timer_overflow_counter_Rechts++; }
	if ((timer_overflow_counter_Rechts >= 100) && BUTTONS::Rechts.isNotPressed())
		{
			timer_overflow_counter_Rechts = 0;
			BUTTONS::Rechts.activate();

			BUTTONS::Mitte.deactivate();
			BUTTONS::Links.deactivate();
			BUTTONS::Unten.deactivate();
			BUTTONS::Oben.deactivate();
		}
}
ISR(WDT_vect)
{
	PORTS::Selfretention.setLow();
}