#include <gtest/gtest.h>
extern "C" {
#include "./thermal_management_types.h"
#include "./thresholds.h"
}

// ----------- STEP 5 -----------------
// Refactor for duplication. Deprecate old interface in favor of new one.
// Distinguish thresholds per cooling type

TEST(ThresholdTest, CoolingDependentThresholds) {
  float passiveLimit = alertTemperatureForCoolingType(THERMAL_PASSIVE);
  float hiActiveLimit = alertTemperatureForCoolingType(THERMAL_ACTIVE);
  float medActiveLimit = alertTemperatureForCoolingType(THERMAL_HYBRID);

  ASSERT_TRUE(passiveLimit < medActiveLimit);
  ASSERT_TRUE(medActiveLimit < hiActiveLimit);
}

// ----------- STEP 5 code ends -------
