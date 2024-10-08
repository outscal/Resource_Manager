#pragma once
#include <string>

class Asset {
protected:
    // Unique identifier for the asset
    std::string id;

public:
    // Constructor with an asset identifier
    Asset(const std::string& assetId);

    // Virtual destructor to ensure proper cleanup in derived classes
    virtual ~Asset();

    // Pure virtual function for loading the asset
    virtual void load() = 0;

    // Getter for the asset ID
    std::string getId() const;
};