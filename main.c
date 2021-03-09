#include <stdio.h>
#include <assert.h>

#ifndef _BMS_H
#include "bms.h"
#endif

/*******Global variables declaration*******/

extern enum LANGUAGE PrintLanguage;

/******************************************/
PrintLanguage = GERMAN;

int main() 
{

  struct batteryParam_unit unitsMeasured = {FAHRENHEIT, PERCENT , RATIO};	
	
  /*All param within range */
  assert(BatteryStateCheck(25, 70, 0.7,unitsMeasured));
  /*Temperature out of range */
  assert(!BatteryStateCheck(46, 70, 0.3,unitsMeasured));
  /*SoC out of range */
  assert(!BatteryStateCheck(50, 85, 0,unitsMeasured));
  /*Charge rate out of range */
  assert(!BatteryStateCheck(25, 70, 0.85,unitsMeasured));
  
  /*This function to be called every frequently based on the monitoring frequency needed*/
  /*Not charging and battery is normal */
  printf("\n\nTC1\nThe passed values for battery charging status check are as follows \nSoC : 80 \nCharge rate:0");
  BatteryChargeMonitoring (80,0);

  /*Not charging and charge is low  */
  printf("\n\nTC2\nThe passed values for battery charging status check are as follows \nSoC : 19 \nCharge rate:0");
  BatteryChargeMonitoring (19,0);

  /*Charging and charge is above threshold */
  printf("\n\nTC3\nThe passed values for battery charging status check are as follows \nSoC : 81 \nCharge rate:0.3");
  BatteryChargeMonitoring (81,0.3);

  /*Charging and charge is in limit */
  printf("\n\nTC4\nThe passed values for battery charging status check are as follows \nSoC : 75 \nCharge rate:0.5");
  BatteryChargeMonitoring (75,0.5);
}


