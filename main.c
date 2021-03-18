#include <stdio.h>
#include <assert.h>

#ifndef _BMS_H
#include "bms.h"
#endif


/******************************************/
/*******Global variables declaration*******/

enum LANGUAGES PrintLanguage = GERMAN;

#if (PrintLanguage == GERMAN)
	char paramNames[NUMPARAM][20] = {"Temperatur", " Ladezustand", "Ladestrom"};
#else
    char paramNames[NUMPARAM][20] = {"Temperature", "StateofCharge", "ChargeRate"};
#endif

int main() 
{

  struct batteryParam_unit unitsMeasured = {CELCIUS, PERCENT , RATIO};	
	
  /*All param within range */
  assert(BatteryStateCheck(25, 70, 0.7,unitsMeasured));
  /*Temperature out of range */
  assert(!BatteryStateCheck(46, 70, 0.3,unitsMeasured));
  /*SoC out of range */
  assert(!BatteryStateCheck(50, 85, 0,unitsMeasured));
  /*Charge rate out of range */
  assert(!BatteryStateCheck(25, 70, 0.85,unitsMeasured));

/*Re initialisation of Temperature unit to celcius*/
  unitsMeasured.tempUnit = FAHRENHEIT;  
  /*All param within range */
  assert(BatteryStateCheck(77, 70, 0.7,unitsMeasured));
  /*Temperature out of range */
  assert(!BatteryStateCheck(114.8, 70, 0.3,unitsMeasured));
  /*SoC out of range */
  assert(!BatteryStateCheck(122, 85, 0,unitsMeasured));
  /*Charge rate out of range */
  assert(!BatteryStateCheck(50, 70, 0.85,unitsMeasured));
  
}


