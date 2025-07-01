#pragma once
#include <Arduino.h>
#include "esp_camera.h"
#include "base64.h"

class CameraStream {
public:
    CameraStream(
        int pwdn, int reset, int xclk, int siod, int sioc,
        int y2, int y3, int y4, int y5, int y6, int y7, int y8, int y9,
        int vsync, int href, int pclk
    );

    bool begin();
    String captureBase64Jpeg();
    void printBase64ToSerial();

private:
    int _pwdn, _reset, _xclk, _siod, _sioc;
    int _y2, _y3, _y4, _y5, _y6, _y7, _y8, _y9;
    int _vsync, _href, _pclk;

    bool initCamera();
};
