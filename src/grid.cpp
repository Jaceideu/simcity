#include "grid.hpp"
#include "grid_cell.hpp"
#include <memory>

namespace citygame {

    Grid::Grid(const std::int8_t width, const std::int8_t height, const std::int8_t cellSize) 
        :width(width), height(height), cellSize(cellSize) {
        data.resize(width * height);

        for (auto& cell : data) {
            cell = std::make_unique<GridCell>(raylib::Rectangle{});
        }
    }

    void Grid::draw(raylib::Vector2 position) {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                GridCell* cell = data[vecToIndex(x, y)].get();
                raylib::Rectangle rect(x*cellSize + position.x, y*cellSize + position.y, cellSize, cellSize);
                cell->draw(rect);
            }
        }
    }

    GridCell* Grid::getCell(const int8_t x, const int8_t y) const {

        if (!checkInBounds(x, y)) return nullptr;

        return data[vecToIndex(x, y)].get();
    }

    void Grid::setCell(const int8_t x, const int8_t y, std::unique_ptr<GridCell> cell) {

        if (!checkInBounds(x, y)) return;

        data[vecToIndex(x, y)] = std::move(cell);
    }

    std::int8_t Grid::getWidth() const {
        return width;
    }

    std::int8_t Grid::getHeight() const {
        return height;
    }

    std::int8_t Grid::getCellSize() const {
        return cellSize;
    }

    bool Grid::checkInBounds(const int8_t x, const int8_t y) const {
        if (x < 0) return false;
        if (x > width - 1) return false;
        if (y < 0) return false;
        if (y > height - 1) return false;

        return true;
    }

    std::int16_t Grid::vecToIndex(const int8_t x, const int8_t y) const {
        return y * width + x % width;
    }

}