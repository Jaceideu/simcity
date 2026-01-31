#pragma once
#include <raylib-cpp.hpp>
#include <string>

namespace citygame {

    class Building {
        public:
            Building(raylib::Rectangle source);
            static void loadTexture(std::string path);
            static void unloadTexture();
            void draw(raylib::Rectangle dest);
        protected:
            static raylib::Texture2D texture;
            raylib::Rectangle source;
    };

}