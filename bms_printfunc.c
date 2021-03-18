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
	
	char batteryStatusOK[NUMLANG][50] = {"Battery status is OK","Batteriestatus ist in Ordnung"};
	char batteryStatusNOTOK[NUMLANG][50] = {"Battery status is NOT OK","Batteriestatus ist nicht in Ordnung"};
		
	if(batteryStatus)
	{
		printf("\n\n%s",batteryStatusOK[PrintLanguage]);
	}
	else
	{
		printf("\n\n%s",batteryStatusNOTOK[PrintLanguage]);
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
    char category_string[NUMLANG][3][10] ={{"Within","Below","Above"},{"innerhalb","Unterhalb","Oberhalb"}}; 
    char Threshold[NUMLANG][12] = {"Threshold","der Schwelle"};		
	char paramNames[NUMLANG][NUMPARAM][20] = {{"Temperature", "StateofCharge", "ChargeRate"},{"Temperatur", " Ladezustand", "Ladestrom"}};
	
	int i = 0;
	int count = 0;
	printf("\n Parameters %s %s", category_string[PrintLanguage][category], Threshold[PrintLanguage]);
	while(i<NUMPARAM)
	{
		if (paramStatus[i]== category)
		{
			count ++;
			printf("\n%d.%s", count,paramNames[PrintLanguage][i]);
		}
		i=i+1;
	} 
}
