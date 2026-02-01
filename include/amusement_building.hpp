#pragma once
#include "building.hpp"

namespace citygame {

    class AmusementBuilding : public Building {
        public:
            AmusementBuilding();
            virtual void step(const int8_t x, const int8_t, Grid& grid, CityStats& stats) override;
        
    };

}