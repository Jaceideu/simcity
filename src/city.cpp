#include "city.hpp"
#include "constants.hpp"

namespace citygame {

    City::City() 
        :backgroundColor(0x234975), screenPosition(CELL_SIZE, CELL_SIZE), grid(CITY_GRID_WIDTH, CITY_GRID_HEIGHT, CELL_SIZE), mouseHandler(&grid) {

    }

    void City::Update() {
        mouseHandler.Update();
    }

    void City::Draw() {
        raylib::Rectangle rect(screenPosition.x, screenPosition.y, grid.getWidth() * CELL_SIZE, grid.getHeight() * CELL_SIZE);
        rect.Draw(backgroundColor);
        mouseHandler.Draw();
        grid.Draw(screenPosition);
    }

    Grid& City::GetGrid() {
        return grid;
    }
    
}

