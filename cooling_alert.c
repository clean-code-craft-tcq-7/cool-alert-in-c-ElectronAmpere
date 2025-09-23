#include "./cooling_alert.h"
#include <stdio.h>

// ----------- STEP 2 -----------------
// Minimal code to compile and fail the test in STEP 2 of test_cooling_alert.cpp

const float PASSIVE_COOLING_LIMIT = 40.0;
const float HI_ACTIVE_COOLING_LIMIT = 55.0;

Action battery_temperature_to_action(CoolingType cooling_type,
                                     float temperature) {
  Action action;
  //     // ------- STEP 3 -----------------
  //     // Minimal code to pass tests in test_cooling_alert.cpp

  if (cooling_type == PASSIVE_COOLING && temperature > PASSIVE_COOLING_LIMIT) {
    action.actionType = ALERT_EMAIL;
    snprintf(action.actionBody, sizeof(action.actionBody),
             "Temperature alert: %.1fF", temperature);
    // // Step 4: duplicated logic for active cooling type
    // // } else if (cooling_type == HI_ACTIVE_COOLING && temperature >
    // HI_ACTIVE_COOLING_LIMIT) {
    // //     action.actionType = ALERT_EMAIL;
    // //     snprintf(action.actionBody, sizeof(action.actionBody),
    // //         "Temperature alert: %.1fF", temperature);
    // // Step 4 code ends -------
  } else {
    action.actionType = NO_ALERT;
    action.actionBody[0] = '\0';
  }

  //     //------- STEP 3 code ends -------
  return action;
}

// ----------- STEP 2 code ends -------
