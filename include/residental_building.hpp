#pragma once
#include "building.hpp"

namespace citygame {

    class ResidentalBuilding : public Building {
        public:
            ResidentalBuilding();
            virtual void step(const int8_t x, const int8_t, Grid& grid) override;
    };

}

