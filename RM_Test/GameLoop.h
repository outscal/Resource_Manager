#pragma once

class GameLoop {
public:
    void initialize();
    void update();
    void render();
    void shutdown();
    void run();

private:
    // ResourceManager* resource_manager = nullptr;
    bool isRunning = true;
};
