all: compile link execute

compile:
	g++ -std=c++20 -I"GLFW/include" -I"src" -c src/main.cpp -o build/main.o

link:
	g++ build/main.o -o build/main -L"GLFW/lib" -l:libglfw3dll.a -l:libglfw3.a -lopengl32 -lglfw3

execute:
	./build/main