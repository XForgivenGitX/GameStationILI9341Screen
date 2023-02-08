#ifndef ENCODER_H
#define ENCODER_H

#include <stdint.h>

#define SHORTPRESS 1
#define LONGPRESS 2

extern int encoderVal;
int getEncoderSteps();
void readEncoderISR();
bool   pollControlSwitches(void);

#endif
