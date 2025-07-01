#include "MotorDriver.h"

MotorDriver::MotorDriver(int ain1, int ain2, int bin1, int bin2, int stby)
    : _ain1(ain1), _ain2(ain2), _bin1(bin1), _bin2(bin2), _stby(stby),
      _speedA(255), _speedB(255) {}

void MotorDriver::begin() {
    pinMode(_ain1, OUTPUT);
    pinMode(_ain2, OUTPUT);
    pinMode(_bin1, OUTPUT);
    pinMode(_bin2, OUTPUT);
    pinMode(_stby, OUTPUT);
    enableDriver(true);
}

void MotorDriver::enableDriver(bool enable) {
    digitalWrite(_stby, enable ? HIGH : LOW);
}

void MotorDriver::driveForward(int speedA, int speedB) {
    enableDriver(true);
    analogWrite(_ain1, speedA);
    digitalWrite(_ain2, LOW);
    analogWrite(_bin1, speedB);
    digitalWrite(_bin2, LOW);
}

void MotorDriver::driveBackward(int speedA, int speedB) {
    enableDriver(true);
    digitalWrite(_ain1, LOW);
    analogWrite(_ain2, speedA);
    digitalWrite(_bin1, LOW);
    analogWrite(_bin2, speedB);
}

void MotorDriver::stop() {
    enableDriver(false);
}

void MotorDriver::setSpeeds(int speedA, int speedB) {
    _speedA = speedA;
    _speedB = speedB;
}
