STB_INCLUDE_PATH = /usr/include/stb/
TOL_INCLUDE_PATH = /usr/include/

PROJECT = vkApp

CFLAGS = -std=c++17 -O3 -I./src/ -I./src/core -I./src/core/vulkan
LDFLAGS = -I$(STB_INCLUDE_PATH) -I${TOL_INCLUDE_PATH} -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi
DBGFLAGS = -DDEBUG

SRC = $(wildcard src/*.cpp src/core/*.cpp)

release: ${SRC}
	g++ $(CFLAGS) -o $(PROJECT) ${SRC} $(LDFLAGS)

debug: ${SRC}
	g++ $(DBGFLAGS) $(CFLAGS) -o $(PROJECT) ${SRC} $(LDFLAGS)

.PHONY: test debug clean

test: release
		./$(PROJECT)

clean:
	rm -f $(PROJECT)