#include "grid_cell.hpp"
#include "raylib-cpp.hpp"
#include <cmath>

namespace citygame {

    raylib::Texture2D GridCell::texture;

    GridCell::GridCell(raylib::Rectangle source)
        :source(source) {

    }

    void GridCell::loadTexture(std::string path) {
        texture.Load(path);
    }

    void GridCell::unloadTexture() {
        texture.Unload();
    }

    void GridCell::draw(raylib::Rectangle dest) {
        texture.Draw(source, dest);
    }

    void GridCell::step(const int8_t x, const int8_t, Grid& grid) {

    }

    bool GridCell::isEmpty() {
        return true;
    }

    void GridCell::flip(bool flip) {
        int flipScale = flip ? -1 : 1;
        source.width = fabs(source.width) * flipScale;
    }
}