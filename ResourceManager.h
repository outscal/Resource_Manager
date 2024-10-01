// ResourceManager.h
#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <unordered_map>
#include <string>
#include <memory>
#include "Asset.h"

class ResourceManager {
private:
    std::unordered_map<std::string, std::shared_ptr<Asset>> resourceMap;
    
public:
    ResourceManager() = default;
    ~ResourceManager() = default;

    template <class T>
    std::shared_ptr<T> findResource(const std::string& id);
    template <class T>
    std::shared_ptr<T> createResource(const std::string& id, const std::string& filePath);
    template <typename T>
    std::shared_ptr<T> loadResource(const std::string& id, const std::string& filePath);
    template <typename T>
    std::shared_ptr<T> getResource(const std::string& id);

    void unloadResource(const std::string& id);
    void unloadAllResources();
};

#include "ResourceManager.inl"

#endif // RESOURCE_MANAGER_H
