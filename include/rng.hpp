#pragma once
#include <random>

namespace citygame {

    inline int RandomInt(int min, int max) {
        static thread_local std::mt19937 rng{std::random_device{}()};
        std::uniform_int_distribution<int> dist(min, max);
        return dist(rng);
    }

}

