#pragma once
#include <vector>
#include <cstdint>
#include <memory>
#include "raylib-cpp.hpp"
#include "grid_cell.hpp"

namespace citygame {

    class Grid {
        public:
            Grid(const std::int8_t width, const std::int8_t height, const std::int8_t cellSize);
            void draw(raylib::Vector2 position);
            GridCell* getCell(const int8_t x, const int8_t y) const;
            void setCell(const int8_t x, const int8_t y, std::unique_ptr<GridCell> newCell);
            std::int8_t getWidth() const;
            std::int8_t getHeight() const;
            std::int8_t getCellSize() const;

        private:
            bool checkInBounds(const int8_t x, const int8_t y) const;
            std::int16_t vecToIndex(const int8_t x, const int8_t y) const;
            std::vector<std::unique_ptr<GridCell>> data; 
            std::int8_t width;
            std::int8_t height;
            std::int8_t cellSize;
    };

}