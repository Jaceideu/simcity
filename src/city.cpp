#include "city.hpp"
#include "constants.hpp"
#include "decoration.hpp"
#include "rng.hpp"

namespace citygame {

    City::City() 
        :backgroundColor(CITY_BACKGROUND_COLOR), cellOffsetX(CITY_SCREEN_CELL_OFFSET), cellOffsetY(CITY_SCREEN_CELL_OFFSET), grid(CITY_GRID_WIDTH, CITY_GRID_HEIGHT, CELL_SIZE) {
        
        for (int y = 0; y < grid.getHeight(); y++) {
            for (int x = 0; x < grid.getWidth(); x++) {

                if (RandomInt(0, 1) == 1) {
                    grid.setCell(x, y, std::make_unique<Decoration>());
                }
                
            }
        }
    }

    void City::update() {
        
    }
    
    void City::drawBackground() {
        raylib::Rectangle rect(cellOffsetX * grid.getCellSize(), cellOffsetY * grid.getCellSize(), grid.getWidth() * CELL_SIZE, grid.getHeight() * CELL_SIZE);
        rect.Draw(backgroundColor);
    }

    void City::drawForeground() {
        grid.draw(raylib::Vector2(cellOffsetX * grid.getCellSize(), cellOffsetY * grid.getCellSize()));
    }

    void City::cityCellToGridCell(int8_t& x, int8_t& y) {
        x -= cellOffsetX;
        y -= cellOffsetY;
    }

    void City::step(CityStats& stats) {
        for (int y = 0; y < grid.getHeight(); y++) {
            for (int x = 0; x < grid.getWidth(); x++) {
                grid.getCell(x, y)->step(x, y, grid, stats);
            }
        }
    }

    Grid& City::getGrid() {
        return grid;
    }


    
}

