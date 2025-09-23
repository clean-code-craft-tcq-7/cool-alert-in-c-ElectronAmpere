#include "./chain.h"
#include "./classify.h"
#include "./thresholds.h"

// ----------- STEP 6 code starts -------

void batteryDataToAction(BatteryDataModel batteryData,
                         Actuators (*actuators)()) {
  BatteryState state = classify_battery_state(batteryData);
  if (state == BATTERY_ALERT) {
    actuators().emailSender("manager@battery.com", "Battery Alert",
                            "Battery temperature is too high",
                            "noreply@battery.com");
  }
}

// ----------- STEP 6 code ends -------
