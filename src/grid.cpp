#include "grid.hpp"
#include "building.hpp"
#include <memory>

namespace citygame {

    Grid::Grid(const std::int8_t width, const std::int8_t height, const std::int8_t cellSize) 
        :width(width), height(height), cellSize(cellSize) {
        data.resize(width * height);

        for (auto& cell : data) {
            cell = std::make_unique<Building>(raylib::Rectangle{});
        }
    }

    void Grid::Draw(raylib::Vector2 position) {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                Building* building = data[vecToIndex(x, y)].get();
                raylib::Rectangle rect(x*16 + position.x, y*16 + position.y, cellSize, cellSize);
                building->draw(rect);
            }
        }
    }

    void Grid::SetCell(const int8_t x, const int8_t y, std::unique_ptr<Building> newBuilding) {
        data[vecToIndex(x, y)] = std::move(newBuilding);
    }

    std::int8_t Grid::getWidth() {
        return width;
    }

    std::int8_t Grid::getHeight() {
        return height;
    }

    std::int8_t Grid::getCellSize() {
        return cellSize;
    }

    std::int16_t Grid::vecToIndex(const int8_t x, const int8_t y) {
        return y * width + x % width;
    }

}