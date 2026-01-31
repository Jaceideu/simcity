#pragma once
#include "grid.hpp"

namespace citygame {

    class MouseHandler {
        public:
            MouseHandler(Grid* grid);
            void Update();
            void Draw();
        private:
            Grid* grid;
            raylib::Rectangle selectRectangle;
            raylib::Color selectColor;
    };

}