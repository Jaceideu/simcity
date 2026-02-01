#include "decoration.hpp"
#include "rng.hpp"

namespace citygame {

    Decoration::Decoration() 
        : GridCell(raylib::Rectangle(48.0f, 0.0f, 16.0f, 16.0f)) {
        
        source.y = RandomInt(0, 3) * 16.0f;
        flip(RandomInt(0, 1) == 1 ? true : false);


    }

}