#ifndef CUBO_H
#define CUBO_H

#include "GL/glut.h"

class Cubo()
{
    private:
        GLuint texture[3];
        float x;
        float y;
        float z;
        float lado; // LARGURA / ALTURA / PROFUNDIDADE

    public:
        Cubo();
        Cubo(float x, float y, float z, float lado);
        float getX();
        float getY();
        float getZ();
        float getLado();
        void setX( float x);
        void setY( float y);
        void setZ( float z);
        void setLado(float lado);
        void MoveInimigo();
}
