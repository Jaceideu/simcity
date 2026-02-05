#pragma once
#include "raylib-cpp.hpp"

namespace citygame {

    class UiElement {
        public:
            UiElement(raylib::Vector2 pos, raylib::Rectangle source);
            virtual void draw(int scale) = 0;
            virtual void update(int scale) = 0;
            static void loadTexture(std::string path);
            static void unloadTexture();
            void hide();
            void show();
            bool isMarkedForDeletion;
            bool isVisible;
        protected:
            static raylib::Texture2D texture;
            raylib::Vector2 position;
            raylib::Rectangle source;
    };
      

}