#pragma once
#include <functional>
#include "raylib-cpp.hpp"
#include "ui_element.hpp"

namespace citygame {

    class Button : public UiElement {
        public:
            Button(raylib::Vector2 pos, raylib::Rectangle source, std::function<void()> callback);
            virtual void draw(int scale) override;
            virtual void update(int scale) override;
        protected:
            bool IsPressed(int scale);
            std::function<void()> callback;

    };

}