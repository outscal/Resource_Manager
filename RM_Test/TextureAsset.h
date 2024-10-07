#pragma once
#include "Asset.h"

class TextureAsset : public Asset {
public:
    // Constructor
    TextureAsset(const std::string& assetId);

    // Override the load function specific to textures
    void load() override;
};