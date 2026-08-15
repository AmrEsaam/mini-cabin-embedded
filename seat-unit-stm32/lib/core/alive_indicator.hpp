#pragma once
#include "hal_interface.hpp"

class AliveIndicator {
    public: 
    enum class State{
    Booting,
    Alive,
    Error
    };

    AliveIndicator(IHalInterface* hal);

    void update();

    private:
    IHalInterface* hal;
    State currentState;
    uint32_t bootStartTimeMs;
};

