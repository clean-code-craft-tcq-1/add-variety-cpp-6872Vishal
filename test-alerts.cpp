#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
}

TEST_CASE("classifies the breach according to limits") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 36) == TOO_HIGH);
}

TEST_CASE("classifies the breach according to limits 2") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, -1) == TOO_LOW);
}

TEST_CASE("classifies the breach according to limits 3") {
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 56) == TOO_HIGH);
}

TEST_CASE("classifies the breach according to limits 4") {
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, -2.5) == TOO_LOW);
}

TEST_CASE("classifies the breach according to limits 5") {
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 41) == TOO_HIGH);
}

TEST_CASE("classifies the breach according to limits 6") {
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, -5.5) == TOO_LOW);
}

TEST_CASE("checkandAlert unit testing 1")
{
  BatteryCharacter batterytesting_st = { PASSIVE_COOLING,"BMW"};
  REQUIRE(checkAndAlert(TO_CONTROLLER,batterytesting_st,30) == YES_EN);
}

TEST_CASE("checkandAlert unit testing 2")
{
  BatteryCharacter batterytesting_st = { HI_ACTIVE_COOLING,"BMW"};
  REQUIRE(checkAndAlert(TO_CONTROLLER,batterytesting_st,42) == YES_EN);
}

TEST_CASE("checkandAlert unit testing 3")
{
  BatteryCharacter batterytesting_st = { MED_ACTIVE_COOLING,"BMW"};
  REQUIRE(checkAndAlert(TO_CONTROLLER,batterytesting_st,39) == YES_EN);
}

TEST_CASE("checkandAlert unit testing 4")
{
  BatteryCharacter batterytesting_st = { MED_ACTIVE_COOLING,"BMW"};
  REQUIRE(checkAndAlert(TO_CONSOLE,batterytesting_st,39) == YES_EN);
}

TEST_CASE("checkandAlert unit testing 5")
{
  BatteryCharacter batterytesting_st = { PASSIVE_COOLING,"BMW"};
  REQUIRE(checkAndAlert(TO_EMAIL,batterytesting_st,10) == NO_EN);
}

TEST_CASE("checkandAlert unit testing 6")
{
  BatteryCharacter batterytesting_st = { HI_ACTIVE_COOLING,"BMW"};
  REQUIRE(checkAndAlert(TO_EMAIL,batterytesting_st,15) == NO_EN);
}

TEST_CASE("checkandAlert unit testing 7")
{
  BatteryCharacter batterytesting_st = { MED_ACTIVE_COOLING,"BMW"};
  REQUIRE(checkAndAlert(TO_EMAIL,batterytesting_st,13) == NO_EN);
}
