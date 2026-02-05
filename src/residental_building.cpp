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
        stats.addHappiness(-1);
    }

    int ResidentalBuilding::getMoneyBonus() {
        return 1;
    }

    int ResidentalBuilding::getHappinessBonus() const {
        return 1;
    }

    int ResidentalBuilding::getCost() const {
        return 2;
    }

}