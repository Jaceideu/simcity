#include "industrial_building.hpp"
#include "residental_building.hpp"
#include "grid.hpp"
#include "city_stats.hpp"

namespace citygame {

    IndustrialBuilding::IndustrialBuilding()
        : Building(raylib::Rectangle(16.0f, 0.0f, 16.0f, 16.0f)) {
    }
    
    void IndustrialBuilding::step(const int8_t x, const int8_t y, Grid& grid, CityStats& stats) {
        int moneyBonus = 0;

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {

                if (i == 0 && j == 0) continue;

                GridCell* cell = grid.getCell(x + i, y + j);
                if (cell) {
                    moneyBonus += cell->getMoneyBonus();
                }

            }
        }

        stats.addMoney(moneyBonus);

    }

    int IndustrialBuilding::getMoneyBonus() {
        return -2;
    }

    int IndustrialBuilding::getCost() const {
        return 4;
    }

}