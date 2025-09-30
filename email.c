#include "email.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct EmailActuator {
    Actuator base;
    char *email_address;
} EmailActuator;

static void email_actuate(Actuator *self, const char *message) {
    EmailActuator *email_actuator = (EmailActuator *)self;
    // Simulate sending email
    printf("[EMAIL] Sending alert to %s: %s\n", email_actuator->email_address, message);
}

static void email_destroy(Actuator *self) {
    EmailActuator *email_actuator = (EmailActuator *)self;
    free(email_actuator->email_address);
    free(email_actuator);
}

Actuator* email_actuator_create(const char *email_address) {
    EmailActuator *actuator = malloc(sizeof(EmailActuator));
    if (!actuator) return NULL;
    actuator->email_address = strdup(email_address);
    actuator->base.actuate = email_actuate;
    actuator->base.destroy = email_destroy;
    return (Actuator *)actuator;
}
