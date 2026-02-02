#pragma once
#include "raylib-cpp.hpp"
#include "city.hpp"
#include "ui_manager.hpp"
#include "city_stats.hpp"

namespace citygame {

    class Game {
        public:
            Game();
            ~Game();
            void enterMainLoop();
        private:
            void startNewRun();
            raylib::Color clearColor;   
            raylib::Window window;
            raylib::RenderTexture2D renderTexture;    
            City city;
            BuildingPlacer buildingPlacer;
            UiManager ui;
    };
    
}