#include "building.hpp"
#include "raylib-cpp.hpp"

namespace citygame {

    Building::Building(raylib::Rectangle source)
        : GridCell(source) {

    }

    bool Building::isEmpty() { 
        return false;
    }
  
}