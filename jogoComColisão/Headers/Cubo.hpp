#ifndef CUBO_H
#define CUBO_H

#include "Player.hpp"
#include "Bala.hpp"
class Player;

#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include "GL/glut.h"
#include <vector>

using namespace std;

class Cubo
{
    private:
        GLuint texture;
        float x;
        float y;
        float z;
        float lado; // LARGURA / ALTURA / PROFUNDIDADE
        bool vida;
        float r;
        float g;
        float b;
        float alpha;

    public:
        Cubo();
        Cubo(const char *nome, float x, float y, float z, float lado);
        Cubo(GLuint textura, float x, float y, float z, float lado);
        ~Cubo();
        float getX();
        float getY();
        float getZ();
        float getLado();
        bool getVida();
        void setX( float x);
        void setY( float y);
        void setZ( float z);
        void setLado(float lado);
        void setVida(bool vida);
        void MoveInimigo();
        bool IntervaloX(float x);
        bool IntervaloZ(float z);
        bool IntervaloXP(float x);
        bool IntervaloYP(float y);
        void Colisao(vector <Bala*> balas, Player *play);
        void drawCubo();
        GLuint loadTexture(const char* nome, int width, int height);
};

#endif
