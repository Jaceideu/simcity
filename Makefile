CC := g++
EXE_NAME := simcity
MAIN_FILE := main.cpp
SRC_FILES := game.cpp building.cpp city.cpp grid.cpp mouse_handler.cpp
SRC_FILES := $(addprefix src/, $(SRC_FILES))

all: $(CPP_FILES)
	$(CC) $(MAIN_FILE) $(SRC_FILES) -o $(EXE_NAME) -I./include -I./include/raylib-cpp -L./lib -lraylib -lopengl32 -lgdi32 -lwinmm