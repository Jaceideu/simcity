#pragma once
#include "ui_element.hpp"
#include <memory>
#include <vector>
#include "building_placer.hpp"

namespace citygame {

    class UiManager {
        public:
            UiManager(int scale);
            void addElement(std::unique_ptr<UiElement> element);
            void update();
            void draw();
        private:
            std::vector<std::unique_ptr<UiElement>> elements;
            int scale;
    };


}