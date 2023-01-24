all:
	g++ -I ./SDL2/include/ -L ./SDL2/lib/x64/ -o main main.cc -lSDL2main -lSDL2