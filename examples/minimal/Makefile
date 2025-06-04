CXX = g++
SRC = $(shell find ../.. -name '*.cpp')
CXXFLAGS = -std=c++11 -I../.. $(shell sdl2-config --cflags) -DRETRO3D_USE_SDL2
LDFLAGS = -lpthread $(shell sdl2-config --libs) -lSDL2_mixer
TARGET = minimal_example

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)
