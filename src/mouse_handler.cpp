#include "mouse_handler.hpp"
#include "constants.hpp"

namespace citygame {

    MouseHandler::MouseHandler(Grid* grid) 
        : grid(grid), selectRectangle(0, 0, grid->getCellSize(), grid->getCellSize()), selectColor(0xbfff3c) {
        
    }

    void MouseHandler::Update() {
        using namespace raylib;
        raylib::Vector2 mPos = Mouse::GetPosition();
        mPos /= WINDOW_SCALE;
        const uint8_t cellX = static_cast<uint8_t>(mPos.x / grid->getCellSize());
        const uint8_t cellY = static_cast<uint8_t>(mPos.y / grid->getCellSize());

        selectRectangle.x = cellX * grid->getCellSize();
        selectRectangle.y = cellY * grid->getCellSize();
    }

    void MouseHandler::Draw() {
        using namespace raylib;
        selectRectangle.Draw(selectColor);
    }

}