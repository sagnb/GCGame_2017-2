#include "../Headers/Cubo.hpp"

using namespace std;

Cubo::Cubo(){

}

Cubo::Cubo(float x, float y, float z, float lado)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->lado = lado;
    this->vida = true;
}

Cubo::~Cubo()

float Cubo::getX(){
    return this->x;
}

float Cubo::getY(){
    return this->y;
}

float Cubo::getZ(){
    return this->z;
}

float Cubo::getLado(){
    return this->lado;
}

bool Cubo::getVida(){
    return this->vida;
}

void Cubo::setVida(bool vida){
    this->vida = vida;
}

void Cubo::setX( float x){
    this->x = x;
}

void Cubo::setY( float y){
    this->y = y;
}

void Cubo::setZ( float z){
    this->z = z;
}

void Cubo::setLado(float lado){
    this->lado = lado;
}

void Cubo::MoveInimigo(){
    this->y--;
}

bool Cubo::IntervaloX(float x){
    if(this->getX() <= x && (this->getX() + this->getLado() >= x){
        return true;
    }
    return false;

}
bool Cubo::IntervaloY(float y){
    if(this->getY() <= y && (this->getY() + this->getLado() >= y){
      //ESTA NO INTERVALO
        return true;
    }
    return false;
}

void Cubo::Colisao(Bala *bala){
    if(IntervaloX(bala->getX()) && IntervaloY(bala->getY())){
        if(IntervaloX(bala->getX()+bala->getLargura()) && IntervaloY(bala->getY() + bala->getAltura())){
              setVida(false);
        }
    }
}
