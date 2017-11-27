#ifndef PLAYER_H
#define PLAYER_H

#include "Object.h"

class Player()
{
      private:
          Object nave;
          float x;
          float y;
          float z;
          float largura;
          float altura;
          float profundidade;

      public:
        Player();        
        Player(Object nave);
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
        void moveDir();
        void moveEsq();
}
