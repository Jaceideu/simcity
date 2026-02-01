#pragma once
#include "grid.hpp"
#include "building_placer.hpp"

namespace citygame {

    class CityStats;

    class City {
        public:
            City();
            void update();
            void drawBackground();
            void drawForeground();
            void cityCellToGridCell(int8_t& x, int8_t& y);
            void step(CityStats& stats);
            Grid& getGrid();
        private:
            raylib::Color backgroundColor;
            int8_t cellOffsetX;
            int8_t cellOffsetY;
            Grid grid;
    };

}