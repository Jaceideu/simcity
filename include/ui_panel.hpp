#pragma once
#include "ui_element.hpp"

namespace citygame {

    class UiPanel : public UiElement {
        public:
            UiPanel(raylib::Rectangle dest, raylib::Color color);
            virtual void draw(int scale) override;
            virtual void update(int scale) override;
        protected:
            raylib::Color color;
    };

}

