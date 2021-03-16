#include "bms.h"
/* This is the variable or switch output which turns ON to establich connection between battery and charge source*/
extern int chargeRelay;  

int chargeRelay = DISCONNECT;
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
	   chargeRelay = DISCONNECT ;
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
	   printf("\nCharging is sufficient, UNPLUGED CHARGER!");
	   chargeRelay = DISCONNECT ;
	}
	else
	{
	  printf("\nBatery charge value is %f , continues charging till 80%%", soc);
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
	   printf("\nBattery charge is low, CONNECTED CHARGER!");
	   chargeRelay = CONNECT ;
	}
	else
	{
	  printf("\nBatery charge value is %f", soc);
    }

}

/****************************************************************************************
*Func desc : This function is to control the cooling fan. Fans speed is terms of duty cycle
*Param     : temperature - measured temperature at battery side     
*Return    : No return values, just sets fan control output
*****************************************************************************************/
void coolingFanControl (float temperature)
{
	float fanSpeed ;
	float tempTolerance ;
	tempTolerance = MAXTEMP * 0.05;
	if(temperature < MINTEMP + tempTolerance)
	{
		fanSpeed = FANSPD_MIN ;
	}
	else if (temperature > MAXTEMP + tempTolerance)
	{
		fanSpeed = FANSPD_MAX ;
	}
	else	
	{
		fanSpeed = (temperature / MAXTEMP) * 100 ;
	}
	
}	