CXX := g++
EXE_NAME := city_game
MAIN_FILE := main.cpp
SRC_FILES := game.cpp building.cpp city.cpp grid.cpp building_placer.cpp grid_cell.cpp residental_building.cpp decoration.cpp industrial_building.cpp amusement_building.cpp ui_manager.cpp button.cpp city_stats.cpp ui_element.cpp label.cpp counter.cpp
SRC_FILES := $(addprefix src/, $(SRC_FILES))

all: $(CPP_FILES)
	$(CXX) $(MAIN_FILE) $(SRC_FILES) -o $(EXE_NAME) -I./include -I./include/raylib-cpp -L./lib -lraylib -lopengl32 -lgdi32 -lwinmm