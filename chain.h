#pragma once

#include "./actions.h"
#include "./data_model.h"

// ----------- STEP 6 -----------------
// Chain theBatteryDataModel to Action

void batteryDataToAction(BatteryDataModel batteryData, Actuator *actuator);

// ----------- STEP 6 code ends -------
