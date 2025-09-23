#include "./actions.h"

// ----------- STEP 6 code starts -------
// Sample implementations of the actuators

int emailSender(const char *to, const char *subject, const char *body,
                const char *from) {
  // TODO: Implementation of email sender
  return 1; // Success
}

Actuators getActuatorSet() {
  Actuators actuators;

  actuators.emailSender = emailSender;

  return actuators;
}

// ----------- STEP 6 code ends -------
