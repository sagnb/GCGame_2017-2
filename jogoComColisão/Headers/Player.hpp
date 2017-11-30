#ifndef PLAYERJOGO_H
#define PLAYERJOGO_H

#include "Object.h"
#include "Cubo.hpp"

#include "GL/glut.h"

using namespace std;

class Player
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
          float r;
          float g;
          float b;
          float alpha;

      public:
        Player();
        Player(char* nomeArquivo, float x, float y, float z, float escalaX, float escalaY, float escalaZ, float r, float g, float b, float alpha);
        Player(Object* objeto, float x, float y, float z, float escalaX, float escalaY, float escalaZ, float r, float g, float b, float alpha);
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
        //void Colisao(Cubo *cubo);
        void drawPlayer();
        float getEscalaX();
        float getEscalaY();
        float getEscalaZ();
        float setEscalaX(float escalaX);
        float setEscalaY(float escalaY);
        float setEscalaZ(float escalaZ);
        void readObject(char* nomeArquivo);
        void setObject(Object* objeto);
        void setR(float r);
        void setG(float g);
        void setB(float b);
        void setAlpha(float alpha);
        float getR();
        float getG();
        float getB();
        float getAlpha();
        void setColor(float r, float g, float b, float alpha);
        void defineLuz();
};

#endif
