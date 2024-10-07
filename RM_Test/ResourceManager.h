#pragma once
#include <map>
#include "TextureAsset.h"

class ResourceManager {
private:
    std::map<std::string, TextureAsset*> assets;

public:
    TextureAsset* load(const std::string& assetId);
    TextureAsset* get(const std::string& assetId);
    ~ResourceManager();
};


