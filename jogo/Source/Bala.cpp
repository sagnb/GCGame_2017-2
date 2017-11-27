#include "..Headers/Bala.hpp"

using namespace std;

Bala(){

}

Bala(float x, float y, float z)
{
      this->x = x;
      this->y = y;
      this->z = z;
      this->largura = 1;
      this->altura = 1;
      this->profundidade = 1;
}

float Bala::getX()
{
    return this->x;
}

float Bala::getY()
{
    return this->y;
}

float Bala::getZ()
{
    return this->z;
}

float Bala::getLargura()
{
    return largura;
}

float Bala::getAltura()
{
  return altura;
}

float Bala::getProfundidade(){
    return profundidade;
}

void Bala::setX(float x)
{
    this->x = x;
}

void Bala::setY(float y)
{
    this->y = y;
}

void Bala::setZ(float z)
{
    this->z = z;
}

void Bala::setLargura(float lar)
{
    this->largura = lar;
}

void Bala::setAltura(float alt)
{
    this->altura = alt;
}

void Bala::setProfundidade(float pro)
{
    this->profundidade = pro;
}
