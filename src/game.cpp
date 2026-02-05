#include "raylib-cpp.hpp"
#include "game.hpp"
#include "constants.hpp"
#include "ui_manager.hpp"
#include "button.hpp"
#include "counter.hpp"
#include <iostream>
#include "texture_counter.hpp"

namespace citygame {

    Game::Game()
        :clearColor(), window(SCREEN_WIDTH * WINDOW_SCALE, SCREEN_HEIGHT * WINDOW_SCALE, "City Game"), renderTexture(SCREEN_WIDTH, SCREEN_HEIGHT), city(), buildingPlacer(&city),  ui(UI_SCALE)  {
        using namespace std;
        using namespace raylib;

        window.SetTargetFPS(60);

        GridCell::loadTexture("assets/textures/buildings.png");
        UiElement::loadTexture("assets/textures/ui.png");
        ui.addElement(make_unique<Button>(
            raylib::Vector2(0.0f, 0.0f),
            raylib::Rectangle(0.0f, 0.0f, 16.0f, 16.0f),
            [this] {
                buildingPlacer.setBuildingIndex(0);
            }
        ));
        ui.addElement(make_unique<Label>(
            raylib::Vector2(0.0f, 0.0f),
            "2",
            raylib::Color(MONEY_COLOR)
        ));


        ui.addElement(make_unique<Button>(
            raylib::Vector2(16.0f, 0.0f),
            raylib::Rectangle(16.0f, 0.0f, 16.0f, 16.0f),
            [this] {
                buildingPlacer.setBuildingIndex(1);
            }

        ));
        ui.addElement(make_unique<Label>(
            raylib::Vector2(16.0f, 0.0f),
            "4",
            raylib::Color(MONEY_COLOR)
        ));

        ui.addElement(make_unique<Button>(
            raylib::Vector2(32.0f, 0.0f),
            raylib::Rectangle(32.0f, 0.0f, 16.0f, 16.0f),
            [this] {
                buildingPlacer.setBuildingIndex(2);
            }

        ));
        ui.addElement(make_unique<Label>(
            raylib::Vector2(32.0f, 0.0f),
            "3",
            raylib::Color(MONEY_COLOR)
        ));

        ui.addElement(make_unique<Button>(
            raylib::Vector2(renderTexture.GetTexture().width - 16.0f, renderTexture.GetTexture().height - 16.0f),
            raylib::Rectangle(0.0f, 16.0f, 16.0f, 16.0f),
            [this] {
                city.step();
            }
        ));
        ui.addElement(make_unique<Counter>(
            raylib::Vector2(0.0f, 16.0f),
            city.getStats().getMoneyReference(),
            raylib::Color(MONEY_COLOR)
        ));

        ui.addElement(make_unique<TextureCounter>(
            raylib::Vector2(0.0f, 32.0f),
            city.getHappinessGaugeReference(),
            std::map<int, raylib::Rectangle>{
                {1, raylib::Rectangle(16.0f, 16.0f, 16.0f, 16.0f)},
                {2, raylib::Rectangle(32.0f, 16.0f, 16.0f, 16.0f)},
                {3, raylib::Rectangle(48.0f, 16.0f, 16.0f, 16.0f)}
            }
        ));

        ui.addElement(make_unique<Label>(
            raylib::Vector2(64.0f, 0.0f),
            "Tax:",
            raylib::Color::Red()
        ));
        ui.addElement(make_unique<Counter>(
            raylib::Vector2(96.0f, 0.0f),
            city.getStats().getTax(),
            raylib::Color::Red()
        ));

    }

    Game::~Game() {
        GridCell::unloadTexture();
        UiElement::unloadTexture();
    }

    void Game::enterMainLoop() {

        while(!window.ShouldClose()) {

            buildingPlacer.update();
            city.update();
            ui.update();

            renderTexture.BeginMode();
            window.ClearBackground(clearColor);
            city.drawBackground();
            buildingPlacer.draw();
            city.drawForeground();
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
            ui.draw();
            window.EndDrawing();
            
        }

    }

    void Game::startNewRun() {
        
    }

}