#pragma once

// ----------- STEP 6 -----------------
// Actuators

typedef struct {
  int (*emailSender)(const char *to, const char *subject, const char *body,
                     const char *from);
} Actuators;

Actuators getActuatorSet();

// ----------- STEP 6 code ends -------
