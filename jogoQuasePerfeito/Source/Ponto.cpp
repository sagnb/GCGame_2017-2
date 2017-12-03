#include <iostream>
#include "../Headers/Ponto.h"

using namespace std;

Ponto::Ponto() {}
Ponto::~Ponto() {}

Ponto::Ponto(float X, float Y,float Z)
{
    x = X;
    y = Y;
    z = Z;
}

float* Ponto::vector(float vetor[])
{
    vetor[0] = x;
    vetor[1] = y;
    vetor[2] = z;
    return vetor;
}

float Ponto::getX()
{
    return x;
}

float Ponto::getY()
{
    return y;
}

float Ponto::getZ()
{
    return z;
}

void Ponto::setX(float x)
{
    this->x = x;
}
void Ponto::setY(float y)
{
    this->y = y;
}
void Ponto::setZ(float z)
{
    this->z = z;
}


