#include "ui_manager.hpp"
#include <iostream>

namespace citygame {

    UiManager::UiManager(int scale)
        : scale(scale) {
    }

    void UiManager::addElement(std::unique_ptr<UiElement> element) {
        elements.emplace_back(std::move(element));
    }

    void UiManager::update() {
        for (auto& el : elements) {
            el->update(scale);
        }
    }

    void UiManager::draw() {
        for (auto& el : elements) {
            el->draw(scale);
        }
    }

}