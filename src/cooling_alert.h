#pragma once

// ----------- STEP 2 -----------------
// Minimal data-models to pass STEP 2 in test_cooling_alert.cpp

typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING
} CoolingType;

typedef enum {
  NO_ALERT,
  ALERT_EMAIL,
} ActionType;

typedef struct {
  ActionType actionType;
  char actionBody[256];
} Action;

Action battery_temperature_to_action(CoolingType cooling_type,
                                     float temperature);

// ----------- STEP 2 code ends -------
