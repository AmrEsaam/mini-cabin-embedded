#pragma once
#include "hal_interface.hpp"
#include <cstdint>

class AliveIndicator {
    public: 
    enum class State{
    Booting,
    Alive,
    Error
    };

    AliveIndicator(IHalInterface* hal);

    void update();
    void notifyBootComplete();

    private:
    IHalInterface* hal;
    State currentState;
    uint32_t bootStartTimeMs;
    uint32_t lastToggleTimeMs;
    bool ledIsOn;
};

