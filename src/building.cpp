#include "building.hpp"
#include "raylib-cpp.hpp"

namespace citygame {

    raylib::Texture2D Building::texture;

    Building::Building(raylib::Rectangle source)
        :source(source) {

    }

    void Building::loadTexture(std::string path) {
        texture.Load(path);
    }

    void Building::unloadTexture() {
        texture.Unload();
    }

    void Building::draw(raylib::Rectangle dest) {
        texture.Draw(source, dest);
    }

}