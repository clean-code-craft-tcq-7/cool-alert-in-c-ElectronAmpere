#include "./thresholds.h"

// ----------- STEP 5 -----------------
// Refactor for duplication. Deprecate old interface in favor of new one.

float alertTemperatureForCoolingType(ThermalManagementType type) {
  static const float thresholds[] = {[THERMAL_PASSIVE] = 40.0,
                                     [THERMAL_ACTIVE] = 55.0,
                                     [THERMAL_HYBRID] = 50.0};
  if (type >= THERMAL_PASSIVE && type <= THERMAL_HYBRID) {
    return thresholds[type];
  }
  return 0.0;
}

// ----------- STEP 5 code ends -------
