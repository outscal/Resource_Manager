// GameLoop.cpp
#include "GameLoop.h"
#include "ResourceManager.h"
#include "TextureAsset.h"
#include "SoundAsset.h"
#include <iostream>

#include "Exceptions.h"

void GameLoop::run()
{
    initialize();

    while (isRunning) {
        update();
        render();
    }

    shutdown();
}

void GameLoop::initialize()
{
    // Initialize Resource Manager:
    std::cout << "Initializing game..." << std::endl;
    resource_manager = new ResourceManager();
    
    // Try Loading Resources:
    try {
        resource_manager->loadResource<TextureAsset>("playerTexture", "assets/texture1.png");
        resource_manager->loadResource<SoundAsset>("backgroundMusic", "assets/sound1.wav");
    } catch (const std::exception& exception) {
        std::cerr << exception.what() << std::endl;
        isRunning = false;
    }
}

void GameLoop::update()
{
    // Game logic goes here
    static int frameCount = 1;
    frameCount++;
    
    if (frameCount > 5)
        isRunning = false; // Stop after 5 frames for demonstration
}

void GameLoop::render()
{
    // Rendering logic goes here
    try {
        auto texture = resource_manager->getResource<TextureAsset>("playerTexture");
        texture->bind();
        
        // Simulate drawing
        std::cout << "Drawing player with texture ID: " << texture->getID() << std::endl;
        texture->unbind();
    } catch (const ResourceNotFoundException& resource_not_found_exception) {
        std::cerr << resource_not_found_exception.what() << std::endl;
    }
}

void GameLoop::shutdown()
{
    std::cout << "Shutting down game..." << std::endl;
    // Unload resources
    resource_manager->unloadAllResources();
}
