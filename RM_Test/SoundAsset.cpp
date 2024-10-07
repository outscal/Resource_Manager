#include "SoundAsset.h"
#include <iostream>

// Constructor implementation
SoundAsset::SoundAsset(const std::string& assetId) : Asset(assetId) {}

// Implement the load function specific to sounds
void SoundAsset::load() {
    std::cout << "Loading sound: " << id << std::endl;
    // Simulate sound file loading
}