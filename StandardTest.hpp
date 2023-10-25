#pragma once

#include "Language.hpp"
#include "Pwm.hpp"
#include "Button.hpp"
#include "Phase.hpp"
#include "RotatingField.hpp"
#include "Number.hpp"
#include "Timer.hpp"
#include "OutputPort.hpp"
#include "SSD1309.hpp"

class StandardTest {
    public:
        StandardTest(uint8_t ca, OutputPort &c, OutputPort &sb, OutputPort &sc, Language &lang, Pwm &pwm, Button &cancel, Button &stop, Button &ok, Phase &l1, Phase &l2, Phase &l3, RotatingField &field, Number &turnoff, Timer &turnofftimer, SSD1309 &display);
        void performTest();
        bool isDone() const;
        bool isNotDone() const;
        void setDone();
        void setNotDone();
        bool isRunning() const;
        bool isNotRunning() const;
        void setRun();
        void setNotRun();
        bool isShowing() const;
        bool isNotShowing() const;
        void setShow();
        void setNotShow();
        void setStep();
        void setNotStep();
        bool isStarted() const;
        bool isNotStarted() const;
        void setStarted();
        void setNotStarted();



        uint8_t getCable() const;
        bool getResA() const;
        bool getResB() const;
        bool getResC() const;
        bool getResPhases() const;
        bool getResTurnoff() const;
        bool getResPassed() const;

        double getAPos() const;
        double getANeg() const;
        uint16_t getAFre() const;
        uint16_t getADc() const;
        uint8_t getACurr() const;

        double getBPos() const;
        double getBNeg() const;
        uint16_t getBFre() const;
        uint16_t getBDc() const;
        uint8_t getBCurr() const;

        double getCPos() const;
        double getCNeg() const;
        uint16_t getCFre() const;
        uint16_t getCDc() const;
        uint8_t getCCurr() const;

        bool getL1() const;
        bool getL2() const;
        bool getL3() const;
        uint8_t getField() const;

        uint16_t getTurnoff() const;

        uint8_t getCounter() const;
        void increaseCounter();
        void resetCounter();
        void setCounter(uint8_t c);

        void setCable(uint8_t cable);

        void setResA(bool res_a);
        void setResB(bool res_b);
        void setResC(bool res_c);
        void setResPhases(bool res);
        void setResTurnoff(bool res);
        void setResPassed(bool res_passed);

        void setAPos(double a_pos);
        void setANeg(double a_neg);
        void setAFre(uint16_t a_fre);
        void setADc(uint16_t a_dc);
        void setACurr(uint8_t a_curr);

        void setBPos(double b_pos);
        void setBNeg(double b_neg);
        void setBFre(uint16_t b_fre);
        void setBDc(uint16_t b_dc);
        void setBCurr(uint8_t b_curr);

        void setCPos(double c_pos);
        void setCNeg(double c_neg);
        void setCFre(uint16_t c_fre);
        void setCDc(uint16_t c_dc);
        void setCCurr(uint8_t c_curr);

        void setL1(bool l1);
        void setL2(bool l2);
        void setL3(bool l3);
        void setField(uint8_t field);

        void setTurnoff(uint16_t turnoff);



    private:
        enum STATES {
            A,
            B,
            C
        };
        uint8_t cable_val;
        OutputPort &Cable;
        OutputPort &StateB;
        OutputPort &StateC;
        Language &SysLanguage;
        Pwm &PWM;
        Button &Stop;
        Button &Cancel;
        Button &Ok;
        Phase &L1;
        Phase &L2;
        Phase &L3;
        RotatingField &Field;
        Number &TurnoffTime;
        Timer &TurnoffTimer;
        SSD1309 &Display;

        volatile bool done;
        volatile bool cancel;
        bool new_auth;
        volatile bool step;
        volatile bool run;
        volatile bool started;
        volatile bool show;

        bool test_passed;

        bool res_state_a;
        double state_a_pos_vol;
        double state_a_neg_vol;
        uint16_t state_a_fre;
        uint16_t state_a_dc;
        uint8_t state_a_curr;

        bool res_state_b;
        double state_b_pos_vol;
        double state_b_neg_vol;
        uint16_t state_b_fre;
        uint16_t state_b_dc;
        uint8_t state_b_curr;

        bool res_state_c;
        double state_c_pos_vol;
        double state_c_neg_vol;
        uint16_t state_c_fre;
        uint16_t state_c_dc;
        uint8_t state_c_curr;

        uint8_t counter;

        bool res_phases;
        bool phases_l1;
        bool phases_l2;
        bool phases_l3;
        uint8_t phases_fielddir;

        bool res_turnoff;
        volatile uint16_t turnoff_time;

        void testPwmValues(uint8_t state);
        void testPhases();
        void testTurnoff();
        void printResult(bool s);
        void printWaiting(bool s);
        void printRunning(bool s);
};