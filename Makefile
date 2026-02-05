CXX := g++
EXE_NAME := city_game
MAIN_FILE := main.cpp

SRC_FILES := game.cpp \
building.cpp \
city.cpp grid.cpp \
building_placer.cpp \
grid_cell.cpp \
residental_building.cpp \
decoration.cpp \
industrial_building.cpp \
amusement_building.cpp \
ui_manager.cpp \
button.cpp \
city_stats.cpp \
ui_element.cpp \
label.cpp counter.cpp \
texture_counter.cpp \
ui_panel.cpp

OBJ_FILES := $(SRC_FILES:.cpp=.o)
OBJ_FILES := $(addprefix bin/, $(OBJ_FILES))
SRC_FILES := $(addprefix src/, $(SRC_FILES))

CXXFLAGS := -I./include -I./include/raylib-cpp 
LDFLAGS := -lraylib_linux -lGL -lm -lpthread -ldl -lrt -lX11

ifeq ($(OS),Windows_NT)
	LDFLAGS := -lraylib_win -mwindows -lopengl32 -lgdi32 -lwinmm
endif

all: $(EXE_NAME)

$(EXE_NAME): $(OBJ_FILES)
	$(CXX) $(MAIN_FILE) $(OBJ_FILES) -o $(EXE_NAME) $(CXXFLAGS) -L./lib $(LDFLAGS)

bin/%.o: src/%.cpp | bin
	$(CXX) -o $@ -c $< $(CXXFLAGS)

bin:
	mkdir -p bin

clean:
	rm -f bin/*.o