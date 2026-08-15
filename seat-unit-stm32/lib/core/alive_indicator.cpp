#include "alive_indicator.hpp"
#include <cstdint>

AliveIndicator::AliveIndicator (IHalInterface* hal)
{
    this->hal = hal;
    currentState = State::Booting;
    bootStartTimeMs = hal->getCurrentTimeMs();
    lastToggleTimeMs = 0;
    ledIsOn = false;
}

void AliveIndicator::update()
{
    uint32_t timeSinceBoot = hal->getCurrentTimeMs() - bootStartTimeMs;
    if (timeSinceBoot >= 5000) {
        currentState = State::Error;
        hal->sendUartMessage("ERROR: Boot timeout exceeded");
    }
}