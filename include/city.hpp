#pragma once
#include "grid.hpp"
#include "mouse_handler.hpp"

namespace citygame {

    class City {
        public:
            City();
            void update();
            void draw();
            void setGridCell(const int8_t x, const int8_t y, std::unique_ptr<Building> newBuilding);
            Grid& getGrid();
        private:
            raylib::Color backgroundColor;
            int8_t cellOffsetX;
            int8_t cellOffsetY;
            Grid grid;
            MouseHandler mouseHandler;
    };

}