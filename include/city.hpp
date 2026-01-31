#pragma once
#include "grid.hpp"
#include "mouse_handler.hpp"

namespace citygame {

    class City {
        public:
            City();
            void Update();
            void Draw();
            Grid& GetGrid();
        private:
            raylib::Color backgroundColor;
            raylib::Vector2 screenPosition;
            Grid grid;
            MouseHandler mouseHandler;
    };

}