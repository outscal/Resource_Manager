#include "GameLoop.h"
#include <iostream>

void GameLoop::initialize() {
    std::cout << "Initializing game resources..." << std::endl;
    resource_manager = new ResourceManager();
    resource_manager->load("player_texture");
    resource_manager->load("enemy_texture");
}

void GameLoop::update() {
    std::cout << "Updating game logic..." << std::endl;
}

void GameLoop::render() {
    std::cout << "Rendering game..." << std::endl;
}

void GameLoop::shutdown() {
    std::cout << "Shutting down the game..." << std::endl;
    delete resource_manager;
}

void GameLoop::run() {
    while (isRunning) {
        update();
        render();
        isRunning = false;  // For now, we'll shut down after one iteration
    }
    shutdown();
}
