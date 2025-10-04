#include "./classify.h"
#include "./thresholds.h"

// ----------- STEP 5 -----------------
// Separation of classification from the email action.

BatteryState classify_battery_state(BatteryDataModel batteryData) {
  BatteryState state = BATTERY_OK;
  float alertThreshold =
      alertTemperatureForCoolingType(batteryData.thermalManagementType);
  if (batteryData.temperature >= alertThreshold) {
    state = BATTERY_ALERT;
  }
  return state;
}

// ----------- STEP 5 code ends -------
