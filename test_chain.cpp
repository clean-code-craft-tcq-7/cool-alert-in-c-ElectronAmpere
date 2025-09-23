#include <gtest/gtest.h>
extern "C" {
#include "./chain.h"
}

// ----------- STEP 6 code starts -------

const char *email_to = 0;
const char *email_subject = 0;
const char *email_body = 0;
const char *email_from = 0;

int emailSenderStub(const char *to, const char *subject, const char *body,
                    const char *from) {
  email_to = to;
  email_subject = subject;
  email_body = body;
  email_from = from;
  return 1; // Success
}

Actuators actuatorStubSet() {
  Actuators actuators;
  actuators.emailSender = emailSenderStub;
  return actuators;
}

TEST(ChainTest, BatteryDataToAction) {
  BatteryDataModel batteryData = {10342, THERMAL_HYBRID, 60};

  batteryDataToAction(batteryData, actuatorStubSet);

  ASSERT_STREQ(email_to, "manager@battery.com");
}

// ----------- STEP 6 code ends -------
