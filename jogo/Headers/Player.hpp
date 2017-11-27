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
          public Player()
          {

          }

          public Player(Object nave)
          {
              this->nave = nave;
              this->x = 0;
              this->y = 15;
              this->z = 200;
          }


}
