
#include "../Headers/Player.hpp"
#include "../Headers/Player.hpp"
#include "../Headers/Cubo.hpp"

#include "GL/glut.h"

using namespace std;

Player::Player(){}

Player::Player(char* nomeArquivo, float x, float y, float z, float escalaX, float escalaY, float escalaZ, float r, float g, float b, float alpha)
{
    this->readObject(nomeArquivo);
    this->setEscalaX(escalaX);
    this->setEscalaY(escalaY);
    this->setEscalaZ(escalaZ);
    this->setX(x);
    this->setY(y);
    this->setZ(z);
    this->setLargura(this->nave->getLargura());
    this->setAltura(this->nave->getAltura());
    this->setProfundidade(this->nave->getProfundidade());
    this->setVida(true);
    this->setColor(r, g, b, alpha);
}

Player::~Player()
{
  delete(nave);
}

float Player::getX()
{
    return this->x;
}

float Player::getY()
{
    return this->y;
}

bool Player::getVida(){
    return this->vida;
}

void Player::setVida(bool vida){
    this->vida = vida;
}

float Player::getZ()
{
    return this->z;
}

float Player::getLargura()
{
    return largura;
}

float Player::getAltura()
{
  return altura;
}

float Player::getProfundidade(){
    return profundidade;
}

void Player::setX(float x)
{
    this->x = x;
}

void Player::setY(float y)
{
    this->y = y;
}

void Player::setZ(float z)
{
    this->z = z;
}

void Player::setLargura(float lar)
{
    this->largura = lar * this->getEscalaX();
}

void Player::setAltura(float alt)
{
    this->altura = alt * this->getEscalaY();
}

void Player::setProfundidade(float pro)
{
    this->profundidade = pro * this->getEscalaZ();
}

void Player::moveDir()
{
    this->x++;
}

void Player::moveEsq()
{
    this->x--;
}

bool Player::IntervaloX(float x){
  if((this->getX() <= x) && (this->getX() + this->getLargura() >= x)){
      return true;
  }
  return false;
}

bool Player::IntervaloY(float y){
  if((this->getY() <= y) && (this->getY() + this->getAltura() >= y)){
    //ESTA NO INTERVALO
      return true;
  }
  return false;
}

void Player::Colisao(Cubo *cubo){
  if(IntervaloX(cubo->getX()) && IntervaloY(cubo->getY())){
      if(IntervaloX(cubo->getX()+cubo->getLado()) && IntervaloY(cubo->getY() + cubo->getLado())){
            setVida(false);
      }
  }

}

void Player::drawPlayer()
{
  glPushMatrix();
     glTranslatef(this->getX(), this->getY(),this->getZ());
     glScalef(this->getEscalaX(), this->getEscalaY(), this->getEscalaZ());
     glColor4f(this->getR(), this->getG(), this->getB(), this->getAlpha());
     this->nave->glObject();
  glPopMatrix();
}

float Player::getEscalaX()
{
  return this->escalaX;
}

float Player::getEscalaY()
{
  return this->escalaY;
}

float Player::getEscalaZ()
{
  return this->escalaZ;
}

float Player::setEscalaX(float escalaX)
{
  this->escalaX = escalaX;
}

float Player::setEscalaY(float escalaY)
{
  this->escalaY = escalaY;
}

float Player::setEscalaZ(float escalaZ)
{
  this->escalaZ = escalaZ;
}

void Player::readObject(char* nomeArquivo)
{
  nave = new Object();
  this->nave->readObject(nomeArquivo);
}

void Player::setR(float r)
{
  this->r = r;
}

void Player::setG(float g)
{
  this->g = g;
}

void Player::setB(float b)
{
  this->b = b;
}

void Player::setAlpha(float alpha)
{
  this->alpha = alpha;
}

float Player::getR()
{
  return this->r;
}

float Player::getG()
{
  return this->g;
}

float Player::getB()
{
  return this->b;
}

float Player::getAlpha()
{
  return this->alpha;
}

void Player::setColor(float r, float g, float b, float alpha)
{
  this->setR(r);
  this->setG(g);
  this->setB(b);
  this->setAlpha(alpha);
}
