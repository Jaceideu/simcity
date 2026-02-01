#include "city.hpp"
#include "constants.hpp"

namespace citygame {

    City::City() 
        :backgroundColor(CITY_BACKGROUND_COLOR), cellOffsetX(CITY_SCREEN_CELL_OFFSET), cellOffsetY(CITY_SCREEN_CELL_OFFSET), grid(CITY_GRID_WIDTH, CITY_GRID_HEIGHT, CELL_SIZE), mouseHandler(this) {

    }

    void City::update() {
        mouseHandler.update();
    }

    void City::draw() {
        raylib::Rectangle rect(cellOffsetX * grid.getCellSize(), cellOffsetY * grid.getCellSize(), grid.getWidth() * CELL_SIZE, grid.getHeight() * CELL_SIZE);
        rect.Draw(backgroundColor);
        mouseHandler.draw();
        grid.draw(raylib::Vector2(cellOffsetX * grid.getCellSize(), cellOffsetY * grid.getCellSize()));
    }

    void City::setGridCell(const int8_t x, const int8_t y, std::unique_ptr<Building> newBuilding) {
        grid.setCell(x - cellOffsetX, y - cellOffsetY, std::move(newBuilding));
    }

    Grid& City::getGrid() {
        return grid;
    }
    
}

