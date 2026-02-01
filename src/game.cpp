#include "raylib-cpp.hpp"
#include "game.hpp"
#include "constants.hpp"

namespace citygame {

    Game::Game()
        :clearColor(), window(SCREEN_WIDTH * WINDOW_SCALE, SCREEN_HEIGHT * WINDOW_SCALE, "City Game"), renderTexture(SCREEN_WIDTH, SCREEN_HEIGHT), city()  {

        window.SetTargetFPS(60);

        GridCell::loadTexture("assets/textures/buildings.png");
    }

    Game::~Game() {
        GridCell::unloadTexture();
    }

    void Game::enterMainLoop() {

        while(!window.ShouldClose()) {

            city.update();

            renderTexture.BeginMode();
            window.ClearBackground(clearColor);
            city.draw();
            renderTexture.EndMode();

            window.BeginDrawing();
            renderTexture.GetTexture().Draw(
                raylib::Rectangle(
                    0, 0, 
                    renderTexture.GetTexture().width, 
                    -renderTexture.GetTexture().height
                ),
                raylib::Rectangle(0, 0, 
                    window.GetWidth(), 
                    window.GetHeight()
                )
            );
            window.EndDrawing();
            
        }

    }

}