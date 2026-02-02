#pragma once
#include "label.hpp"

namespace citygame {

    class Counter : public Label {

        public:
            Counter(raylib::Vector2 pos, int& target);
            virtual void update(int scale) override;
        protected:
            int& target;
    };

}