CC := g++
EXE_NAME := simcity
CPP_FILES := main.cpp

all: $(CPP_FILES)
	$(CC) $(CPP_FILES) -o $(EXE_NAME) -I./include -I./include/raylib-cpp -L./lib -lraylib -lopengl32 -lgdi32 -lwinmm