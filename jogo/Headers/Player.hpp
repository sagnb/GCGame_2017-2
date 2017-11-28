#ifndef PLAYER_H
#define PLAYER_H

#include "Object.h"

#include "GL/glut.h"

class Player()
{
      private:
          Object *nave;
          float x;
          float y;
          float z;
          float largura;
          float altura;
          float profundidade;
          bool vida;
          float escalaX;
          float escalaY;
          float escalaZ;

      public:
        Player();
        Player(char* nomeArquivo);
        ~Player();
        float getX();
        float getY();
        float getZ();
        float getLargura();
        float getAltura();
        float getProfundidade();
        bool getVida();
        void setX(float x);
        void setY(float y);
        void setZ(float z);
        void setLargura(float lar);
        void setAltura(float alt);
        void setProfundidade(float pro);
        void setVida(bool vida);
        void moveDir();
        void moveEsq();
        bool IntervaloX(float x);
        bool IntervaloY(float y);
        void Colisao(Cubo *cubo);
        void drawPlayer();
        float getEscalaX();
        float getEscalaY();
        float getEscalaZ();
        float setEscalaX(float escalaX);
        float setEscalaY(float escalaY);
        float setEscalaZ(float escalaZ);
        void readObject(char* nomeArquivo);
};
