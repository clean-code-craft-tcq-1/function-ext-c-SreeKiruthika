#include "bms.h"

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
	
	/*Array 0- English, Array 1- German */
	char batteryStatusOK[2][50] = {"Battery status is OK", "Batteriestatus ist in Ordnung"};
	char batteryStatusNOTOK[2][50] = {"Battery status is NOT OK" , "Batteriestatus ist nicht in Ordnung"};
	
	if(batteryStatus)
	{
		printf("\n%s",batteryStatusOK[PrintLanguage]);
	}
	else
	{
		printf("\n%s",batteryStatusNOTOK[PrintLanguage]);
	}
	
}
/****************************************************************************************
*Func desc : This function prints the param status
*Param     : param_name - The paramater is passed as param name
*			 unitMeasured- the unit in which the battery temperature is measured by sensor - enum TEMP_UNIT	
*Return    : Returns the temperature value in units of celsius (float) 
****************************************************************************************/
void PrintParamStatus(enum PARAM_NAME param_name)
{
 	char belowThreshold[NUMLANG][25] = {"Below Threshold","Unterhalb der Schwelle"};
	char aboveThreshold[NUMLANG][25] = {"Above Threshold","oberhalb der Schwelle"};
	
		if (paramStatus[param_name]==1)
		{
			printf("%s : %s\n", paramNames[param_name],belowThreshold[PrintLanguage]);
		}
	    else if (paramStatus[param_name]==2)
		{
			printf("%s : %s\n", paramNames[param_name], aboveThreshold[PrintLanguage]);
		}
	
}