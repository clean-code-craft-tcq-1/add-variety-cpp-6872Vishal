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
BatteryCharacter batterytesting_st = { PASSIVE_COOLING,"BMW"};
TEST_CASE("checkandAlert unit testing 1")
{
  REQUIRE(checkAndAlert(TO_CONTROLLER,batterytesting_st,30) == YES_EN);
}
