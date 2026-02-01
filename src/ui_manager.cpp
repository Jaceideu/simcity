#include "ui_manager.hpp"
#include <iostream>

namespace citygame {

    UiManager::UiManager(int scale)
        : scale(scale) {
    }

    void UiManager::addButton(std::unique_ptr<Button> button) {
        buttons.emplace_back(std::move(button));
    }

    void UiManager::update() {
        for (auto& btn : buttons) {
            btn->update(scale);
        }
    }

    void UiManager::draw() {
        for (auto& btn : buttons) {
            btn->draw(scale);
        }
    }

}