#include "typewise-alert.h"
#include <stdio.h>

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

BreachType classifyTemperatureBreach(
    CoolingType coolingType, double temperatureInC) {
  
  if(temperatureInC < LowerLimitValues[coolingType]) {
    return TOO_LOW;
  }
  if(temperatureInC > LowerLimitValues[coolingType]) {
    return TOO_HIGH;
  }
  return NORMAL;
  
//   int lowerLimit = 0;
//   int upperLimit = 0;
//   switch(coolingType) {
//     case PASSIVE_COOLING:
//       lowerLimit = 0;
//       upperLimit = 35;
//       break;
//     case HI_ACTIVE_COOLING:
//       lowerLimit = 0;
//       upperLimit = 45;
//       break;
//     case MED_ACTIVE_COOLING:
//       lowerLimit = 0;
//       upperLimit = 40;
//       break;
//   }
//   return inferBreach(temperatureInC, lowerLimit, upperLimit);
}

void checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {

  BreachType breachType = classifyTemperatureBreach(
    batteryChar.coolingType, temperatureInC
  );

  sendToOutputDevice(breachType,alertTarget);
  
//   switch(alertTarget) {
//     case TO_CONTROLLER:
//       sendToController(breachType);
//       break;
//     case TO_EMAIL:
//       sendToEmail(breachType);
//       break;
//   }
}

void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
  string CharBreachType[2] = {"Too Low", "Too High"};
  if(breachType != NORMAL)
  {
  printf("To: %s\n", recepient);
  printf("Hi, the temperature is %x\n",breachType);
  }
//   switch(breachType) {
//     case TOO_LOW:
//       printf("To: %s\n", recepient);
//       printf("Hi, the temperature is too low\n");
//       break;
//     case TOO_HIGH:
//       printf("To: %s\n", recepient);
//       printf("Hi, the temperature is too high\n");
//       break;
//     case NORMAL:
//       break;
//   }
}

void sendToOutputDevice(BreachType breachType_en,AlertTarget alertTarget_en)
{
  const unsigned short header = 0xfeed;
  const char* recepient = "a.b@c.com";
  if(alertTarget_en == TO_EMAIL)
  {
      if(breachType != NORMAL)
      {
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is %x\n",breachType);
      }
  }
  else
  {
    printf("%x : %x\n", header, breachType);
  }
  
}
