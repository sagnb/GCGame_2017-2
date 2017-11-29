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
        int gang; //Quantidade de Inimigos

    public:
        Cubo();
        Cubo(float x, float y, float z, float lado);
        ~Cubo();
        float getX();
        float getY();
        float getZ();
        float getLado();
        int getGang();
        bool getVida();
        void setX( float x);
        void setY( float y);
        void setZ( float z);
        void setLado(float lado);
        void setVida(bool vida);
        void setGang(int g);
        void MoveInimigo();
        bool IntervaloX(float x);
        bool IntervaloY(float y);
        bool IntervaloXP(float x);
        bool IntervaloYP(float y);
        void Colisao(Bala *bala, Player *play);
        void drawCubo();
        GLuint loadTexture(const char* nome, int width, int height);
};

#endif
