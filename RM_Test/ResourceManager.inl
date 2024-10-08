#pragma once
#include <iostream>

// Load a resource or create it if it doesn't exist
template <typename T>
T* ResourceManager::loadResource(const std::string& id)
{
    // Check if the resource is already loaded
    auto existingResource = findResource<T>(id);
    
    if (existingResource)
        return existingResource;  // Return the already loaded resource

    // Create a new resource if not found
    return createResource<T>(id);
}

// Public function to get an already loaded resource by id
template <typename T>
T* ResourceManager::getResource(const std::string& id)
{
    auto resource = findResource<T>(id);
    
    if (resource == nullptr)
        std::cout << "Resource not found: " << id;  // Resource doesn't exist
    
    return resource;
}

// Find a resource in the map
template <typename T>
T* ResourceManager::findResource(const std::string& id) {
    auto iterator = assets.find(id);
    if (iterator != assets.end()) {
        // Use dynamic_cast to ensure type safety
        return dynamic_cast<T*>(iterator->second);
    }
    return nullptr;
}

// Create and store a new resource in the map
template <typename T>
T* ResourceManager::createResource(const std::string& id) {
    T* resource = new T(id);  // Create the resource
    resource->load();  // Assuming T has a load() function
    assets[id] = resource;  // Add the resource to the map
    return resource;
}
