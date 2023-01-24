all:
	g++ -I ./SDL2/include/ -L ./SDL2/lib/x64/ -L ./SDL2/lib/linux/ -o main main.cc -lSDL2main -lSDL2