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
	
	#if(PrintLanguage == GERMAN)
	char batteryStatusOK[] = {"Batteriestatus ist in Ordnung"};
	char batteryStatusNOTOK[] = {"Batteriestatus ist nicht in Ordnung"};
	#else
	char batteryStatusOK[] = {"Battery status is OK"};
	char batteryStatusNOTOK[] = {"Battery status is NOT OK"};
	#endif
	
	
	if(batteryStatus)
	{
		printf("\n%s",batteryStatusOK);
	}
	else
	{
		printf("\n%s",batteryStatusNOTOK);
		PrintParamCategoryWise(BELOW_MIN);
		PrintParamCategoryWise(ABOVE_MAX);
	}
	
}

/****************************************************************************************
*Func desc : This function prints the parameters that are under the category passed as parameter
*Param     : The category range which needs to be printed, say below threshold / above threshold or in range	
*Return    : None
****************************************************************************************/
void PrintParamCategoryWise(int category)
{
	#if(PrintLanguage == GERMAN)
	char category_string[3][10] = {"innerhalb","Unterhalb","Oberhalb"}; 
	char Threshold[] = {"der Schwelle"};
	#else
	char category_string[3][10] = {"Within","Below","Above"}; 
	char Threshold[] = {"Threshold"};
    #endif
		
	int i = 0;
	int count = 0;
	printf("\n Parameters %s %s", category_string[category], Threshold);
	while(i<NUMPARAM)
	{
		if (paramStatus[param_name]== category)
		{
			count ++;
			printf("\n%d.%s", count,paramNames[param_name]);
		}
	} 
}
