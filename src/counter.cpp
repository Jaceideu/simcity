#include "counter.hpp"
#include <string>

namespace citygame {
    Counter::Counter(raylib::Vector2 pos, int& target, raylib::Color color)
        :Label(pos, "0", color), target(target), lastNumber(0) {

    }

    void Counter::update(int scale) {
        if (!isVisible) return;
        if (target != lastNumber) {
            lastNumber = target;
            text.text = std::to_string(target);
        }
    }
}

