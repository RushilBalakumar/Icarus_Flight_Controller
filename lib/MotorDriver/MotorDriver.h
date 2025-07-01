#pragma once
#include <Arduino.h>

class MotorDriver {
public:
    MotorDriver(int ain1, int ain2, int bin1, int bin2, int stby);

    void begin();
    void driveForward(int speedA, int speedB);
    void driveBackward(int speedA, int speedB);
    void stop();
    void setSpeeds(int speedA, int speedB);

private:
    int _ain1, _ain2, _bin1, _bin2, _stby;
    int _speedA, _speedB;

    void enableDriver(bool enable);
};
