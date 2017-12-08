#ifndef INIMIGO_H
#define INIMIGO_H

#include "Player.hpp"
#include "Bala.hpp"
#include "Object.h"
class Player;

#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include "GL/glut.h"
#include <vector>

using namespace std;

class Inimigo
{
private:
    Object *objeto;
    float x;
    float y;
    float z;
    float raio; // LARGURA / ALTURA / PROFUNDIDADE
    bool vida;
    bool flag;
    int velocidade;

public:
    Inimigo();
    Inimigo(Object* objeto, float x, float y, float z, float raio, int velocidade);
    ~Inimigo();
    void setObject(Object *objeto);
    float getX();
    float getY();
    float getZ();
    float getRaio();
    bool getVida();
    void setX( float x);
    void setY( float y);
    void setZ( float z);
    void setRaio(float raio);
    void setVida(bool vida);
    void MoveInimigo();
    bool IntervaloX(float x);
    bool IntervaloZ(float z);
    void Colisao(vector <Bala*> balas, Player *play);
    void drawInimigo();
    void ia(Player *nave);
    void setFlag(bool flag);
    bool getFlag();
    void setVelocidade(int velocidade);
    int getVelocidade();
};

#endif
