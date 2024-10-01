// Utilities.cpp
#include "Utilities.h"
#include <random>

namespace Utilities {
    unsigned int generateRandomID() {
        static std::mt19937 generator(static_cast<unsigned int>(time(nullptr)));
        static std::uniform_int_distribution<unsigned int> distribution(1000, 9999);
        return distribution(generator);
    }
}