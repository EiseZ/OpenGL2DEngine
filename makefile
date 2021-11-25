all:
	g++ src/*.cpp src/*.c -o bin/main.exe -Iinc -Llib -lglfw3dll
	./bin/main.exe