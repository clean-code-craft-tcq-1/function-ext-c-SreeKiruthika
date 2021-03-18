#include "bms.h"

int paramStatus[3]= {0,0,0};
/****************************************************************************************
*Func desc : This function check if the passed battery parameter value is within the specified range 
*Param     : param_value - The measured battery parameter value, whole limits are to be verified - float type
*Return    : Returns the status of param limit check
			 0 - Param is within range (OK)
			 1 - Param is less than required charge (NOT_OK)
			 2 - Param is more than desired charge value (NOT_OK)
*****************************************************************************************/	
int BatteryParamCheck(float param_value, float min_value, float max_value, enum PARAM_NAME param_name)
{
	int retval ;
    if(param_value < min_value)
	{
		retval = BELOW_MIN;
	}
	else if (param_value > max_value) 
	{
		retval = ABOVE_MAX;
	}
	else
	{
		retval = IN_RANGE;
	}
	
	paramStatus[param_name] =  retval;
	return retval;
}	

	

/****************************************************************************************
*Func desc : This function check if the battery state is ok. In this function all the desired battery
			 parameters are checked to validate the current battery status. Further 
*Param     : temperature - The current battery temperature value that was measured -float type
*			 soc         - The current battery state of charge that was measured   -float type	
*            chargerate  - The charging rate that is measured - float type
*Return    : Returns the state of battery as int, 
			 1 - battery is ok
			 0 - battery is not ok
*****************************************************************************************/	  
int BatteryStateCheck(float temperature, float soc, float chargeRate, struct batteryParam_unit unit) 
{
	/*All check param functions must return 0 if the param check is OK*/
    int batteryStatus;
	float convTemp = convertToCelcius (temperature , unit.tempUnit);
	/*All check param functions must return 0 if the param check is OK*/
    int temp_status  = BatteryParamCheck(convTemp , MINTEMP , MAXTEMP, TEMP);
	int soc_status = BatteryParamCheck(soc , MINSOC , MAXSOC , SOC);
	int chargeRate_status  = BatteryParamCheck(chargeRate , MINCHGRATE , MAXCHGRATE, CHRGRATE);
	
	batteryStatus = !(temp_status || soc_status || chargeRate_status);
	
	printBatteryStatus(batteryStatus);
	
	/* For Battery system mamagement*/
	coolingFanControl (temperature);
	BatteryChargeMonitoring(soc,chargeRate) ;
	
	return batteryStatus;
}

/****************************************************************************************
*Func desc : This function converts the passed temperature value into a temperature value of Celcius unit. 
*Param     : temperature - The current battery temperature value that was measured in the unit passed as second argument -float type
*			 unitMeasured- the unit in which the battery temperature is measured by sensor - enum TEMP_UNIT	
*Return    : Returns the temperature value in units of celsius (float) 
****************************************************************************************/
float convertToCelcius (float temperature, enum TEMP_UNITS unitMeasured)
{
   float retval;
   switch(unitMeasured)
   {
	    case KELVIN:
			retval = (temperature - 273) ;
			break;
		
		case FAHRENHEIT:
			retval = (temperature - (float)32) * (0.556);
			break;
		default:
	        retval = temperature ;
			break;
   }
   return retval;
}
