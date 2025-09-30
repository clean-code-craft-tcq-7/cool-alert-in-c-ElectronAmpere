#include "./chain.h"
#include "./classify.h"
#include "./thresholds.h"

// ----------- STEP 6 code starts -------

void batteryDataToAction(BatteryDataModel batteryData, Actuator *actuator) {
  BatteryState state = classify_battery_state(batteryData);
  if (state == BATTERY_ALERT && actuator && actuator->actuate) {
    actuator->actuate(actuator, "Battery temperature is too high");
  }
}


// ----------- STEP 6 code ends -------
