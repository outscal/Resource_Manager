#pragma once
#include "Exceptions.h"

template <typename T>
Resource<T>::Resource(const std::string& id, const std::string& filePath)
{
    assetPtr = std::make_shared<T>(id);
    try {
        assetPtr->load(filePath);
    } catch (const std::exception& e) {
        throw ResourceLoadingException("Failed to load resource: " + id + " from " + filePath);
    }
}
