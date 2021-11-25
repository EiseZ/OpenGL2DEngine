all:
	g++ -std=c++2a src/*.cpp src/*/*.c -o bin/main.exe -Wall -Wextra -Iinc -Llib -lglfw3dll
	./bin/main.exe