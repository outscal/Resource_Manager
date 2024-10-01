#include <memory>
#include <string>

template <typename T>
class Resource {
private:
    std::shared_ptr<T> assetPtr;

public:
    Resource(const std::string& id, const std::string& filePath);

    std::shared_ptr<T> getAsset() const { return assetPtr; }

};

#include "Resource.inl"
