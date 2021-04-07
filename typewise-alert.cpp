#include "typewise-alert.h"
#include <stdio.h>
#include <string>

double LowerLimitValues[TOTAL_NUM_OF_COOLING]  = { 0,  0,  0};
double HigherLimitValues[TOTAL_NUM_OF_COOLING] = {35, 45, 40};

BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  if(value < lowerLimit) {
    return TOO_LOW;
  }
  if(value > upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}

void SendToEmail(BreachType TypeOfBreach)
{
  const char* recepient = "a.b@c.com";
  
  if(TypeOfBreach != NORMAL)
      {
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is %x\n",TypeOfBreach);
      }
}

BreachType classifyTemperatureBreach(
    CoolingType coolingType, double temperatureInC) {
  
  if(temperatureInC < LowerLimitValues[coolingType]) {
    return TOO_LOW;
  }
  if(temperatureInC > LowerLimitValues[coolingType]) {
    return TOO_HIGH;
  }
  return NORMAL;
  
}

void checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {

  BreachType breachType = classifyTemperatureBreach(
    batteryChar.coolingType, temperatureInC
  );

  sendToOutputDevice(breachType,alertTarget);
  
}


void sendToOutputDevice(BreachType breachType_en,AlertTarget alertTarget_en)
{
  const unsigned short header = 0xfeed;
  
  if(alertTarget_en == TO_EMAIL)
  {
    SendToEmail(breachType_en);
  }
  else if(alertTarget_en == TO_CONSOLE)
  {
    printf("Sending Info to Console\n");
  }
  else
  {
    printf("%x : %x\n", header, breachType_en);
  }
  
}
