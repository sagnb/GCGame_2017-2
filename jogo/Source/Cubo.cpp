#include "../Headers/Cubo.hpp"
#include "../Headers/Player.hpp"
#include "../Headers/Bala.hpp"

using namespace std;

Cubo::Cubo(){

}

Cubo::Cubo(float x, float y, float z, float lado)
{
    this->setX(x);
    this->setY(y);
    this->setZ(z);
    this->setLado(lado);
    this->setVida(true);
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
    if((this->getX() <= x) && (this->getX() + this->getLado() >= x)){
        return true;
    }
    return false;

}
bool Cubo::IntervaloY(float y){
    if((this->getY()) <= y && (this->getY() + this->getLado() >= y)){
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

void Cubo::drawCubo()
{

      glBindTexture( GL_TEXTURE_2D, texture[0]);
      glBegin (GL_QUADS);//POLYGON);
            glTexCoord2f(0.0, 0.0); glVertex3f(-5, -5, -5.0);
            glTexCoord2f(0.0, 1.0); glVertex3f(-5, 5, -5.0);
            glTexCoord2f(1.0, 1.0); glVertex3f(5, 5, -5.0);
            glTexCoord2f(1.0, 0.0); glVertex3f(5, -5, -5.0);
      glEnd();

       glBindTexture( GL_TEXTURE_2D, texture[0]);
      glBegin (GL_QUADS);//POLYGON);
          glTexCoord2f(0.0, 0.0); glVertex3f(-5.0,-5.0, 5.0);
            glTexCoord2f(0.0, 1.0); glVertex3f(5, -5, 5.0);
            glTexCoord2f(1.0, 1.0); glVertex3f(5, 5, 5.0);
            glTexCoord2f(1.0, 0.0); glVertex3f(-5, 5, 5.0);
      glEnd();


       glBindTexture( GL_TEXTURE_2D, texture[0]);
       glBegin (GL_QUADS);
            glTexCoord2f(0.0, 0.0); glVertex3f(5.0,-5.0, -5.0);
            glTexCoord2f(0.0, 1.0); glVertex3f(5.0, 5.0, -5.0);
            glTexCoord2f(1.0, 1.0); glVertex3f(5.0, 5.0, 5.0);
            glTexCoord2f(1.0, 0.0); glVertex3f(5.0,-5.0, 5.0);
      glEnd();

       glBindTexture( GL_TEXTURE_2D, texture[0]);
       glBegin (GL_QUADS);
           glTexCoord2f(0.0, 0.0); glVertex3f(-5.0,-5.0, -5.0);
            glTexCoord2f(0.0, 1.0); glVertex3f(-5.0, -5, 5.0);
            glTexCoord2f(1.0, 1.0); glVertex3f(-5.0, 5.0, 5.0);
            glTexCoord2f(1.0, 0.0); glVertex3f(-5.0, 5.0, -5.0);

      glEnd();

       glBindTexture( GL_TEXTURE_2D, texture[0]);
       glBegin (GL_QUADS);
            glTexCoord2f(0.0, 0.0); glVertex3f(-5.0, -5.0, -5.0);
            glTexCoord2f(0.0, 1.0); glVertex3f(5.0, -5.0, -5.0);
            glTexCoord2f(1.0, 1.0); glVertex3f(5.0, -5.0, 5.0);
            glTexCoord2f(1.0, 0.0); glVertex3f(-5.0, -5.0, 5.0);
      glEnd();

       glBindTexture( GL_TEXTURE_2D, texture[0]);
       glBegin (GL_QUADS);
            glTexCoord2f(0.0, 0.0); glVertex3f(-5.0, 5.0, -5.0);
            glTexCoord2f(0.0, 1.0); glVertex3f(-5.0, 5.0, 5.0);
            glTexCoord2f(1.0, 1.0); glVertex3f(5.0, 5.0, 5.0);
            glTexCoord2f(1.0, 0.0); glVertex3f(5.0,5.0, -5.0);
      glEnd();
}
