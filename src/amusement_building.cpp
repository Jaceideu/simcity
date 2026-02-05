#include "amusement_building.hpp"
#include "city_stats.hpp"
#include "grid.hpp"

namespace citygame {

    AmusementBuilding::AmusementBuilding() 
        : Building(raylib::Rectangle(32.0f, 0.0f, 16.0f, 16.0f)) {
        
    }

    void AmusementBuilding::step(const int8_t x, const int8_t y, Grid& grid, CityStats& stats) {
        int happinessBonus = 0;

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {

                if (i == 0 && j == 0) continue;

                GridCell* cell = grid.getCell(x + i, y + j);
                if (cell) {
                    happinessBonus += cell->getHappinessBonus();
                }

            }
        }
        stats.addHappiness(happinessBonus + 2);
        stats.addMoney(-1);
    }

    int AmusementBuilding::getCost() const {
        return 3;
    }
    
    int AmusementBuilding::getHappinessBonus() const {
        return 2;
    }

}