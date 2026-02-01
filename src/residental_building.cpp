#include "residental_building.hpp"
#include "rng.hpp"

namespace citygame {

    ResidentalBuilding::ResidentalBuilding()
        : Building(raylib::Rectangle(0.0f, 0.0f, 16.0f, 16.0f)) {

        source.y = RandomInt(0, 2) * 16.0f;

    }

    void ResidentalBuilding::step(const int8_t x, const int8_t, Grid& grid, CityStats& stats) {
        
    }

    int ResidentalBuilding::getMoneyBonus() {
        return 1;
    }

}