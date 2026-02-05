#pragma once
#include "label.hpp"

namespace citygame {

    class Counter : public Label {

        public:
        Counter(raylib::Vector2 pos, int& target, raylib::Color color = raylib::Color::White());
            virtual void update(int scale) override;
        protected:
            int& target;
            int lastNumber;
    };

}