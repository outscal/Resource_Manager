// SoundAsset.h
#ifndef SOUND_ASSET_H
#define SOUND_ASSET_H

#include "Asset.h"
#include <string>

class SoundAsset : public Asset {
public:
    SoundAsset(const std::string& id);
    ~SoundAsset();

    void load(const std::string& filePath) override;

    // Additional methods specific to sounds
    void play();
    void stop();

private:
    unsigned int soundID; // Identifier for the sound buffer
};

#endif // SOUND_ASSET_H
