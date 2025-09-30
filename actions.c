#include "actions.h"

void trigger_alert(Actuator *actuator, const char *msg) {
    if (actuator && actuator->actuate) {
        actuator->actuate(actuator, msg);
    }
}
