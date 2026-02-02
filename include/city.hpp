#pragma once
#include "grid.hpp"
#include "building_placer.hpp"
#include "city_stats.hpp"

namespace citygame {

    class CityStats;

    class City {
        public:
            City();
            void update();
            void drawBackground();
            void drawForeground();
            void cityCellToGridCell(int8_t& x, int8_t& y);
            void step();
            Grid& getGrid();
            CityStats& getStats();

            int& getHappinessGaugeReference();
        private:
            raylib::Color backgroundColor;
            int8_t cellOffsetX;
            int8_t cellOffsetY;
            Grid grid;
            CityStats stats;
            int happinessGauge;
    };

}