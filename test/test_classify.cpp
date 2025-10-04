#include <gtest/gtest.h>
extern "C" {
#include "../src/classify.h"
}

// ----------- STEP 5 -----------------
// Separation of classification from the email action.

TEST(ClassifyTest, BatteryOk) {
  BatteryDataModel batteryData = {10567, THERMAL_PASSIVE, 25};
  BatteryState state = classify_battery_state(batteryData);
  ASSERT_EQ(state, BATTERY_OK);
}

TEST(ClassifyTest, BatteryAlert) {
  BatteryDataModel batteryData = {21389, THERMAL_HYBRID, 60};
  BatteryState state = classify_battery_state(batteryData);
  ASSERT_EQ(state, BATTERY_ALERT);
}

// ----------- STEP 5 code ends -------
