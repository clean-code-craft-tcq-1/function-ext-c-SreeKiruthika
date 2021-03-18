#include <stdio.h>
#include <assert.h>

#ifndef _BMS_H
#include "bms.h"
#endif


/******************************************/
/*******Global variables declaration*******/

enum LANGUAGES PrintLanguage = ENGLISH;

int main() 
{

  struct batteryParam_unit unitsMeasured = {CELCIUS, PERCENT , RATIO};	
 float temp_measured, soc_measured, chrgRate_measured;	
  temp_measured = 25;
  soc_measured = 70 ;
  chrgRate_measured = 0.7 ;
  printf("The passed test values are \nTemperature = %f \nSoC = %f \nCharge Rate = %f", temp_measured, soc_measured, chrgRate_measured);
  /*All param within range */
   assert(BatteryStateCheck(temp_measured, soc_measured, chrgRate_measured,unitsMeasured));
  /*Temperature out of range */
  temp_measured = 46;
  soc_measured = 70 ;
  chrgRate_measured = 0.3 ;
  printf("The passed test values are \nTemperature = %f \nSoC = %f \nCharge Rate = %f", temp_measured, soc_measured, chrgRate_measured);

  assert(!BatteryStateCheck(temp_measured, soc_measured, chrgRate_measured,unitsMeasured));
  /*SoC out of range */
  temp_measured = 50;
  soc_measured = 85;
  chrgRate_measured = 0 ;
  printf("The passed test values are \nTemperature = %f \nSoC = %f \nCharge Rate = %f", temp_measured, soc_measured, chrgRate_measured);

  assert(!BatteryStateCheck(temp_measured, soc_measured, chrgRate_measured,unitsMeasured));
  /*Charge rate out of range */
  temp_measured = 25;
  soc_measured = 70 ;
  chrgRate_measured = 0.85 ;
  printf("The passed test values are \nTemperature = %f \nSoC = %f \nCharge Rate = %f", temp_measured, soc_measured, chrgRate_measured);

  assert(!BatteryStateCheck(temp_measured, soc_measured, chrgRate_measured,unitsMeasured));
  /*All out of range */
  temp_measured = 5;
  soc_measured = 85 ;
  chrgRate_measured = 0.81 ;
  printf("The passed test values are \nTemperature = %f \nSoC = %f \nCharge Rate = %f", temp_measured, soc_measured, chrgRate_measured);

  assert(!BatteryStateCheck(temp_measured, soc_measured, chrgRate_measured,unitsMeasured));
/*Re initialisation of Temperature unit to celcius*/
  unitsMeasured.tempUnit = FAHRENHEIT;  
  /*All param within range */
  temp_measured = 77;
  soc_measured = 70 ;
  chrgRate_measured = 0.7 ;
  printf("The passed test values are \nTemperature = %f in Fanhrenheit \nSoC = %f \nCharge Rate = %f", temp_measured, soc_measured, chrgRate_measured);

  assert(BatteryStateCheck(temp_measured, soc_measured, chrgRate_measured,unitsMeasured));
  /*Temperature out of range */
  temp_measured = 114.8;
  soc_measured = 70 ;
  chrgRate_measured = 0.3 ;
  printf("The passed test values are \nTemperature = %f in Fanhrenheit \nSoC = %f \nCharge Rate = %f", temp_measured, soc_measured, chrgRate_measured);

  assert(!BatteryStateCheck(temp_measured, soc_measured, chrgRate_measured,unitsMeasured));
  /*SoC out of range */
  temp_measured = 122;
  soc_measured = 85 ;
  chrgRate_measured = 0 ;
  printf("The passed test values are \nTemperature = %f in Fanhrenheit \nSoC = %f \nCharge Rate = %f", temp_measured, soc_measured, chrgRate_measured);

  assert(!BatteryStateCheck(temp_measured, soc_measured, chrgRate_measured,unitsMeasured));
  /*Charge rate out of range */
  temp_measured = 50;
  soc_measured = 70 ;
  chrgRate_measured = 0.85 ;
  printf("The passed test values are \nTemperature = %f in Fanhrenheit \nSoC = %f \nCharge Rate = %f", temp_measured, soc_measured, chrgRate_measured);

  assert(!BatteryStateCheck(temp_measured, soc_measured, chrgRate_measured,unitsMeasured));
  
}


