#include "bms.h"

/****************************************************************************************
*Func desc : This function is used to check for the battery charge monitoring 
*Param     : soc         - The current battery state of charge that was measured   -float type	
*            chargerate  - The charging rate that is measured - float type
*Return    : No return values, just infers the battery charge / charging status
*****************************************************************************************/	  
void BatteryChargeMonitoring(float soc, float chargeRate) 
{
	if (chargeRate == 0)
	{
		checkIfChargingNeeded(soc);
	}
	else if(chargeRate < MAXCHGRATE)
	{
	   checkIfCharged(soc);
	}
    else
	{
	   printf("\nBattery Charge rate is not normal, UNPLUG charger!");
 	}
}


/****************************************************************************************
*Func desc : This function is to print the status of battery charging
*Param     : soc         - The current battery state of charge that was measured   -float type	      
*Return    : No return values, just prints battery charging status. This function to be called only if battery charging
*****************************************************************************************/
void checkIfCharged(float soc)
{
	if (soc > MAXSOC)
	{
	   printf("\nCharging is sufficient, UNPLUG CHARGER!");
	}
	else
	{
	  printf("\nBatery charge value is %f , continue charging till 80%%", soc);
    }
}
/****************************************************************************************
*Func desc : This function is to print the status if battery charging needed
*Param     : soc         - The current battery state of charge that was measured   -float type	      
*Return    : No return values, just prints battery charging requiements. This function to be called only if battery is not charging
*****************************************************************************************/
void checkIfChargingNeeded(float soc)
{
	if (soc < MINSOC)
	{
	   printf("\nBattery charge is low, CONNECT CHARGER!");
	}
	else
	{
	  printf("\nBatery charge value is %f, connect if it goes less than 20%%", soc);
    }

}
