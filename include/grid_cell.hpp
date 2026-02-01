#pragma once
#include "raylib-cpp.hpp"
#include <string>
#include <cstdint>

namespace citygame {

    class Grid;
    class CityStats;

    class GridCell {
        public:
            GridCell(raylib::Rectangle source);
            static void loadTexture(std::string path);
            static void unloadTexture();
            void draw(raylib::Rectangle dest);
            virtual void step(const int8_t x, const int8_t, Grid& grid, CityStats& stats);
            virtual bool isEmpty();
            virtual int getMoneyBonus();
            void flip(bool flip);
        protected:
            static raylib::Texture2D texture;
            raylib::Rectangle source;

    };

}