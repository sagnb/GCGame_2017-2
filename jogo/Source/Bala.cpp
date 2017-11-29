#include "../Headers/Bala.hpp"
#include "../Headers/Object.h"

#include <iostream>
#include <stdlib.h>
#include "GL/glut.h"

using namespace std;

Bala::Bala(){
}

Bala::Bala(char* nome, float x, float y, float z, int vel)
{
      this->readObject(nome);
      this->setX(x);
      this->setY(y);
      this->setZ(z);
      this->setLargura(1);
      this->setAltura(1);
      this->setProfundidade(1);
      this->setVelocidade(vel);
      this->drawBala();
}

Bala::~Bala(){
  delete(bala);
}

float Bala::getX()
{
    return this->x;
}

int Bala::getVelocidade()
{
  return this->velocidade;
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

void Bala::setVelocidade(int vel){
    this->velocidade = vel;
}

void Bala::drawBala()
{
  glPushMatrix();
     glTranslatef(this->getX(), this->getY(), this->getZ());
     glScalef(2, 2, 2);
     glRotatef(90,1,0,0);
     glColor4f(0.0f,0.0f,0.3f, 1.0f);
     this->bala->glObject();
  glPopMatrix();

}

void Bala::Percurso()
{
    this->z += getVelocidade();
}

void Bala::readObject(char* nome)
{
  this->bala = new Object();
  this->bala->readObject(nome);
}
