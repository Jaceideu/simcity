#include "building_placer.hpp"
#include "constants.hpp"
#include "city.hpp"
#include "raylib-cpp.hpp"
#include "rng.hpp"
#include "residental_building.hpp"
#include "industrial_building.hpp"
#include "amusement_building.hpp"
#include <iostream>

namespace citygame {

    BuildingPlacer::BuildingPlacer(City* city) 
        : city(city), selectRectangle(0, 0, city->getGrid().getCellSize(), city->getGrid().getCellSize()), selectColor(SELECTION_COLOR), cellX(0), cellY(0), currBuildingIndex(0) {
        
    }

    void BuildingPlacer::update() {
        using namespace raylib;
        raylib::Vector2 mPos = Mouse::GetPosition();
        mPos /= WINDOW_SCALE;
        cellX = static_cast<int8_t>(mPos.x / city->getGrid().getCellSize());
        cellY = static_cast<int8_t>(mPos.y / city->getGrid().getCellSize());

        selectRectangle.x = cellX * city->getGrid().getCellSize();
        selectRectangle.y = cellY * city->getGrid().getCellSize();


        if (Mouse::IsButtonPressed(MouseButton::MOUSE_BUTTON_LEFT)) {
            int8_t cCellX = cellX, cCellY = cellY;

            city->cityCellToGridCell(cCellX, cCellY);

            GridCell* currCell = city->getGrid().getCell(cCellX, cCellY);

            if (currCell && currCell->isEmpty()) {
                
                bool shouldFlip = RandomInt(0, 1) == 1 ? true : false;

                std::unique_ptr<Building> newBuilding;

                switch (currBuildingIndex)
                {
                case 0:
                    newBuilding = std::make_unique<ResidentalBuilding>();
                    break;
                case 1:
                    newBuilding = std::make_unique<IndustrialBuilding>();
                    break;
                case 2:
                    newBuilding = std::make_unique<AmusementBuilding>();
                    break;
                default:
                    break;
                }

                newBuilding->flip(shouldFlip);

                city->getGrid().setCell(cCellX, cCellY, std::move(newBuilding));
            }
        }
    }

    void BuildingPlacer::draw() {
        using namespace raylib;
        selectRectangle.Draw(selectColor);
    }

    void BuildingPlacer::setBuildingIndex(int i) {
        currBuildingIndex = i;
    }

}