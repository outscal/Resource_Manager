#pragma once
#include <stdexcept>
#include "Exceptions.h"
#include "Resource.h"

// Public function to load a resource, either by finding it or creating it
template <typename T>
std::shared_ptr<T> ResourceManager::loadResource(const std::string& id, const std::string& filePath)
{
    // Check if the resource is already loaded
    auto existingResource = findResource<T>(id);

    if (existingResource)
        return existingResource; // Return the already loaded resource

    // Create a new resource if not found
    return createResource<T>(id, filePath);
}

// Public function to get an already loaded resource by id
template <typename T>
std::shared_ptr<T> ResourceManager::getResource(const std::string& id)
{
    auto resource = findResource<T>(id);

    if (!resource)
        throw ResourceNotFoundException("Resource not found: " + id);
    
    return resource;
}

// Helper function to find a resource in the map
template <typename T>
std::shared_ptr<T> ResourceManager::findResource(const std::string& id)
{
    auto iterator = resourceMap.find(id);

    if (iterator != resourceMap.end())
    {
        // Use dynamic_pointer_cast to ensure type safety
        auto resource = std::dynamic_pointer_cast<T>(iterator->second);

        if (!resource)
            throw std::runtime_error("Resource type mismatch for id: " + id);

        return resource;
    }
    return nullptr;
}

// Helper function to create and store a new resource
template <typename T>
std::shared_ptr<T> ResourceManager::createResource(const std::string& id, const std::string& filePath)
{
    auto resource = std::make_shared<Resource<T>>(id, filePath);

    // Store the resource in the map
    resourceMap[id] = resource->getAsset();

    // Return the asset for immediate use
    return resource->getAsset();
}
