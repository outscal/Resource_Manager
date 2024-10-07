#include "TextureAsset.h"
#include <iostream>

// Constructor implementation
TextureAsset::TextureAsset(const std::string& assetId) : Asset(assetId) {}

// Implement the load function specific to textures
void TextureAsset::load() {
    // Simulate texture loading from file
    std::cout << "Loading texture: " << id << std::endl;
}