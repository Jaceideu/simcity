#pragma once
#include "button.hpp"
#include <memory>
#include <vector>
#include "building_placer.hpp"

namespace citygame {

    class UiManager {
        public:
            UiManager(int scale);
            void addButton(std::unique_ptr<Button> button);
            void update();
            void draw();
        private:
            std::vector<std::unique_ptr<Button>> buttons;
            int scale;
    };


}