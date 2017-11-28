#ifndef BALA_H
#define BALA_H

#include "GL/glut.h"

class Bala
{
    private:
        Object *bala;
        float x;
        float y;
        float z;
        float largura;
        float altura;
        float profundidade;
        int velocidade;
        //float escalaX;?????
        //float escalaY;?????
        //float escalaZ;?????

    public:

      Bala();
      Bala(char* nome, float x, float y, float z);
      ~Bala();
      float getX();
      float getY();
      float getZ();
      float getLargura();
      float getAltura();
      float getProfundidade();
      int getVelocidade();
      void setX(float x);
      void setY(float y);
      void setZ(float z);
      void setLargura(float lar);
      void setAltura(float alt);
      void setProfundidade(float pro);
      void setVelocidade(int vel);
      void Percurso(); //INCREMENTA O Y DA BALA
      void drawBala();
      void readObject(char* nome);
};

#endif
