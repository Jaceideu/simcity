#include "button.hpp"

namespace citygame {

    Button::Button(raylib::Vector2 pos, raylib::Rectangle source, std::function<void()> callback)
        : UiElement(pos, source), callback(callback) {

    }

    void Button::draw(int scale) {
        texture.Draw(source, raylib::Rectangle(position.x * scale, position.y * scale, source.width * scale, source.height * scale));
    }

    void Button::update(int scale) {
        if (isPressed(scale)) {
            callback();
        }
    }

    bool Button::isHovered(int scale) {
        raylib::Vector2 mPos = raylib::Mouse::GetPosition();

        if (mPos.x < position.x * scale) return false;
        if (mPos.x > position.x * scale + source.width * scale) return false;
        if (mPos.y < position.y * scale) return false;
        if (mPos.y > position.y * scale + source.height * scale) return false;

        return true;
    }
    
    bool Button::isPressed(int scale) {
        if (!isHovered(scale)) return false;
        if (!raylib::Mouse::IsButtonPressed(MouseButton::MOUSE_BUTTON_LEFT)) return false;

        return true;
    }
            
}