#include "CameraStream.h"

CameraStream::CameraStream(
    int pwdn, int reset, int xclk, int siod, int sioc,
    int y2, int y3, int y4, int y5, int y6, int y7, int y8, int y9,
    int vsync, int href, int pclk
) : _pwdn(pwdn), _reset(reset), _xclk(xclk), _siod(siod), _sioc(sioc),
    _y2(y2), _y3(y3), _y4(y4), _y5(y5), _y6(y6), _y7(y7), _y8(y8), _y9(y9),
    _vsync(vsync), _href(href), _pclk(pclk) {}

bool CameraStream::begin() {
    return initCamera();
}

bool CameraStream::initCamera() {
    camera_config_t config;
    config.ledc_channel = LEDC_CHANNEL_0;
    config.ledc_timer   = LEDC_TIMER_0;

    config.pin_pwdn     = _pwdn;
    config.pin_reset    = _reset;
    config.pin_xclk     = _xclk;
    config.pin_sscb_sda = _siod;
    config.pin_sscb_scl = _sioc;

    config.pin_d0       = _y2;
    config.pin_d1       = _y3;
    config.pin_d2       = _y4;
    config.pin_d3       = _y5;
    config.pin_d4       = _y6;
    config.pin_d5       = _y7;
    config.pin_d6       = _y8;
    config.pin_d7       = _y9;

    config.pin_vsync    = _vsync;
    config.pin_href     = _href;
    config.pin_pclk     = _pclk;

    config.xclk_freq_hz = 20000000;
    config.pixel_format = PIXFORMAT_JPEG;

    if(psramFound()){
        config.frame_size = FRAMESIZE_QQVGA;
        config.jpeg_quality = 10;
        config.fb_count = 2;
    } else {
        config.frame_size = FRAMESIZE_QQVGA;
        config.jpeg_quality = 12;
        config.fb_count = 1;
    }

    esp_err_t err = esp_camera_init(&config);
    if (err != ESP_OK) {
        Serial.printf("Camera init failed with error 0x%x\n", err);
        return false;
    }

    return true;
}

String CameraStream::captureBase64Jpeg() {
    camera_fb_t * fb = esp_camera_fb_get();
    if (!fb) {
        Serial.println("Camera capture failed");
        return "";
    }

    String encoded = base64::encode(fb->buf, fb->len);
    esp_camera_fb_return(fb);
    return encoded;
}

void CameraStream::printBase64ToSerial() {
    String b64 = captureBase64Jpeg();
    if (!b64.isEmpty()) {
        Serial.println("-----BEGIN IMAGE-----");
        Serial.println(b64);
        Serial.println("------END IMAGE------");
    }
}
