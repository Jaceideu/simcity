#include "label.hpp"
#include "constants.hpp"

namespace citygame {

    Label::Label(raylib::Vector2 pos, std::string text)
        : UiElement(pos, raylib::Rectangle(0.0)), text(text) {
    }

    void Label::draw(int scale) {
        text.fontSize = REGULAR_FONT_SIZE * scale;
        text.spacing = REGULAR_FONT_SPACING * scale;
        text.Draw(position * scale);
    }

    void Label::update(int scale) {

    }


}