#include "ui_element.hpp"
#include <iostream>

namespace citygame {

    raylib::Texture2D UiElement::texture;

    UiElement::UiElement(raylib::Vector2 pos, raylib::Rectangle source)
        : position(pos), source(source), isVisible(true), isMarkedForDeletion(false) {
    }

    void UiElement::loadTexture(std::string path) {
        texture.Load(path);
    }

    void UiElement::unloadTexture() {
        texture.Unload();
    }

}

