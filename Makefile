CC = g++
CFLAGS = -std=c++20
OBJS = ./libs/glad/src/glad.cpp\
	   ./3dEngine/main.cpp\
	   ./3dEngine/Src/*.cpp\

INCLUDE_PATHS = -I./libs/glfw-3.3.8/include/GLFW/glfw3.h
LIBRARY_PATHS = -L./libs/glfw-3.3.8/lib-arm64 -lglfw3 -I/opt/homebrew/Cellar/assimp/5.3.1/include -L/opt/homebrew/Cellar/assimp/5.3.1/lib -lassimp
LINKER_FLAGS = -framework OpenGL -framework IOKit -framework Cocoa -lSOIL2
OBJ_NAME = ./bin/3dEngine

all: $(OBJ_NAME)

$(OBJ_NAME): $(OBJS)
	$(CC) $^ $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(CFLAGS) $(LINKER_FLAGS) -o $@

test : all
	@$(OBJ_NAME)
	@rm -rf ./bin/3dEngine

clean:
	@rm -rf ./bin/*