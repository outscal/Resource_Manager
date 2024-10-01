#pragma once
#include "ResourceManager.h"

class GameLoop {
private:
    ResourceManager* resource_manager = nullptr;
    bool isRunning = true;

    void initialize();
    void update();
    void render();
    void shutdown();

public:
    void run();

};
