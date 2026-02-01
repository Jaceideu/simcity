#pragma once
#include "raylib-cpp.hpp"
#include "grid_cell.hpp"
#include <string>
#include <cstdint>

namespace citygame {

    class Grid;

    class Building : public GridCell {
        public:
            Building(raylib::Rectangle source);
            virtual bool isEmpty() override;
            virtual int getCost() const = 0;
    };

}