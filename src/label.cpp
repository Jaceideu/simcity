#include "label.hpp"
#include "constants.hpp"

namespace citygame {

    Label::Label(raylib::Vector2 pos, std::string text, raylib::Color color)
        : UiElement(pos, raylib::Rectangle(0.0)), text(text, static_cast<float>(REGULAR_FONT_SIZE), color) {
    }

    void Label::draw(int scale) {
        text.fontSize = REGULAR_FONT_SIZE * scale;
        text.spacing = REGULAR_FONT_SPACING * scale;
        text.Draw(position * scale);
    }

    void Label::update(int scale) {

    }


}