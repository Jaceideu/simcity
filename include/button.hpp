#pragma once
#include <functional>
#include "raylib-cpp.hpp"

namespace citygame {

    class Button {
        public:
            Button(raylib::Vector2 pos, raylib::Rectangle source, std::function<void()> callback);
            void draw(int scale);
            void update(int scale);
            static void loadTexture(std::string path);
            static void unloadTexture();
        protected:
            bool IsPressed(int scale);
            static raylib::Texture2D texture;
            raylib::Vector2 position;
            raylib::Rectangle source;
            std::function<void()> callback;

    };

}