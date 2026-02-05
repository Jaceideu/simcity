#include "ui_panel.hpp"

namespace citygame {

    UiPanel::UiPanel(raylib::Rectangle dest, raylib::Color color)
        : UiElement(raylib::Vector2(dest.x, dest.y), dest), color(color) {

    }

    void UiPanel::draw(int scale) {
        if (!isVisible) return;
        raylib::Rectangle scaledSource(source.x * scale, source.x * scale, source.width * scale, source.height * scale);
        scaledSource.Draw(color);
    }

    void UiPanel::update(int scale) {
        
    }

}
