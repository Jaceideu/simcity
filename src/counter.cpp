#include "counter.hpp"
#include <string>

namespace citygame {
    Counter::Counter(raylib::Vector2 pos, int& target)
        :Label(pos, "0"), target(target) {

    }

    void Counter::update(int scale) {
        text.text = std::to_string(target);
    }
}

