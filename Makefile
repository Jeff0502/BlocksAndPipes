all:
	g++ -Wall -I include/ -L lib -o main main.cpp -lmingw32 -lSDL2main -lSDL2 -Dmain=SDL_main 

run:
	.\main.exe