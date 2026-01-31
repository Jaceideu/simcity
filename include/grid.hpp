#pragma once
#include <vector>
#include <cstdint>
#include <memory>
#include <raylib-cpp.hpp>
#include "building.hpp"

namespace citygame {

    class Grid {
        public:
            Grid(const std::int8_t width, const std::int8_t height, const std::int8_t cellSize);
            void Draw(raylib::Vector2 position);
            void SetCell(const int8_t x, const int8_t y, std::unique_ptr<Building> newBuilding);
            std::int8_t getWidth();
            std::int8_t getHeight();
            std::int8_t getCellSize();
        private:
            std::int16_t vecToIndex(const int8_t x, const int8_t y);
            std::vector<std::unique_ptr<Building>> data; 
            std::int8_t width;
            std::int8_t height;
            std::int8_t cellSize;
    };

}