#pragma once
#include "ui_element.hpp"
#include <memory>
#include <list>
#include "building_placer.hpp"

namespace citygame {

    class UiManager {
        public:
            UiManager(int scale);
            UiElement* addElement(std::unique_ptr<UiElement> element);
            void update();
            void draw();
        private:
            std::list<std::unique_ptr<UiElement>> elements;
            int scale;
    };


}