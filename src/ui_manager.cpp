#include "ui_manager.hpp"
#include <iostream>

namespace citygame {

    UiManager::UiManager(int scale)
        : scale(scale) {
    }

    UiElement* UiManager::addElement(std::unique_ptr<UiElement> element) {
        elements.emplace_back(std::move(element));
        return elements.back().get();
    }

    void UiManager::update() {

        for (auto it = elements.begin(); it != elements.end(); ) {
            if ((*it)->isMarkedForDeletion) {
                it = elements.erase(it);
            }
            else {
                (*it)->update(scale);
                ++it;
            }
        }
    }

    void UiManager::draw() {
        for (auto& el : elements) {
            el->draw(scale);
        }
    }

}