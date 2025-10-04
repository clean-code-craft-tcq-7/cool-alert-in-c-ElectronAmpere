#include "./cooling_alert.h"
#include <stdio.h>

// ----------- STEP 2 -----------------
// Minimal code to compile and fail the test in STEP 2 of test_cooling_alert.cpp
typedef struct {
  CoolingType type;
  const float limit;
} CoolingLimit_t;

CoolingLimit_t limits[] = {{PASSIVE_COOLING, 40.0}, {HI_ACTIVE_COOLING, 55.0}};

float get_cooling_limit(CoolingType type) {
  for (int i = 0; i < sizeof(limits) / sizeof(limits[0]); i++) {
    if (limits[i].type == type)
      return limits[i].limit;
  }
  return 0.0; // or error
}

Action battery_temperature_to_action(CoolingType cooling_type,
                                     float temperature) {
  Action action;

  float limit = get_cooling_limit(cooling_type);

  if (temperature > limit) {
    action.actionType = ALERT_EMAIL;
    snprintf(action.actionBody, sizeof(action.actionBody),
             "Temperature alert: %.1fF", temperature);
  } else {
    action.actionType = NO_ALERT;
    action.actionBody[0] = '\0';
  }

  return action;
}

// ----------- STEP 2 code ends -------
