#ifndef CUBO_H
#define CUBO_H

#include "GL/glut.h"

#include "Player.hpp"
#include "Bala.hpp"

#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <cstdio>

class Cubo
{
    private:
        GLuint texture[3];
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
        Cubo(float x, float y, float z, float lado);
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
        bool IntervaloY(float y);
        void Colisao(Bala *bala);
        void drawCubo();
        GLuint loadTexture(char* nome, int width, int height);
};

#endif
