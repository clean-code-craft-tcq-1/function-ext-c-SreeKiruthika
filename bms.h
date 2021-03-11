/************************************************************************************************************************/
/* This file contains the inclusions and definitions needed for BMS*/
/************************************************************************************************************************/
#include <stdio.h>

/***************DEFINES section *****************************/
/* Parameters related to battery maintainence check is defined here*/
#define MINTEMP 0
#define MAXTEMP 45
#define MINSOC  20
#define MAXSOC  80
#define MINCHGRATE 0
#define MAXCHGRATE 0.8

#define BELOW_MIN 1
#define ABOVE_MAX 2
#define IN_RANGE 0

enum TEMP_UNITS  {CELCIUS, FAHRENHEIT, KELVIN};
enum SOC_UNITS  {PERCENT};
enum CHGRATE_UNITS  {RATIO};
enum LANGUAGES {ENGLISH,GERMAN,NUMLANG};

/*******Global variables declaration*******/

extern enum LANGUAGES PrintLanguage;

/*****************************************/

/***************Structure definitions*******************/
/*Structure which holds the unit in which battery parameters are measured */
struct batteryParam_unit
{
   enum TEMP_UNITS tempUnit;
   enum SOC_UNITS  socUnit;
   enum CHGRATE_UNITS chgrateUnit;
};	
/************************************************************/

/**************Function prototype section**********************/
  
int BatteryStateCheck(float temperature, float soc, float chargeRate, struct batteryParam_unit unit);

void printBatteryStatus(int batteryStatus);

int BatteryParamCheck (float param_value, float min_value, float max_alue);

void BatteryChargeMonitoring(float soc, float chargeRate) ;

void checkIfChargingNeeded(float soc);

void checkIfCharged(float soc);

float convertToCelcius (float temperature, enum TEMP_UNITS unitMeasured);


/************************************************************/