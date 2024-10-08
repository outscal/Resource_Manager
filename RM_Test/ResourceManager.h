#pragma once
#include <map>
#include "TextureAsset.h"

class ResourceManager {
private:
    std::map<std::string, Asset*> assets;

public:
    ResourceManager() = default;
    ~ResourceManager();

    template <class T>
    T* findResource(const std::string& id);
    template <class T>
    T* createResource(const std::string& id);
    template <typename T>
    T* loadResource(const std::string& id);
    template <typename T>
    T* getResource(const std::string& id);

    // Non-template methods for unloading resources
    void unloadResource(const std::string& id);
    void unloadAllResources();
};

#include "ResourceManager.inl"