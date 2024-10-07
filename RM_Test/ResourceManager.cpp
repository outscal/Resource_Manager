#include "ResourceManager.h"

TextureAsset* ResourceManager::load(const std::string& assetId) {
    if (assets.find(assetId) != assets.end()) {
        return assets[assetId];
    }
    TextureAsset* texture = new TextureAsset(assetId);
    texture->load();
    assets[assetId] = texture;
    return texture;
}

ResourceManager::~ResourceManager() {
    for (auto& pair : assets) {
        delete pair.second;
    }
}