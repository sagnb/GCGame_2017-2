
#include "../Headers/Player.hpp"

using namespace std;

Player()
{

}

Player(Object nave)
{
    this->nave = nave;
    this->x = 0;
    this->y = 15;
    this->z = 200;
    this->largura = 4;
    this->altura = 4;
    this->profundidade = 4;
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
    this->largura = lar;
}

void Player::setAltura(float alt)
{
    this->altura = alt;
}

void Player::setProfundidade(float pro)
{
    this->profundidade = pro;
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
  //FAZER
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
