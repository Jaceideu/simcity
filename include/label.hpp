#pragma once
#include "ui_element.hpp"

namespace citygame {

    class Label : public UiElement {
        public:
            Label(raylib::Vector2 pos, std::string text, raylib::Color color = raylib::Color::White());
            virtual void draw(int scale) override;
            virtual void update(int scale) override;
        protected:
            raylib::Text text;

    };


}