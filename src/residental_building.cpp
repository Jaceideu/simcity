#include "residental_building.hpp"
#include "rng.hpp"
#include "grid.hpp"
#include "city_stats.hpp"

namespace citygame {

    ResidentalBuilding::ResidentalBuilding()
        : Building(raylib::Rectangle(0.0f, 0.0f, 16.0f, 16.0f)) {

        source.y = RandomInt(0, 2) * 16.0f;

    }

    void ResidentalBuilding::step(const int8_t x, const int8_t y, Grid& grid, CityStats& stats) {
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

        stats.addHappiness(happinessBonus);
    }

    int ResidentalBuilding::getMoneyBonus() {
        return 1;
    }

    int ResidentalBuilding::getCost() const {
        return 2;
    }

}