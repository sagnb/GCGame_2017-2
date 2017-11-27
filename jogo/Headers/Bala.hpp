#ifndef BALA_H
#define BALA_H

#include "GL/glut.h"

class Bala()
{
    private:
        //Object bala;
        float x;
        float y;
        float z;
        float largura;
        float altura;
        float profundidade;

    public:

      Bala();
      Bala(float x, float y, float z);
      float getX();
      float getY();
      float getZ();
      float getLargura();
      float getAltura();
      float getProfundidade();
      void setX(float x);
      void setY(float y);
      void setZ(float z);
      void setLargura(float lar);
      void setAltura(float alt);
      void setProfundidade(float pro);
};
