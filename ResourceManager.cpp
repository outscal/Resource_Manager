#include "ResourceManager.h"
#include <iostream>

void ResourceManager::unloadResource(const std::string& id)
{
    auto iterator = resourceMap.find(id);
    if (iterator != resourceMap.end())
    {
        resourceMap.erase(iterator);
        std::cout << "Resource " << id << " unloaded." << std::endl;
    }
}

void ResourceManager::unloadAllResources()
{
    resourceMap.clear();
    std::cout << "All resources unloaded." << std::endl;
}
