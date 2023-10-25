#include <avr/io.h>
#include <avr/eeprom.h>
#include <string.h>

#include "Language.hpp"

namespace language 
{
    namespace german
    {
        constexpr const char* standardtest_1  =   "      TEST      ";
        constexpr const char* standardtest_2  =   " STANDARD (20A) ";
        constexpr const char* preparation_1   =   " STECKER STECKEN";
        constexpr const char* preparation_2   =   "  AUTORISIEREN  ";
        constexpr const char* next            =   "  OK = WEITER   ";
        constexpr const char* cancel          =   " ESC = ABBRUCH  ";
        constexpr const char* test_ended      =   "  TEST BEENDET  ";
        constexpr const char* finish          =   " ESC = BEENDEN  ";
        constexpr const char* details         =   "  OK = DETAILS  ";
        constexpr const char* wantsave        =   "WERTE SPEICHERN?";
        constexpr const char* yes             =   "     OK = JA    ";
        constexpr const char* no              =   "    ESC = NEIN  ";
        constexpr const char* stateetest_1    =   "      TEST      ";
        constexpr const char* stateetest_2    =   "      CPPE      ";
        constexpr const char* savedvalues_1   =   "  GESPEICHERTE  ";
        constexpr const char* savedvalues_2   =   "     WERTE      ";
        constexpr const char* settingslang_1  =   "    SPRACHE     ";
        constexpr const char* settingslang_2  =   "   EINSTELLEN   ";
        constexpr const char* english         =   "    ENGLISCH    ";
        constexpr const char* german          =   "    DEUTSCH     ";
        constexpr const char* french          =   "  FRANZOESISCH  ";
        constexpr const char* save            =   " OK = SPEICHERN ";

        constexpr const char* statea          =   "STATUS A:";
        constexpr const char* stateb          =   "STATUS B:";
        constexpr const char* statec          =   "STATUS C:";
        constexpr const char* stated          =   "STATUS D:";
        constexpr const char* phases          =   "PHASEN:  ";
        constexpr const char* turnoff         =   "tAUS:    ";

        constexpr const char* posvol          =   "SPANNUNG+: ";
        constexpr const char* negvol          =   "SPANNUNG-: ";
        constexpr const char* fre             =   "FREQUENZ:  ";
        constexpr const char* dc              =   "DUTY CYCLE:";
        constexpr const char* cur             =   "STROM:     ";

        constexpr const char* phase1          =   "L1:       ";
        constexpr const char* phase2          =   "L2:       ";
        constexpr const char* phase3          =   "L3:       ";
        constexpr const char* rot             =   "DREHFELD: ";

        constexpr const char* time            =   "ZEIT:     ";

        constexpr const char* right            =  "RECHTS";
        constexpr const char* left            =   "LINKS";
        constexpr const char* on              =   "AN";
        constexpr const char* off             =   "AUS";

        constexpr const char* ok              =   " OK  ";
        constexpr const char* fail            =   " --  ";
        constexpr const char* ok1             =   " OK    ";
        constexpr const char* fail1           =   " --    ";

        constexpr const char* waiting1          =   "WARTEN ";
        constexpr const char* running1          =   "TESTEN ";
        constexpr const char* waiting2          =   "WARTEN ";
        constexpr const char* running2          =   "TESTEN ";

        constexpr const char* test_failed       =   " NICHT BESTANDEN";
        constexpr const char* test_32_1         =   "  TEST MIT 32A  ";
        constexpr const char* test_32_2         =   " KABEL STARTEN?";

        constexpr const char* test_cable        =   "  KABEL: ";
        constexpr const char* test_details      =   "  TEST DETAILS  ";

        constexpr const char* charging1         =   "   KEIN TEST    ";
        constexpr const char* charging2         =   " BEIM AUFLADEN  ";

        constexpr const char* battery_low1      =   "  BATTERIESTAND ";
        constexpr const char* battery_low2      =   "     NIEDRIG    ";
        constexpr const char* battery_low3      =   " BITTE AUFLADEN ";
        constexpr const char* battery_ok        =   "  LADESTAND OK  ";

        constexpr const char* auth_1            =   " UNKLARE WERTE  ";           
        constexpr const char* auth_2            =   " AUTHORISIERUNG ";
        constexpr const char* auth_3            =   "   NOTWENDIG?   ";

        constexpr const char* data_lost1        =   "  DATEN LADEN   ";
        constexpr const char* data_lost2        =   " FEHLGESCHLAGEN ";

        //INFO
        constexpr const char* info              =   "      INFO      ";
        constexpr const char* info_1            =   "SOWFTARE VERSION";
        constexpr const char* info_2            =   "  2.0 (09/2023) ";

        //saved data
        constexpr const char* saved1          =   "  VALUE 1:  ";
        constexpr const char* saved2          =   "  VALUE 2:  ";
        constexpr const char* saved3          =   "  VALUE 3:  ";

        //Messung
        constexpr const char* messung          =   "    MESSUNG    ";

        //Sprache
        constexpr const char* spanish          =   "    SPANISH    ";

        //Einstellung
        constexpr const char* settingslang_3  =   "   EINSTELLUNG  ";
    }
    namespace english
    {
        constexpr const char* standardtest_1  =   "    FUNCTION    ";
        constexpr const char* standardtest_2  =   "	   TEST (20A)  ";
        constexpr const char* preparation_1   =   "  CONNECT PLUG  ";
        constexpr const char* preparation_2   =   "    AUTHORIZE   ";
        constexpr const char* next            =   "    OK = NEXT   ";
        constexpr const char* cancel          =   "   ESC = CANCEL ";
        constexpr const char* test_ended      =   "  TEST FINISHED ";
        constexpr const char* finish          =   "  ESC = FINISH  ";
        constexpr const char* details         =   "  OK = DETAILS  ";
        constexpr const char* wantsave        =   "   SAVE DATA?   ";
        constexpr const char* yes             =   "    OK = YES    ";
        constexpr const char* no              =   "    ESC = NO    ";
        constexpr const char* stateetest_1    =   "      TEST      ";
        constexpr const char* stateetest_2    =   "     STATE E    ";
        constexpr const char* savedvalues_1   =   "      SAVED     ";
        constexpr const char* savedvalues_2   =   "      DATA      ";
        constexpr const char* settingslang_1  =   "    LANGUAGE    ";
        constexpr const char* settingslang_2  =   "    SETTINGS    ";
        constexpr const char* english         =   "     ENGLISH    ";
        constexpr const char* german          =   "     GERMAN     ";
        constexpr const char* french          =   "     FRENCH     ";
        constexpr const char* save            =   "   OK = SAVE    ";

        constexpr const char* statea          =   "STATE A: ";
        constexpr const char* stateb          =   "STATE B: ";
        constexpr const char* statec          =   "STATE C: ";
        constexpr const char* stated          =   "STATE D: ";
        constexpr const char* phases          =   "PHASES:  ";
        constexpr const char* turnoff         =   "TURNOFF: ";

        constexpr const char* posvol          =   "VOLTAGE +: ";
        constexpr const char* negvol          =   "VOLTAGE -: ";
        constexpr const char* fre             =   "FREQUENCY: ";
        constexpr const char* dc              =   "DUTY CYCLE:";
        constexpr const char* cur             =   "CURRENT:   ";

        constexpr const char* phase1          =   "L1:      ";
        constexpr const char* phase2          =   "L2:      ";
        constexpr const char* phase3          =   "L3:      ";
        constexpr const char* rot             =   "ROTATION:";

        constexpr const char* time            =   "tOFF:    ";

        constexpr const char* right           =   "RIGHT";
        constexpr const char* left            =   "LEFT";
        constexpr const char* on              =   "ON";
        constexpr const char* off             =   "OFF";

        constexpr const char* ok              =   "OK   ";
        constexpr const char* fail            =   "--   ";
        constexpr const char* ok1             =   "OK     ";
        constexpr const char* fail1           =   "--     ";

        constexpr const char* waiting1        =   "WAITING";
        constexpr const char* running1        =   "RUNNING";
        constexpr const char* waiting2        =   "WAITING";
        constexpr const char* running2        =   "RUNNING";

        constexpr const char* test_failed     =   " 20A TEST FAILED";
        constexpr const char* test_32_1       =   " TEST 32A CABLE?";
        constexpr  const char* test_32_2       =   "                ";

        constexpr const char* test_cable      =   "  CABLE: ";
        constexpr const char* test_details    =   "  TEST DETAILS  ";

        constexpr const char* charging1       =   "     NO TEST    ";
        constexpr const char* charging2       =   " WHILE CHARGING ";

        constexpr const char* battery_low1    =   "  EMPTY BATTERY ";
        constexpr const char* battery_low2    =   "  PLEASE CHARGE ";
        constexpr const char* battery_low3    =   "     DEVICE     ";
        constexpr const char* battery_ok      =   "   BATTERY OK   ";

        constexpr const char* auth_1            =   " UNCLEAR VALUES ";           
        constexpr const char* auth_2            =   " AUTHORIZATION  ";
        constexpr const char* auth_3            =   "   NECESSARY?   ";

        constexpr const char* data_lost1        =   " FAILED TO LOAD ";
        constexpr const char* data_lost2        =   "      DATA      ";

        ///
        constexpr const char* info              =   "      INFO      ";
        constexpr const char* info_1            =   "SOWFTARE VERSION";
        constexpr const char* info_2            =   "  2.0 (09/2023) ";

        constexpr const char* saved1          =   "  VALUE 1:  ";
        constexpr const char* saved2          =   "  VALUE 2:  ";
        constexpr const char* saved3          =   "  VALUE 3:  ";
        
        constexpr const char* messung          =   "     MEASURE    ";

        constexpr const char* spanish          =   "     SPANISH    ";

        constexpr const char* settingslang_3  =   "    SETTINGS    ";
    }
    namespace french
    {
        constexpr const char* standardtest_1  =   "      TEST      ";
        constexpr const char* standardtest_2  =   "	STANDARD (20A) ";
        constexpr const char* preparation_1   =   " BRANCHER FICHE ";
        constexpr const char* preparation_2   =   "    AUTORISER   ";
        constexpr const char* next            =   " OK = CONTINUER ";
        constexpr const char* cancel          =   "ESC = ANNULATION";
        constexpr const char* test_ended      =   "  TEST TERMINE  ";
        constexpr const char* finish          =   " ESC = TERMINER ";
        constexpr const char* details         =   "  OK = DETAILS  ";
        constexpr const char* wantsave        =   "  ENREGISTRER?  ";
        constexpr const char* yes             =   "    OK = OUI    ";
        constexpr const char* no              =   "    ESC = NO    ";
        constexpr const char* stateetest_1    =   "      TEST      ";
        constexpr const char* stateetest_2    =   "     STATE E    ";
        constexpr const char* savedvalues_1   =   "    VALEURS     ";
        constexpr const char* savedvalues_2   =   "  ENREGISTREES  ";
        constexpr const char* settingslang_1  =   "     CHOISIR    ";
        constexpr const char* settingslang_2  =   "     LANGUE     ";
        constexpr const char* english         =   "     ANGLAIS    ";
        constexpr const char* german          =   "    ALLEMAND    ";
        constexpr const char* french          =   "    FRANCAIS    ";
        constexpr const char* save            =   "OK = ENREGISTRER";

        constexpr const char* statea          =   "ETAT A: ";
        constexpr const char* stateb          =   "ETAT B: ";
        constexpr const char* statec          =   "ETAT C: ";
        constexpr const char* stated          =   "ETAT D: ";
        constexpr const char* phases          =   "PHASES: ";
        constexpr const char* turnoff         =   "tArret: ";

        constexpr const char* posvol          =   "TENSION +: ";
        constexpr const char* negvol          =   "TENSION -: ";
        constexpr const char* fre             =   "FREQUENCE: ";
        constexpr const char* dc              =   "DUTY CYCLE:";
        constexpr const char* cur             =   "COURANT:   ";

        constexpr const char* phase1          =   "L1:      ";
        constexpr const char* phase2          =   "L2:      ";
        constexpr const char* phase3          =   "L3:      ";
        constexpr const char* rot             =   "ROTATION:";

        constexpr const char* time            =   "TEMPS:   ";

        constexpr const char* right           =   "DROITE";
        constexpr const char* left            =   "GAUCHE";
        constexpr const char* on              =   "ON";
        constexpr const char* off             =   "--";

        constexpr const char* ok              =   "OK   ";
        constexpr const char* fail            =   "--   ";
        constexpr const char* ok1             =   "OK      ";
        constexpr const char* fail1           =   "--      ";

        constexpr const char* waiting1        =   "ATTENDRE";
        constexpr const char* running1        =   "TESTER  ";
        constexpr const char* waiting2        =   "ATTENDRE";
        constexpr const char* running2        =   "TESTER  ";

        constexpr const char* test_failed     =   " 20A TEST MANQUE";
        constexpr const char* test_32_1       =   " DEMARRER TEST  ";
        constexpr  const char* test_32_2       =  " AVEC CABLE 32A ";

        constexpr const char* test_cable      =   "  CABLE: ";
        constexpr const char* test_details    =   " DETAILS DU TEST";

        constexpr const char* charging1       =   "PAS DE TEST LORS";
        constexpr const char* charging2       =   " DE LA RECHARGE ";

        constexpr const char* battery_low1    =   "  BATTERIE VIDE ";
        constexpr const char* battery_low2    =   "    VEUILLEZ    ";
        constexpr const char* battery_low3    =   "    RECHARGE    ";
        constexpr const char* battery_ok      =   "  BATTERIE OK   ";

        constexpr const char* auth_1            =   "VALEURS OBSCURES";           
        constexpr const char* auth_2            =   "  AUTORISATION  ";
        constexpr const char* auth_3            =   "  NECESSAIRE?   ";

        constexpr const char* data_lost1        =   "   CHARGEMENT   ";
        constexpr const char* data_lost2        =   " DONNEES ECHOUE ";

        constexpr const char* info              =   "      INFO      ";
        constexpr const char* info_1            =   "VERSION SOWFTARE";
        constexpr const char* info_2            =   "  2.0 (09/2023) ";

        constexpr const char* saved1          =   "  VALUE 1:  ";
        constexpr const char* saved2          =   "  VALUE 2:  ";
        constexpr const char* saved3          =   "  VALUE 3:  ";

        constexpr const char* messung         =   "     MESURE     ";

        constexpr const char* spanish          =  "    ESPAGNOL    ";

        constexpr const char* settingslang_3  =   "   PARAMETRES   ";
    }
        namespace spanish
    {   
        constexpr const char* standardtest_1  =   "      PRUEBA      ";
        constexpr const char* standardtest_2  =   "	ESTANDAR (20A) ";
        constexpr const char* preparation_1   =   " CONECTAR HOJA ";
        constexpr const char* preparation_2   =   "    AUTORIZAR   ";
        constexpr const char* next            =   " OK = CONTINUAR ";
        constexpr const char* cancel          =   "ESC = CANCELAR";
        constexpr const char* test_ended      =   "PRUEBA FINALIZADA";
        constexpr const char* finish          =   " ESC = FINAL ";
        constexpr const char* details         =   "  OK = DETALLES ";
        constexpr const char* wantsave        =   "  REGISTRARSE?  ";
        constexpr const char* yes             =   "    OK = SI    ";
        constexpr const char* no              =   "    ESC = NO    ";
        constexpr const char* stateetest_1    =   "      TEST      ";
        constexpr const char* stateetest_2    =   "     STATE E    ";
        constexpr const char* savedvalues_1   =   "    VALORES     ";
        constexpr const char* savedvalues_2   =   "  REGISTRADO  ";
        constexpr const char* settingslang_1  =   "     ELEGIR    ";
        constexpr const char* settingslang_2  =   "     LENGUA     ";
        constexpr const char* english         =   "     INGLES    ";
        constexpr const char* german          =   "    ALEMAN    ";
        constexpr const char* french          =   "    FRANCIA    ";
        constexpr const char* save            =   "OK = REGISTRESE";

        constexpr const char* statea          =   "ESTATUTOS A: ";
        constexpr const char* stateb          =   "ESTATUTOS B: ";
        constexpr const char* statec          =   "ESTATUTOS C: ";
        constexpr const char* stated          =   "ESTATUTOS D: ";
        constexpr const char* phases          =   "FASES: ";
        constexpr const char* turnoff         =   "tArret: ";

        constexpr const char* posvol          =   "VOLTAJE +: ";
        constexpr const char* negvol          =   "VOLTAJE -: ";
        constexpr const char* fre             =   "FRECUENCIA: ";
        constexpr const char* dc              =   "DUTY CYCLE:";
        constexpr const char* cur             =   "CORRIENTE :   ";

        constexpr const char* phase1          =   "L1:      ";
        constexpr const char* phase2          =   "L2:      ";
        constexpr const char* phase3          =   "L3:      ";
        constexpr const char* rot             =   "ROTACION:";

        constexpr const char* time            =   "TIEMPO:   ";

        constexpr const char* right           =   "DERECHA";
        constexpr const char* left            =   "IZQUIERDA";
        constexpr const char* on              =   "ON";
        constexpr const char* off             =   "--";

        constexpr const char* ok              =   "OK   ";
        constexpr const char* fail            =   "--   ";
        constexpr const char* ok1             =   "OK      ";
        constexpr const char* fail1           =   "--      ";

        constexpr const char* waiting1        =   "ESPERA";
        constexpr const char* running1        =   "PRUEBA  ";
        constexpr const char* waiting2        =   "ESPERA";
        constexpr const char* running2        =   "PRUEBA  ";

        constexpr const char* test_failed     =   "FALTA LA PRUEBA 20A";
        constexpr const char* test_32_1       =   " INICIAR PRUEBA  ";
        constexpr  const char* test_32_2       =  " CON CABLE 32A ";

        constexpr const char* test_cable      =   "  CABLE: ";
        constexpr const char* test_details    =   "DETALLES DE LA PRUEBA";

        constexpr const char* charging1       =   "NINGUNA PRUEBA ";
        constexpr const char* charging2       =   "DURANTE RECARGA ";

        constexpr const char* battery_low1    =   "  BATERIA VACIA ";
        constexpr const char* battery_low2    =   "    POR FAVOR    ";
        constexpr const char* battery_low3    =   "    RECARGA    ";
        constexpr const char* battery_ok      =   "  BATERIA OK   ";

        constexpr const char* auth_1            =   "VALORES OBSCUROS";           
        constexpr const char* auth_2            =   "  AUTORIZACIONES  ";
        constexpr const char* auth_3            =   "  NECESARIO?   ";

        constexpr const char* data_lost1        =   "   CARGA   ";
        constexpr const char* data_lost2        =   " DATOS DE ESCAPE ";

        constexpr const char* info              =   "      INFO      ";
        constexpr const char* info_1            =   "VERSION SOWFTARE";
        constexpr const char* info_2            =   "  2.0 (09/2023) ";

        constexpr const char* saved1          =   "  VALOR 1:  ";
        constexpr const char* saved2          =   "  VALOR 2:  ";
        constexpr const char* saved3          =   "  VALOR 3:  ";

        constexpr const char* messung         =   "      MEDIR     ";

        constexpr const char* spanish          =   "     ESPANOL    ";

        constexpr const char* settingslang_3  =   "    PARAMETRO   ";
    }
}

Language::Language() {
    lang_state = 0;
}

uint8_t Language::getLanguage(){
    return lang_state;
}
void Language::setEnglish(){
    lang_state = 0;
}
void Language::setGerman(){
    lang_state = 1;
}

void Language::setFrench(){
    lang_state = 2;
}
void Language::setSpanish(){
    lang_state = 3;
}


const char* Language::getmessung() const{
    switch(lang_state)
    {
        case 0:
                return language::english::messung;
        case 1:
                return language::german::messung;
        case 2: 
                return language::french::messung;
        case 3: 
                return language::spanish::messung;
        default:
                return language::english::messung;
    }
}

const char* Language::getInfo() const{
    switch(lang_state)
    {
        case 0:
                return language::english::info;
        case 1:
                return language::german::info;
        case 2: 
                return language::french::info;
        case 3: 
                return language::spanish::info;
        default:
                return language::english::info;
    }
}


const char* Language::getInfo_1() const{
    switch(lang_state)
    {
        case 0:
                return language::english::info_1;
        case 1:
                return language::german::info_1;
        case 2: 
                return language::french::info_1;
        case 3: 
                return language::spanish::info_1;
        default:
                return language::english::info_1;
    }
}


const char* Language::getInfo_2() const{
    switch(lang_state)
    {
        case 0:
                return language::english::info_2;
        case 1:
                return language::german::info_2;
        case 2: 
                return language::french::info_2;
        case 3: 
                return language::spanish::info_2;
        default:
                return language::english::info_2;
    }
}


const char* Language::getSaved1() const{
    switch(lang_state)
    {
        case 0:
                return language::english::saved1 ;
        case 1:
                return language::german::saved1 ;
        case 2: 
                return language::french::saved1 ;
        case 3: 
                return language::spanish::saved1;
        default:
                return language::english::saved1 ;
    }
}


const char* Language::getSaved2() const{
    switch(lang_state)
    {
        case 0:
                return language::english::saved2;
        case 1:
                return language::german::saved2;
        case 2: 
                return language::french::saved2;
        case 3: 
                return language::spanish::saved2;
        default:
                return language::english::saved2;
    }
}







const char* Language::getSaved3() const{
    switch(lang_state)
    {
        case 0:
                return language::english::saved3;
        case 1:
                return language::german::saved3;
        case 2: 
                return language::french::saved3;
        case 3: 
                return language::spanish::saved3;
        default:
                return language::english::saved3;
    }
}





const char* Language::getSpanish() const {
    switch(lang_state)
    {
        case 0:
                return language::english::spanish;
        case 1:
                return language::german::spanish;
        case 2: 
                return language::french::spanish;
        case 3: 
                return language::spanish::spanish;
        default:
                return language::english::spanish;
    }
}



const char* Language::getSettingslang_3() const{
    switch(lang_state)
    {
        case 0:
                return language::english::settingslang_3;
        case 1:
                return language::german::settingslang_3;
        case 2: 
                return language::french::settingslang_3;
        case 3: 
                return language::spanish::settingslang_3;
        default:
                return language::english::settingslang_3;
    }
}











































const char* Language::getStandardtest_1() const{
    switch(lang_state)
    {
        case 0:
                return language::english::standardtest_1;
        case 1:
                return language::german::standardtest_1;
        case 2: 
                return language::french::standardtest_1;
        case 3: 
                return language::spanish::standardtest_1;
        default:
                return language::english::standardtest_1;
    }
}
const char* Language::getStandardtest_2() const{
    switch(lang_state)
    {
        case 0:
                return language::english::standardtest_2;
        case 1:
                return language::german::standardtest_2;
        case 2: 
                return language::french::standardtest_2;
        case 3: 
                return language::spanish::standardtest_1;
        default:
                return language::english::standardtest_2;
    }
}
const char* Language::getStateetest_1() const{
    if(lang_state == 0){return language::english::stateetest_1;}
    else{return language::german::stateetest_1;}
}
const char* Language::getStateetest_2() const{
    if(lang_state == 0){return language::english::stateetest_2;}
    else{return language::german::stateetest_2;}
}
const char* Language::getPreparation_1() const{
    switch(lang_state)
    {
        case 0:
                return language::english::preparation_1;
        case 1:
                return language::german::preparation_1;
        case 2: 
                return language::french::preparation_1;
        case 3: 
                return language::spanish::preparation_1;
        default:
                return language::english::preparation_1;
    }
}
const char* Language::getPreparation_2() const{
    switch(lang_state)
    {
        case 0:
                return language::english::preparation_2;
        case 1:
                return language::german::preparation_2;
        case 2: 
                return language::french::preparation_2;
        case 3: 
                return language::spanish::preparation_2;
        default:
                return language::english::preparation_2;
    }
}
const char* Language::getNext() const{
    switch(lang_state)
    {
        case 0:
                return language::english::next;
        case 1:
                return language::german::next;
        case 2: 
                return language::french::next;
        case 3: 
                return language::spanish::next;
        default:
                return language::english::next;
    }
}
const char* Language::getCancel() const{
    switch(lang_state)
    {
        case 0:
                return language::english::cancel;
        case 1:
                return language::german::cancel;
        case 2: 
                return language::french::cancel;
        case 3: 
                return language::spanish::cancel;
        default:
                return language::english::cancel;
    }
}
const char* Language::getTest_ended() const{
    switch(lang_state)
    {
        case 0:
                return language::english::test_ended;
        case 1:
                return language::german::test_ended;
        case 2: 
                return language::french::test_ended;
        case 3: 
                return language::spanish::test_ended;
        default:
                return language::english::test_ended;
    }
}
const char* Language::getFinish() const{
    switch(lang_state)
    {
        case 0:
                return language::english::finish;
        case 1:
                return language::german::finish;
        case 2: 
                return language::french::finish;
        case 3: 
                return language::spanish::finish;        
        default:
                return language::english::finish;
    }
}
const char* Language::getDetails() const{
    switch(lang_state)
    {
        case 0:
                return language::english::details;
        case 1:
                return language::german::details;
        case 2: 
                return language::french::details;
        case 3:
                return language::spanish::details;
        default:
                return language::english::details;
    }
}
const char* Language::getWantsave() const{
    switch(lang_state)
    {
        case 0:
                return language::english::wantsave;
        case 1:
                return language::german::wantsave;
        case 2: 
                return language::french::wantsave;
        case 3:
                return language::spanish::wantsave;
        default:
                return language::english::wantsave;
    }
}
const char* Language::getYes() const{
    switch(lang_state)
    {
        case 0:
                return language::english::yes;
        case 1:
                return language::german::yes;
        case 2: 
                return language::french::yes;
        case 3: 
                return language::spanish::yes;
        default:
                return language::english::yes;
    }
}
const char* Language::getNo() const{
    switch(lang_state)
    {
        case 0:
                return language::english::no;
        case 1:
                return language::german::no;
        case 2: 
                return language::french::no;
        case 3: 
                return language::spanish::no;
        default:
                return language::english::no;
    }
}
const char* Language::getSavedvalues_1() const{
    switch(lang_state)
    {
        case 0:
                return language::english::savedvalues_1;
        case 1:
                return language::german::savedvalues_1;
        case 2: 
                return language::french::savedvalues_1;
        case 3: 
                return language::spanish::savedvalues_1;
        default:
                return language::english::savedvalues_1;
    }
}
const char* Language::getSavedvalues_2() const{
    switch(lang_state)
    {
        case 0:
                return language::english::savedvalues_2;
        case 1:
                return language::german::savedvalues_2;
        case 2: 
                return language::french::savedvalues_2;
        case 3: 
                return language::spanish::savedvalues_2;
        default:
                return language::english::savedvalues_2;
    }
}
const char* Language::getSettingslang_1() const{
    switch(lang_state)
    {
        case 0:
                return language::english::settingslang_1;
        case 1:
                return language::german::settingslang_1;
        case 2: 
                return language::french::settingslang_1;
        case 3: 
                return language::spanish::settingslang_1;
        default:
                return language::english::settingslang_1;
    }
}
const char* Language::getSettingslang_2() const{
    switch(lang_state)
    {
        case 0:
                return language::english::settingslang_2;
        case 1:
                return language::german::settingslang_2;
        case 2: 
                return language::french::settingslang_2;
        case 3: 
                return language::spanish::settingslang_2;
        default:
                return language::english::settingslang_2;
    }
}
const char* Language::getEnglish() const{
    switch(lang_state)
    {
        case 0:
                return language::english::english;
        case 1:
                return language::german::english;
        case 2: 
                return language::french::english;
        case 3: 
                return language::spanish::english;
        default:
                return language::english::english;
    }
}
const char* Language::getGerman() const{
    switch(lang_state)
    {
        case 0:
                return language::english::german;
        case 1:
                return language::german::german;
        case 2: 
                return language::french::german;
        case 3: 
                return language::spanish::german;
        default:
                return language::english::german;
    }
}

const char* Language::getFrench() const {
    switch(lang_state)
    {
        case 0:
                return language::english::french;
        case 1:
                return language::german::french;
        case 2: 
                return language::french::french;
        case 3: 
                return language::spanish::french;
        default:
                return language::english::french;
    }
}
const char* Language::getSave() const{
    switch(lang_state)
    {
        case 0:
                return language::english::save;
        case 1:
                return language::german::save;
        case 2: 
                return language::french::save;
        case 3: 
                return language::spanish::save;
        default:
                return language::english::save;
    }
}

const char* Language::getStatea() const{
    switch(lang_state)
    {
        case 0:
                return language::english::statea;
        case 1:
                return language::german::statea;
        case 2: 
                return language::french::statea;
        case 3: 
                return language::spanish::statea;
        default:
                return language::english::statea;
    }
}
const char* Language::getStateb() const{
    switch(lang_state)
    {
        case 0:
                return language::english::stateb;
        case 1:
                return language::german::stateb;
        case 2: 
                return language::french::stateb;
        case 3: 
                return language::spanish::stateb;
        default:
                return language::english::stateb;
    }
}
const char* Language::getStatec() const{
    switch(lang_state)
    {
        case 0:
                return language::english::statec;
        case 1:
                return language::german::statec;
        case 2: 
                return language::french::statec;
        case 3: 
                return language::spanish::statec;
        default:
                return language::english::statec;
    }
}
const char* Language::getStated() const{
    if(lang_state == 0){return language::english::stated;}
    else{return language::german::stated;}
}
const char* Language::getPhases() const{
    switch(lang_state)
    {
        case 0:
                return language::english::phases;
        case 1:
                return language::german::phases;
        case 2: 
                return language::french::phases;
        case 3: 
                return language::spanish::phases;
        default:
                return language::english::phases;
    }
    
}
const char* Language::getTurnoff() const{
    switch(lang_state)
    {
        case 0:
                return language::english::turnoff;
        case 1:
                return language::german::turnoff;
        case 2: 
                return language::french::turnoff;
        case 3: 
                return language::spanish::turnoff;
        default:
                return language::english::turnoff;
    }
}

const char* Language::getPosvol() const{
    switch(lang_state)
    {
        case 0:
                return language::english::posvol;
        case 1:
                return language::german::posvol;
        case 2: 
                return language::french::posvol;
        case 3: 
                return language::spanish::posvol;
        default:
                return language::english::posvol;
    }
}
const char* Language::getNegvol() const{
    switch(lang_state)
    {
        case 0:
                return language::english::negvol;
        case 1:
                return language::german::negvol;
        case 2: 
                return language::french::negvol;
        case 3: 
                return language::spanish::negvol;
        default:
                return language::english::negvol;
    }
}
const char* Language::getFre() const{
    switch(lang_state)
    {
        case 0:
                return language::english::fre;
        case 1:
                return language::german::fre;
        case 2: 
                return language::french::fre;
        case 3: 
                return language::spanish::fre;
        default:
                return language::english::fre;
    }
}
const char* Language::getDc() const{
    switch(lang_state)
    {
        case 0:
                return language::english::dc;
        case 1:
                return language::german::dc;
        case 2: 
                return language::french::dc;
        case 3: 
                return language::spanish::dc;
        default:
                return language::english::dc;
    }
}
const char* Language::getCur() const{
    switch(lang_state)
    {
        case 0:
                return language::english::cur;
        case 1:
                return language::german::cur;
        case 2: 
                return language::french::cur;
        case 3: 
                return language::spanish::cur;
        default:
                return language::english::cur;
    }
}

const char* Language::getPhase1() const{
    switch(lang_state)
    {
        case 0:
                return language::english::phase1;
        case 1:
                return language::german::phase1;
        case 2: 
                return language::french::phase1;
        case 3: 
                return language::spanish::phase1;
        default:
                return language::english::phase1;
    }
}
const char* Language::getPhase2() const{
    switch(lang_state)
    {
        case 0:
                return language::english::phase2;
        case 1:
                return language::german::phase2;
        case 2: 
                return language::french::phase2;
        case 3: 
                return language::spanish::phase2;
        default:
                return language::english::phase2;
    }
}
const char* Language::getPhase3() const{
    switch(lang_state)
    {
        case 0:
                return language::english::phase3;
        case 1:
                return language::german::phase3;
        case 2: 
                return language::french::phase3;
        case 3: 
                return language::spanish::phase3;
        default:
                return language::english::phase3;
    }
}
const char* Language::getRot() const{
    switch(lang_state)
    {
        case 0:
                return language::english::rot;
        case 1:
                return language::german::rot;
        case 2: 
                return language::french::rot;
        case 3: 
                return language::spanish::rot;
        default:
                return language::english::rot;
    }
}

const char* Language::getTime() const{
    switch(lang_state)
    {
        case 0:
                return language::english::time;
        case 1:
                return language::german::time;
        case 2: 
                return language::french::time;
        case 3: 
                return language::spanish::time;
        default:
                return language::english::time;
    }
}

const char* Language::getLeft() const{
    switch(lang_state)
    {
        case 0:
                return language::english::left;
        case 1:
                return language::german::left;
        case 2: 
                return language::french::left;
        case 3: 
                return language::spanish::left;
        default:
                return language::english::left;
    }
}
const char* Language::getRight() const{
    switch(lang_state)
    {
        case 0:
                return language::english::right;
        case 1:
                return language::german::right;
        case 2: 
                return language::french::right;
        case 3: 
                return language::spanish::right;
        default:
                return language::english::right;
    }
}
const char* Language::getOn() const{
    switch(lang_state)
    {
        case 0:
                return language::english::on;
        case 1:
                return language::german::on;
        case 2: 
                return language::french::on;
        case 3: 
                return language::spanish::on;
        default:
                return language::english::on;
    }
}
const char* Language::getOff() const{
    switch(lang_state)
    {
        case 0:
                return language::english::off;
        case 1:
                return language::german::off;
        case 2: 
                return language::french::off;
        case 3: 
                return language::spanish::off;
        default:
                return language::english::off;
    }
}

const char* Language::getOk() const{
    switch(lang_state)
    {
        case 0:
                return language::english::ok;
        case 1:
                return language::german::ok;
        case 2: 
                return language::french::ok;
        case 3: 
                return language::spanish::ok;
        default:
                return language::english::ok;
    }
}
const char* Language::getFail() const{
    switch(lang_state)
    {
        case 0:
                return language::english::fail;
        case 1:
                return language::german::fail;
        case 2: 
                return language::french::fail;
        case 3: 
                return language::spanish::fail;
        default:
                return language::english::fail;
    }
}
const char* Language::getOk1() const{
    switch(lang_state)
    {
        case 0:
                return language::english::ok1;
        case 1:
                return language::german::ok1;
        case 2: 
                return language::french::ok1;
        case 3: 
                return language::spanish::ok1;
        default:
                return language::english::ok1;
    }
}
const char* Language::getFail1() const{
    switch(lang_state)
    {
        case 0:
                return language::english::fail1;
        case 1:
                return language::german::fail1;
        case 2: 
                return language::french::fail1;
        case 3: 
                return language::spanish::fail1;
        default:
                return language::english::fail1;
    }
}

const char* Language::getWaiting1() const{
    switch(lang_state)
    {
        case 0:
                return language::english::waiting1;
        case 1:
                return language::german::waiting1;
        case 2: 
                return language::french::waiting1;
        case 3: 
                return language::spanish::waiting1;
        default:
                return language::english::waiting1;
    }
}
const char* Language::getRunning1() const{
    switch(lang_state)
    {
        case 0:
                return language::english::running1;
        case 1:
                return language::german::running1;
        case 2: 
                return language::french::running1;
        case 3: 
                return language::spanish::running1;
        default:
                return language::english::running1;
    }
}
const char* Language::getWaiting2() const{
    switch(lang_state)
    {
        case 0:
                return language::english::waiting2;
        case 1:
                return language::german::waiting2;
        case 2: 
                return language::french::waiting2;
        case 3: 
                return language::spanish::waiting2;
        default:
                return language::english::waiting2;
    }
}
const char* Language::getRunning2() const{
    switch(lang_state)
    {
        case 0:
                return language::english::running2;
        case 1:
                return language::german::running2;
        case 2: 
                return language::french::running2;
        case 3: 
                return language::spanish::running2;
        default:
                return language::english::running2;
    }
}

const char* Language::getTest_failed() const{
    switch(lang_state)
    {
        case 0:
                return language::english::test_failed;
        case 1:
                return language::german::test_failed;
        case 2: 
                return language::french::test_failed;
        case 3: 
                return language::spanish::test_failed;
        default:
                return language::english::test_failed;
    }
}
const char* Language::getTest_32_1() const{
    switch(lang_state)
    {
        case 0:
                return language::english::test_32_1;
        case 1:
                return language::german::test_32_1;
        case 2: 
                return language::french::test_32_1;
        case 3: 
                return language::spanish::test_32_1;
        default:
                return language::english::test_32_1;
    }
}
const char* Language::getTest_32_2() const{
    switch(lang_state)
    {
        case 0:
                return language::english::test_32_2;
        case 1:
                return language::german::test_32_2;
        case 2: 
                return language::french::test_32_2;
        case 3: 
                return language::spanish::test_32_2;
        default:
                return language::english::test_32_2;
    }
}

const char* Language::getTest_cable() const{
    switch(lang_state)
    {
        case 0:
                return language::english::test_cable;
        case 1:
                return language::german::test_cable;
        case 2: 
                return language::french::test_cable;
        case 3: 
                return language::spanish::test_cable;
        default:
                return language::english::test_cable;
    }
}
const char* Language::getTest_details() const{
    switch(lang_state)
    {
        case 0:
                return language::english::test_details;
        case 1:
                return language::german::test_details;
        case 2: 
                return language::french::test_details;
        case 3: 
                return language::spanish::test_details;
        default:
                return language::english::test_details;
    }
}

const char* Language::getCharging1() const{
    switch(lang_state)
    {
        case 0:
                return language::english::charging1;
        case 1:
                return language::german::charging1;
        case 2: 
                return language::french::charging1;
        case 3: 
                return language::spanish::charging1;
        default:
                return language::english::charging1;
    }
}
const char* Language::getCharging2() const{
    switch(lang_state)
    {
        case 0:
                return language::english::charging2;
        case 1:
                return language::german::charging2;
        case 2: 
                return language::french::charging2;
        case 3: 
                return language::spanish::charging2;
        default:
                return language::english::charging2;
    }
}

const char* Language::getBattery_low1() const{
    switch(lang_state)
    {
        case 0:
                return language::english::battery_low1;
        case 1:
                return language::german::battery_low1;
        case 2: 
                return language::french::battery_low1;
        case 3: 
                return language::spanish::battery_low1;
        default:
                return language::english::battery_low1;
    }
}
const char* Language::getBattery_low2() const{
    switch(lang_state)
    {
        case 0:
                return language::english::battery_low2;
        case 1:
                return language::german::battery_low2;
        case 2: 
                return language::french::battery_low2;
        case 3: 
                return language::spanish::battery_low2;
        default:
                return language::english::battery_low2;
    }
}
const char* Language::getBattery_low3() const{
    switch(lang_state)
    {
        case 0:
                return language::english::battery_low3;
        case 1:
                return language::german::battery_low3;
        case 2: 
                return language::french::battery_low3;
        case 3: 
                return language::spanish::battery_low3;
        default:
                return language::english::battery_low3;
    }
}
const char* Language::getBattery_ok() const{
    switch(lang_state)
    {
        case 0:
                return language::english::battery_ok;
        case 1:
                return language::german::battery_ok;
        case 2: 
                return language::french::battery_ok;
        case 3: 
                return language::spanish::battery_ok;
        default:
                return language::english::battery_ok;
    }
}

const char* Language::getAuth_1() const{
    switch(lang_state)
    {
        case 0:
                return language::english::auth_1;
        case 1:
                return language::german::auth_1;
        case 2: 
                return language::french::auth_1;
        case 3: 
                return language::spanish::auth_1;
        default:
                return language::english::auth_1;
    }
}
const char* Language::getAuth_2() const{
    switch(lang_state)
    {
        case 0:
                return language::english::auth_2;
        case 1:
                return language::german::auth_2;
        case 2: 
                return language::french::auth_2;
        case 3: 
                return language::spanish::auth_2;
        default:
                return language::english::auth_2;
    }
}
const char* Language::getAuth_3() const{
    switch(lang_state)
    {
        case 0:
                return language::english::auth_3;
        case 1:
                return language::german::auth_3;
        case 2: 
                return language::french::auth_3;
        case 3: 
                return language::spanish::auth_3;
        default:
                return language::english::auth_3;
    }
}
const char* Language::getData_lost1() const{
    switch(lang_state)
    {
        case 0:
                return language::english::data_lost1;
        case 1:
                return language::german::data_lost1;
        case 2: 
                return language::french::data_lost1;
        case 3: 
                return language::spanish::data_lost1;
        default:
                return language::english::data_lost1;
    }
}
const char* Language::getData_lost2() const{
    switch(lang_state)
    {
        case 0:
                return language::english::data_lost2;
        case 1:
                return language::german::data_lost2;
        case 2: 
                return language::french::data_lost2;
                case 3: 
                return language::spanish::data_lost2;
        default:
                return language::english::data_lost2;
    }
}