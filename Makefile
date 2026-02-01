CXX := g++
EXE_NAME := city_game
MAIN_FILE := main.cpp
SRC_FILES := game.cpp building.cpp city.cpp grid.cpp mouse_handler.cpp grid_cell.cpp residental_building.cpp decoration.cpp
SRC_FILES := $(addprefix src/, $(SRC_FILES))

all: $(CPP_FILES)
	$(CXX) $(MAIN_FILE) $(SRC_FILES) -o $(EXE_NAME) -I./include -I./include/raylib-cpp -L./lib -lraylib -lopengl32 -lgdi32 -lwinmm