#pragma once
#include <raylib-cpp.hpp>
#include <cstdint>

namespace citygame {

    class City;

    class MouseHandler {
        public:
            MouseHandler(City* city);
            void update();
            void draw();
        private:
            City* city;
            raylib::Rectangle selectRectangle;
            raylib::Color selectColor;
            int8_t cellX;
            int8_t cellY;
    };

}