#include "amusement_building.hpp"

namespace citygame {

    AmusementBuilding::AmusementBuilding() 
        : Building(raylib::Rectangle(32.0f, 0.0f, 16.0f, 16.0f)) {
        
    }

    void AmusementBuilding::step(const int8_t x, const int8_t, Grid& grid, CityStats& stats) {

    }

    int AmusementBuilding::getCost() const {
        return 3;
    }

}