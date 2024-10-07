#pragma once
#include "Asset.h"

class SoundAsset : public Asset {
public:
    // Constructor
    SoundAsset(const std::string& assetId);

    // Override the load function specific to sounds
    void load() override;
};