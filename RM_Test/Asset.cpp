#include "Asset.h"

// Constructor implementation
Asset::Asset(const std::string& assetId) : id(assetId) {}

// Virtual destructor implementation
Asset::~Asset() = default;

// Getter implementation
std::string Asset::getId() const { return id; }
