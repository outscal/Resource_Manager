// TextureAsset.h
#ifndef TEXTURE_ASSET_H
#define TEXTURE_ASSET_H

#include "Asset.h"
#include <string>

class TextureAsset : public Asset {
public:
    TextureAsset(const std::string& id);
    ~TextureAsset();

    void load(const std::string& filePath) override;

    // Additional methods specific to textures
    void bind();
    void unbind();

private:
    unsigned int textureID; // Identifier for the GPU texture
};

#endif // TEXTURE_ASSET_H
