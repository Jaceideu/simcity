#include "texture_counter.hpp"

namespace citygame {


    TextureCounter::TextureCounter(raylib::Vector2 pos, int& target, std::map<int, raylib::Rectangle> numToTexture)
        : Counter(pos, target), numToTexture(numToTexture), lastNumber(0) {

    }

    void TextureCounter::draw(int scale) {
        texture.Draw(source, raylib::Rectangle(position.x * scale, position.y * scale, source.width * scale, source.height * scale));
    }

    void TextureCounter::update(int scale) {
        if (target != lastNumber) {
            lastNumber = target;
            if (numToTexture.find(target) != numToTexture.end()) {
                
                source = numToTexture[target];
                
            }
        }
    }

}