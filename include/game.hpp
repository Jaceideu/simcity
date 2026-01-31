#pragma once
#include <raylib-cpp.hpp>
#include "city.hpp"

namespace citygame {

    class Game {
        public:
            Game();
            ~Game();
            void enterMainLoop();
        private:
            raylib::Color clearColor;   
            raylib::Window window;
            raylib::RenderTexture2D renderTexture;    
            City city;
    };
    
}