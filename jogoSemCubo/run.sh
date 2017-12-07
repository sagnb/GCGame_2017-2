#!/bin/bash
g++ -o jogo ./Source/Star.cpp ./Source/Bala.cpp ./Source/Inimigo.cpp ./Source/Player.cpp ./Source/main.cpp ./Source/Object.cpp ./Source/Face.cpp ./Source/Aresta.cpp ./Source/Ponto.cpp ./Source/image.cpp -lGL -lglut -lGLU -lm -std=c++98 `sdl-config --cflags --libs` -lSDL_mixer
./jogo
