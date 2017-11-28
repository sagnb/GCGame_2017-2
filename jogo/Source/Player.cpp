
#include "../Headers/Player.hpp"
#include "../Headers/Player.hpp"

#include "GL/glut.h"

using namespace std;

Player::Player()
{

}

Player::Player(char* nomeArquivo, float x, float y, float z, float escalaX, float escalaY, float escalaZ)
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
  if(this->getX() <= x && (this->getX() + this->getLargura() >= x){
      return true;
  }
  return false;
}

bool Player::IntervaloY(float y){
  if(this->getY() <= y && (this->getY() + this->geAltura() >= y){
    //ESTA NO INTERVALO
      return true;
  }
  return false;
}

void Player::Colisao(Cubo *cubo){
  if(IntervaloX(cubo->getX()) && IntervaloY(cubo->getY())){
      if(IntervaloX(cubo->getX()+cubo->getLargura()) && IntervaloY(cubo->getY() + cubo->getAltura())){
            setVida(false);
      }
  }

}

void Player::drawPlayer()
{
  glPushMatrix();
      glTranslatef(ppos,15,-200);
     glScalef(4,4,4);
     glColor4f(0.0f,0.0f,0.3f, 1.0f);
     objeto->glObject();
  glPopMatrix();
}

float getEscalaX()
{
  return this->escalaX;
}

float getEscalaY()
{
  return this->escalaY;
}

float getEscalaZ()
{
  return this->escalaZ;
}

float setEscalaX(float escalaX)
{
  this->escalaX = escalaX;
}

float setEscalaY(float escalaY)
{
  this->escalaY = escalaY;
}

float setEscalaZ(float escalaZ)
{
  this->escalaZ = escalaZ;
}

void Player::readObject(char* nomeArquivo)
{
  nave = new Object();
  this->nave->readObject(nomeArquivo);
}
