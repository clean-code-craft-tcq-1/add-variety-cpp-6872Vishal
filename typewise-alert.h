#pragma once

typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING,
  TOTAL_NUM_OF_COOLING
} CoolingType;

typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH
} BreachType;

typedef enum {
  NO_EN,
  YES_EN
}IsAlertTriggered;

BreachType inferBreach(double value, double lowerLimit, double upperLimit);
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL,
  TO_CONSOLE
} AlertTarget;

typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

IsAlertTriggered checkAndAlert(
  AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);


IsAlertTriggered SendToEmail(BreachType TypeOfBreach);
IsAlertTriggered sendToOutputDevice(BreachType breachType_en,AlertTarget alertTarget_en);
