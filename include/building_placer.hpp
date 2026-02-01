#pragma once
#include "raylib-cpp.hpp"
#include <cstdint>

namespace citygame {

    class City;

    class BuildingPlacer {
        public:
            BuildingPlacer(City* city);
            void update();
            void draw();
            void setBuildingIndex(int i);
        private:
            City* city;
            raylib::Rectangle selectRectangle;
            raylib::Color selectColor;
            int8_t cellX;
            int8_t cellY;
            int currBuildingIndex;
    };

}