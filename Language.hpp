#pragma once

class Language {
    public:
        Language();
        uint8_t getLanguage();
        void setEnglish();
        void setGerman();
        void setFrench();
        void setSpanish();

        const char* getStandardtest_1() const;
        const char* getStandardtest_2() const;
        const char* getStateetest_1() const;
        const char* getStateetest_2() const;
        const char* getPreparation_1() const;
        const char* getPreparation_2() const;
        const char* getNext() const;
        const char* getCancel() const;
        const char* getTest_ended() const;
        const char* getFinish() const;
        const char* getDetails() const;
        const char* getWantsave() const;
        const char* getYes() const;
        const char* getNo() const;
        const char* getSavedvalues_1() const;
        const char* getSavedvalues_2() const;
        const char* getSettingslang_1() const;
        const char* getSettingslang_2() const;
        const char* getEnglish() const;
        const char* getGerman() const;
        const char* getFrench() const;
        const char* getSave() const;

        const char* getStatea() const;
        const char* getStateb() const;
        const char* getStatec() const;
        const char* getStated() const;
        const char* getPhases() const;
        const char* getTurnoff() const;

        const char* getPosvol() const;
        const char* getNegvol() const;
        const char* getFre() const;
        const char* getDc() const;
        const char* getCur() const;

        const char* getPhase1() const;
        const char* getPhase2() const;
        const char* getPhase3() const;
        const char* getRot() const;

        const char* getTime() const;

        const char* getLeft() const;
        const char* getRight() const;
        const char* getOn() const;
        const char* getOff() const;

        const char* getOk() const;
        const char* getFail() const;
        const char* getOk1() const;
        const char* getFail1() const;

        const char* getWaiting1() const;
        const char* getRunning1() const;
        const char* getWaiting2() const;
        const char* getRunning2() const;

        const char* getTest_failed() const;
        const char* getTest_32_1() const;
        const char* getTest_32_2() const;

        const char* getTest_cable() const;
        const char* getTest_details() const;

        const char* getCharging1() const;
        const char* getCharging2() const;

        const char* getBattery_low1() const;
        const char* getBattery_low2() const;
        const char* getBattery_low3() const;
        const char* getBattery_ok() const;

        const char* getAuth_1() const;
        const char* getAuth_2() const;
        const char* getAuth_3() const;

        const char* getData_lost1() const;
        const char* getData_lost2() const;

        /// 
        const char* getInfo() const;
        const char* getInfo_1() const;
        const char* getInfo_2() const;

        const char* getSaved1() const;
        const char* getSaved2() const;
        const char* getSaved3() const;

        const char* getmessung() const;

        const char* getSpanish() const;

        const char* getSettingslang_3() const;

        
    private:
        uint8_t lang_state;
};
