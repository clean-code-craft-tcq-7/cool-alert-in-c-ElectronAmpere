#ifndef ACTIONS_H
#define ACTIONS_H

typedef struct Actuator {
    void (*actuate)(struct Actuator *self, const char *message);
    void (*destroy)(struct Actuator *self);
} Actuator;

void trigger_alert(Actuator *actuator, const char *msg);

#endif // ACTIONS_H
