#include <iostream>
#include <raylib-cpp.hpp>

int main() {
    using namespace std;

    raylib::Window window(800, 600, "Testować");
    window.SetTargetFPS(60);

    while(!window.ShouldClose()) {
        window.BeginDrawing();
        window.ClearBackground(DARKGREEN);
        window.EndDrawing();
    }
}