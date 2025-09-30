#include "charge_rate.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct ChargeRateActuator {
    Actuator base;
    int limit;
} ChargeRateActuator;

static void charge_rate_actuate(Actuator *self, const char *message) {
    ChargeRateActuator *actuator = (ChargeRateActuator *)self;
    // Simulate restricting charge rate
    printf("[CHARGE RATE] Restricting charging rate to %d%% due to alert: %s\n", actuator->limit, message);
    // TODO: Add real hardware interaction here
}

static void charge_rate_destroy(Actuator *self) {
    free(self);
}

Actuator* charge_rate_actuator_create(int limit) {
    ChargeRateActuator *actuator = malloc(sizeof(ChargeRateActuator));
    if (!actuator) return NULL;
    actuator->limit = limit;
    actuator->base.actuate = charge_rate_actuate;
    actuator->base.destroy = charge_rate_destroy;
    return (Actuator *)actuator;
}
