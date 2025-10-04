#include <gtest/gtest.h>
extern "C" {
#include "../src/chain.h"
}

// Variables to capture email parameters from the stub
const char *captured_message = nullptr;

// Stub actuator struct
typedef struct StubActuator {
  Actuator base;
} StubActuator;

// Stub actuate function, captures the message passed
void stub_actuate(Actuator *self, const char *message) {
  captured_message = message;
}

// Create the stub actuator instance
Actuator *create_stub_actuator() {
  StubActuator *stub = (StubActuator *)malloc(sizeof(StubActuator));
  stub->base.actuate = stub_actuate;
  stub->base.destroy = [](Actuator *self) { free(self); };
  return &stub->base;
}

TEST(ChainTest, BatteryDataToAction) {
  BatteryDataModel batteryData = {10342, THERMAL_HYBRID, 60};
  captured_message = nullptr;

  Actuator *stub_actuator = create_stub_actuator();

  batteryDataToAction(batteryData, stub_actuator);

  ASSERT_STREQ(captured_message, "Battery temperature is too high");

  // Clean up
  stub_actuator->destroy(stub_actuator);
}
