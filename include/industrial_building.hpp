#pragma once
#include "building.hpp"

namespace citygame {

    class IndustrialBuilding : public Building {
        public:
            IndustrialBuilding();
            virtual void step(const int8_t x, const int8_t, Grid& grid, CityStats& stats) override;
            virtual int getMoneyBonus() override;
            virtual int getCost() const override;
            virtual int getHappinessBonus() const override;
    };
}