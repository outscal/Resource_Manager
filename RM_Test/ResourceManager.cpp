#include "ResourceManager.h"
#include <iostream>

// Destructor: Clean up all resources
ResourceManager::~ResourceManager() { unloadAllResources(); }

// Unload a specific resource by its ID
void ResourceManager::unloadResource(const std::string& id)
{
    auto iterator = assets.find(id);
    if (iterator != assets.end())
    {
        delete iterator->second;  // Delete the resource
        assets.erase(iterator);  // Remove it from the map
        std::cout << "Resource " << id << " unloaded." << std::endl;
    }
}

// Unload all resources
void ResourceManager::unloadAllResources()
{
    assets.clear();  // Clear the map
    std::cout << "All resources unloaded." << std::endl;
}
