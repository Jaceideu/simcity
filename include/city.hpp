#pragma once
#include "grid.hpp"
#include "mouse_handler.hpp"
#include <tuple>

namespace citygame {

    class City {
        public:
            City();
            void update();
            void draw();
            void cityCellToGridCell(int8_t& x, int8_t& y);
            Grid& getGrid();
        private:
            raylib::Color backgroundColor;
            int8_t cellOffsetX;
            int8_t cellOffsetY;
            Grid grid;
            MouseHandler mouseHandler;
    };

}