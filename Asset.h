// Asset.h
#ifndef ASSET_H
#define ASSET_H

#include <string>

// Base class for all assets
class Asset {
public:
    Asset(const std::string& id) : assetID(id) {}
    virtual ~Asset() = default;

    std::string getID() const { return assetID; }

    // Pure virtual function to load asset data
    virtual void load(const std::string& filePath) = 0;

protected:
    std::string assetID;
};

#endif // ASSET_H
