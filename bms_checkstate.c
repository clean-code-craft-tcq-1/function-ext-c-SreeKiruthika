#include "bms.h"

/****************************************************************************************
*Func desc : This function check if the passed battery parameter value is within the specified range 
*Param     : param_value - The measured battery parameter value, whole limits are to be verified - float type
*Return    : Returns the status of param limit check
			 0 - Param is within range (OK)
			 1 - Param is less than required charge (NOT_OK)
			 2 - Param is more than desired charge value (NOT_OK)
*****************************************************************************************/	
int BatteryParamCheck(float param_value, float min_value, float max_value)
{
    if(param_value < min_value)
	{
		return 1;
	}
	else if (param_value > max_value) 
	{
		return 2;
	}
	else
	{
		return 0;
	}
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
	convTemp = convertToCelcius (temperature , unit.tempUnit);
	/*All check param functions must return 0 if the param check is OK*/
	int temp_status  = BatteryParamCheck(convTemp , MINTEMP , MAXTEMP);
	int soc_status = BatteryParamCheck(soc , MINSOC , MAXSOC);
	int chargeRate_status  = BatteryParamCheck(chargeRate , MINCHGRATE , MAXCHGRATE);
	
	batteryStatus = !(temp_status || soc_status || chargeRate_status);
	
	printBatteryStatus(batteryStatus);
	
    return batteryStatus;
}

/****************************************************************************************
*Func desc : This function check if the battery state is ok. In this function all the desired battery
			 parameters are checked to validate the current battery status. 
*Param     : temperature - The current battery temperature value that was measured -float type
*			 soc         - The current battery state of charge that was measured   -float type	
*            chargerate  - The charging rate that is measured - float type
*Return    : Returns the state of battery as int, 
			 1 - battery is ok
			 0 - battery is not ok
*****************************************************************************************/	
void printBatteryStatus(int batteryStatus)
{
	if(batteryStatus)
	{
		if(PrintLanguage == GERMAN)
		{
			printf("\nBatteriestatus ist in Ordnung");
		}
		else
		{
			printf("\nBattery status is OK");
		}
		
	}
	else
	{
		if(PrintLanguage == GERMAN)
		{
			printf("\nBatteriestatus ist nicht in Ordnung");
		}
		else
		{
		    printf("\nBattery status is NOT OK");
		}
	}
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
			retval = (temperature - 32) * (5/9);
			break;
		default:
	        retval = temperature ;
			break;
   }
   return retval;
}