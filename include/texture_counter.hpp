#pragma once
#include "counter.hpp"
#include <map>

namespace citygame {

    class TextureCounter : public Counter {
        public:
            TextureCounter(raylib::Vector2 pos, int& target, std::map<int, raylib::Rectangle> numToTexture);
            virtual void draw(int scale) override;
            virtual void update(int scale) override;
        protected:
            std::map<int, raylib::Rectangle> numToTexture;
            int lastNumber;

    };

}