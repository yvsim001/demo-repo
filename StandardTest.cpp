#include <avr/io.h>
#include <avr/wdt.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <string.h>

#include "StandardTest.hpp"

StandardTest::StandardTest(uint8_t ca, OutputPort &c, OutputPort &sb, OutputPort &sc, Language &lang, Pwm &pwm, Button &cancel, Button &stop, Button &ok, Phase &l1, Phase &l2, Phase &l3, RotatingField &field, Number &turnoff, Timer &turnofftimer, SSD1309 &display) : cable_val(ca), Cable(c), StateB(sb), StateC(sc), SysLanguage(lang), PWM(pwm), Stop(stop), Cancel(cancel), Ok(ok), L1(l1), L2(l2), L3(l3), Field(field), TurnoffTime(turnoff), TurnoffTimer(turnofftimer), Display(display) {	
	turnoff_time = 0;
	res_state_a = false;
	res_state_b = false;
	res_state_c = false;
	res_phases = false;
	res_turnoff = false;
	test_passed = false;
}

void StandardTest::printResult(bool s){
	if(s){Display.writeString(SysLanguage.getOk1());}
	else{Display.writeString(SysLanguage.getFail1());}
}
void StandardTest::printWaiting(bool s){
	if(s){Display.writeString(SysLanguage.getWaiting1());}
	else{
		if(SysLanguage.getLanguage() == 2) Display.writeString("        ");
		else Display.writeString("       ");
	}
}
void StandardTest::printRunning(bool s){
	if(s){Display.writeString(SysLanguage.getRunning1());}
	else{
		if(SysLanguage.getLanguage() == 2) Display.writeString("        ");
		else Display.writeString("       ");
	}
}

void StandardTest::performTest(){
	test_passed = true;
	Cable.setHigh();
	cancel = false;
	new_auth = false;  

	res_state_a = false;
	state_a_pos_vol = 99.0;
	state_a_neg_vol = 99.0;
	state_a_fre = 99;
	state_a_dc = 99;
	state_a_curr = 99;

	res_state_b = false;
	state_b_pos_vol = 99.0;
	state_b_neg_vol = 99.0;
	state_b_fre = 99;
	state_b_dc = 99;
	state_b_curr = 99;

	res_state_c = false;
	state_c_pos_vol = 99.0;
	state_c_neg_vol = 99.0;
	state_c_fre = 99;
	state_c_dc = 99;
	state_c_curr = 99;

	res_phases = false;
	phases_l1 = false;
	phases_l2 = false;
	phases_l3 = false;
	phases_fielddir = 0;

	res_turnoff = false;
	turnoff_time = 9999;

	Display.clrScreen();
	Display.gotoXY(0,0);
	Display.writeString(SysLanguage.getStatea());
	Display.writeString(SysLanguage.getWaiting1());
	Display.gotoXY(0,1);
	Display.writeString(SysLanguage.getStateb());
	Display.writeString(SysLanguage.getWaiting1());
	Display.gotoXY(0,2);
	Display.writeString(SysLanguage.getStatec());
	Display.writeString(SysLanguage.getWaiting1());
	Display.gotoXY(0,3);
	Display.writeString(SysLanguage.getPhases());
	Display.writeString(SysLanguage.getWaiting1());
	Display.gotoXY(0,4);
	Display.writeString(SysLanguage.getTurnoff());
	Display.writeString(SysLanguage.getWaiting1());

	testPwmValues(STATES::A);

	if(!cancel){
		if(SysLanguage.getLanguage() == 2) Display.gotoXY(8,0);
		else Display.gotoXY(9,0);

		printResult(res_state_a);

		StateB.setHigh();

		testPwmValues(STATES::B);

		if(!cancel){
			if(new_auth){

				bool set = false;
				bool test = false;

				Display.clrScreen();
				Display.gotoXY(0,1);
				Display.writeString(SysLanguage.getAuth_1());
				Display.gotoXY(0,3);
				Display.writeString(SysLanguage.getAuth_2());
				Display.gotoXY(0,4);
				Display.writeString(SysLanguage.getAuth_3());

				Display.gotoXY(0,6);
				Display.writeString(SysLanguage.getYes());
				Display.gotoXY(0,7);
				Display.writeString(SysLanguage.getNo());

				while(!set){
					if(Cancel.isActivated()){set = true;}
					if(Ok.isActivated()){
						set = true;
						test = true;
					}
					wdt_reset();
				}

				if(test){
					Display.clrScreen();
					Display.gotoXY(0,3);
					Display.writeString(SysLanguage.getPreparation_2());
					Display.gotoXY(0,7);
					Display.writeString(SysLanguage.getNext());

					while(Ok.isNotActivated()){wdt_reset();}	
				}
			
				Display.clrScreen();
				Display.gotoXY(0,0);
				Display.writeString(SysLanguage.getStatea());
				if(SysLanguage.getLanguage() == 2) Display.gotoXY(8,0);
				else Display.gotoXY(9,0);
				printResult(res_state_a);
				Display.gotoXY(0,1);
				Display.writeString(SysLanguage.getStateb());
				Display.gotoXY(0,2);
				Display.writeString(SysLanguage.getStatec());
				Display.writeString(SysLanguage.getWaiting1());
				Display.gotoXY(0,3);
				Display.writeString(SysLanguage.getPhases());
				Display.writeString(SysLanguage.getWaiting1());
				Display.gotoXY(0,4);
				Display.writeString(SysLanguage.getTurnoff());
				Display.writeString(SysLanguage.getWaiting1());

				if(test){
					testPwmValues(STATES::B);
					new_auth = false;
				}
			}
			if(SysLanguage.getLanguage() == 2) Display.gotoXY(8,1);
			else Display.gotoXY(9,1);

			printResult(res_state_b);	

			StateC.setHigh();

			testPwmValues(STATES::C);
			
			if(!cancel){
				if(SysLanguage.getLanguage() == 2) Display.gotoXY(8,2);
				else Display.gotoXY(9,2);

				printResult(res_state_c);

				testPhases();

				if(!cancel){
					if(SysLanguage.getLanguage() == 2) Display.gotoXY(8,3);
					else Display.gotoXY(9,3);
					printResult(res_phases);

					testTurnoff();

					if(SysLanguage.getLanguage() == 2) Display.gotoXY(8,4);
					else Display.gotoXY(9,4);
					printResult(res_turnoff);
				}
			}
		}
		if(!res_state_a || !res_state_b || !res_state_c || !res_phases || !res_turnoff){test_passed = false;}
		
		StateB.setLow();
		StateC.setLow();
		Cable.setLow();
	}
}

void StandardTest::testPwmValues(uint8_t state){
	uint8_t counter_fails = 0;
									
	done = false;

	switch (state)
	{
	case STATES::A: 
				while (!done){
					if(Cancel.isActivated() || Stop.isActivated()){
						Cancel.deactivate();
						Stop.deactivate();
						cancel = true;
						step = false;
						done = true;
						run = false;
						started = false;
					}
					run = true;

					if(step){
						step = false;

						state_a_pos_vol = PWM.getPosVoltage();
						state_a_neg_vol = PWM.getNegVoltage();
						state_a_fre = PWM.getFrequency();
						state_a_dc = PWM.getDutyCycle();
						state_a_curr = PWM.getCurrent();

						if(state_a_pos_vol > 11){started = true;}

						if(SysLanguage.getLanguage() == 2) Display.gotoXY(8,0);
						else Display.gotoXY(9,0); 

						if(!started){printWaiting(show);}
						else{
							printRunning(show);

							if(state_a_curr > 0 || state_a_fre > 0 || state_a_neg_vol > 0 || state_a_pos_vol > 13 || state_a_pos_vol < 11){counter_fails++;}

							if(counter_fails >= 3){
								res_state_a = false;

								counter = 0;
								step = false;
								done = true;
								run = false;
								started = false;

								return;
							}
							else res_state_a = true;
						}
					}
					wdt_reset();
				}
			break;
	case STATES::B: 
				while (!done){
					if(Cancel.isActivated() || Stop.isActivated()){
						Cancel.deactivate();
						Stop.deactivate();
						cancel = true;
						step = false;
						done = true;
						run = false;
						started = false;
					}
					run = true;

					if(step){
						step = false;

						state_b_pos_vol = PWM.getPosVoltage();
						state_b_neg_vol = PWM.getNegVoltage();
						state_b_fre = PWM.getFrequency();
						state_b_dc = PWM.getDutyCycle();
						state_b_curr = PWM.getCurrent();

						if(state_b_pos_vol < 10 && state_b_neg_vol > 11){started = true;}
				
						if(SysLanguage.getLanguage() == 2) Display.gotoXY(8,1);
						else Display.gotoXY(9,1); 

						if(!started){printWaiting(show);}
						else{
							printRunning(show);

							if(state_b_fre == 0 && state_b_dc == 0 && state_b_pos_vol < 10 && state_b_pos_vol > 8 && res_state_a && !new_auth){
								new_auth = true;

								res_state_b = false;

								counter = 0;
								step = false;
								done = true;
								run = false;
								started = false;
								
								return;
							}

							if(state_b_curr > cable_val || state_b_fre > 1100 || state_b_fre < 900 || state_b_neg_vol > 13 || state_b_neg_vol < 11 || state_b_pos_vol > 10 || state_b_pos_vol < 8){counter_fails++;}

							if(counter_fails >= 3){
								res_state_b = false;
								
								counter = 0;
								res_state_b = false;
								step = false;
								done = true;
								run = false;
								started = false;

								return;
							}
							else res_state_b = true; 
						}		
					}
					wdt_reset();
				}
		break;
	case STATES::C: 
				while (!done){
					if(Cancel.isActivated() || Stop.isActivated()){
						Cancel.deactivate();
						Stop.deactivate();
						cancel = true;
						step = false;
						done = true;
						run = false;
						started = false;
					}
					run = true;

					if(step){
						step = false;

						state_c_pos_vol = PWM.getPosVoltage();
						state_c_neg_vol = PWM.getNegVoltage();
						state_c_fre = PWM.getFrequency();
						state_c_dc = PWM.getDutyCycle();
						state_c_curr = PWM.getCurrent();

						if(state_c_pos_vol < 7 && state_c_neg_vol > 11){started = true;}

						if(SysLanguage.getLanguage() == 2) Display.gotoXY(8,2);
						else Display.gotoXY(9,2); 

						if(!started){printWaiting(show);}
						else{
							printRunning(show);

							if(state_c_curr > cable_val || state_c_fre > 1100 || state_c_fre < 900 || state_c_pos_vol > 7 || state_c_pos_vol < 5 || state_c_neg_vol > 13 || state_c_neg_vol < 11){counter_fails++;}

							if(counter_fails >= 3){
								res_state_c = false;
								
								counter = 0;
								step = false;
								done = true;
								run = false;
								started = false;

								return;
							}
							else res_state_c = true; 
						}
					}
					wdt_reset();
				}
		break;
	}
}

void StandardTest::testPhases(){
	done = false;

	while(!done){
		if(Cancel.isActivated() || Stop.isActivated()){
			Cancel.deactivate();
			Stop.deactivate();
			cancel = true;
			step = false;
			done = true;
			run = false;
			started = false;
		}
		run = true;

		if(step){
			step = false;

			if(L1.getDetected()){started = true;}

			if(SysLanguage.getLanguage() == 2) Display.gotoXY(8,3);
			else Display.gotoXY(9,3); 

			if(!started){printWaiting(show);}
			else{
				printRunning(show);

				if(L1.getDetected() || (L1.getDetected() && L2.getDetected() && L3.getDetected())){res_phases = true;}
				else{res_phases = false;}
				phases_l1 = L1.getDetected();
				phases_l2 = L2.getDetected();
				phases_l3 = L3.getDetected();
				phases_fielddir = Field.getRotation();
			}
		}
		wdt_reset();
	}
}

void StandardTest::testTurnoff() {
	bool phases = false;

	if(L1.isActive() || L2.isActive() || L3.isActive()){phases = true;}

	StateB.setLow();
	StateC.setLow();

	TurnoffTime.resetNumber();
	TurnoffTimer.activate();
	TurnoffTime.resetReady();

	while(TurnoffTime.isNotReady()){wdt_reset();}

	if(phases){
		turnoff_time = TurnoffTime.getNumber();
		if(turnoff_time < 100){res_turnoff = true;}
		else{res_turnoff = false;}
	}
	else {
		turnoff_time = 5000;
		res_turnoff = false;
	}
}

uint8_t StandardTest::getCable() const{
	return cable_val;
}

bool StandardTest::getResA() const {
	return res_state_a;
}

bool StandardTest::getResB() const {
	return res_state_b;
}

bool StandardTest::getResC() const {
	return res_state_c;
}

bool StandardTest::getResPhases() const {
	return res_phases;
}

bool StandardTest::getResTurnoff() const {
	return res_turnoff;
}

bool StandardTest::getResPassed() const {
	return test_passed;
}

double StandardTest::getAPos() const{
	return state_a_pos_vol;
}
double StandardTest::getANeg() const{
	return state_a_neg_vol;
}
uint16_t StandardTest::getAFre() const{
	return state_a_fre;
}
uint16_t StandardTest::getADc() const{
	return state_a_dc;
}
uint8_t StandardTest::getACurr() const{
	return state_a_curr;
}

double StandardTest::getBPos() const{
	return state_b_pos_vol;
}
double StandardTest::getBNeg() const{
	return state_b_neg_vol;
}
uint16_t StandardTest::getBFre() const{
	return state_b_fre;
}
uint16_t StandardTest::getBDc() const{
	return state_b_dc;
}
uint8_t StandardTest::getBCurr() const{
	return state_b_curr;
}

double StandardTest::getCPos() const{
	return state_c_pos_vol;
}
double StandardTest::getCNeg()const{
	return state_c_neg_vol;
}
uint16_t StandardTest::getCFre() const{
	return state_c_fre;
}
uint16_t StandardTest::getCDc() const{
	return state_c_dc;
}
uint8_t StandardTest::getCCurr() const{
	return state_c_curr;
}

bool StandardTest::getL1() const{
	return phases_l1;
}
bool StandardTest::getL2() const{
	return phases_l2;
}
bool StandardTest::getL3() const{
	return phases_l3;
}
uint8_t StandardTest::getField() const{
	return phases_fielddir;
}

uint16_t StandardTest::getTurnoff() const{
	return turnoff_time;
}

bool StandardTest::isDone() const{
	return done;
}
bool StandardTest::isNotDone() const{
	return !done;
}
void StandardTest::setDone(){
	done = true;
}
void StandardTest::setNotDone(){
	done = false;
}
bool StandardTest::isRunning() const{
	return run;
}
bool StandardTest::isNotRunning() const{
	return !run;
}
void StandardTest::setRun(){
	run = true;
}
void StandardTest::setNotRun(){
	run = false;
}
bool StandardTest::isShowing() const{
	return show;
}
bool StandardTest::isNotShowing() const{
	return !show;
}
void StandardTest::setShow(){
	show = true;
}
void StandardTest::setNotShow(){
	show = false;
}
void StandardTest::setStep(){
	step = true;
}
void StandardTest::setNotStep(){
	step = false;
}
bool StandardTest::isStarted() const{
	return started;
}
bool StandardTest::isNotStarted() const{
	return !started;
}
void StandardTest::setStarted(){
	started = true;
}
void StandardTest::setNotStarted(){
	started = false;
}
uint8_t StandardTest::getCounter() const{
	return counter;
}
void StandardTest::increaseCounter(){
	counter++;
}
void StandardTest::resetCounter(){
	counter = 0;
}
void StandardTest::setCounter(uint8_t c){
	counter = c;
}

void StandardTest::setCable(uint8_t cable){
	cable_val = cable;
}

void StandardTest::setResA(bool res_a) {
	res_state_a = res_a;
}

void StandardTest::setResB(bool res_b) {
	res_state_b = res_b;
}

void StandardTest::setResC(bool res_c) {
	res_state_c = res_c;
}

void StandardTest::setResPhases(bool res) {
	res_phases = res;
}

void StandardTest::setResTurnoff(bool res) {
	res_turnoff = res;
}

void StandardTest::setResPassed(bool res_passed) {
	test_passed = test_passed;
}

void StandardTest::setAPos(double a_pos){
	state_a_pos_vol = a_pos;
}
void StandardTest::setANeg(double a_neg){
	state_a_neg_vol = a_neg;
}
void StandardTest::setAFre(uint16_t a_fre){
	state_a_fre = a_fre;
}
void StandardTest::setADc(uint16_t a_dc){
	state_a_dc = a_dc;
}
void StandardTest::setACurr(uint8_t a_curr){
	state_a_curr = a_curr;
}

void StandardTest::setBPos(double b_pos){
	state_b_pos_vol = b_pos;
}
void StandardTest::setBNeg(double b_neg){
	state_b_neg_vol = b_neg;
}
void StandardTest::setBFre(uint16_t b_fre){
	state_b_fre = b_fre;
}
void StandardTest::setBDc(uint16_t b_dc){
	state_b_dc = b_dc;
}
void StandardTest::setBCurr(uint8_t b_curr){
	state_b_curr = b_curr;
}

void StandardTest::setCPos(double c_pos){
	state_c_pos_vol = c_pos;
}
void StandardTest::setCNeg(double c_neg){
	state_c_neg_vol = c_neg;
}
void StandardTest::setCFre(uint16_t c_fre){
	state_c_fre = c_fre;
}
void StandardTest::setCDc(uint16_t c_dc){
	state_c_dc = c_dc;
}
void StandardTest::setCCurr(uint8_t c_curr){
	state_c_curr = c_curr;
}

void StandardTest::setL1(bool l1){
	phases_l1 = l1;
}
void StandardTest::setL2(bool l2){
	phases_l2 = l2;
}
void StandardTest::setL3(bool l3){
	phases_l3 = l3;
}
void StandardTest::setField(uint8_t field){
	phases_fielddir = field;
}

void StandardTest::setTurnoff(uint16_t turnoff){
	 turnoff_time = turnoff;
}