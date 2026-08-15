#pragma once
#include <cstdint>

class IHalInterface {
    public: 
    virtual void setLed(bool on) = 0;
    virtual void sendUartMessage(const char* message) = 0;
    virtual uint32_t getCurrentTimeMs()= 0;
    virtual ~IHalInterface() = default;
};