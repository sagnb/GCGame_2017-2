
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
