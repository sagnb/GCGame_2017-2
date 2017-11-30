#include "../Headers/Cubo.hpp"

#include <iostream>
#include <cmath>
#include <stdio.h>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <vector>

#include "GL/glut.h"

using namespace std;

Cubo::Cubo(){
}

Cubo::Cubo(const char* nome, float x, float y, float z, float lado)
{
    this->setX(x);
    this->setY(y);
    this->setZ(z);
    this->setLado(lado);
    this->setVida(true);
    this->texture = loadTexture(nome, 200, 200);
}

Cubo::Cubo(GLuint textura, float x, float y, float z, float lado)
{
    this->setX(x);
    this->setY(y);
    this->setZ(z);
    this->setLado(lado);
    this->setVida(true);
    this->texture = textura;
}

Cubo::~Cubo(){

}

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
    this->setZ(this->getZ()-1);
}

bool Cubo::IntervaloX(float x){
    if((this->getX() - this->getLado() <= x) && (this->getX() + this->getLado() >= x)){
        return true;
    }
    return false;

}
bool Cubo::IntervaloZ(float z){
    if((this->getZ()- this->getLado()) <= z && (this->getZ() + this->getLado() >= z)){
      //ESTA NO INTERVALO
        return true;
    }
    return false;
}

bool Cubo::IntervaloXP(float x){
  if((this->getX() <= x) && (this->getX() + this->getLado() >= x)){
      return true;
  }
  return false;
}

bool Cubo::IntervaloYP(float y){
  if((this->getY() <= y) && (this->getY() + this->getLado() >= y)){
    //ESTA NO INTERVALO
      return true;
  }
  return false;
}

void Cubo::Colisao(vector <Bala*> balas, Player *play){
  if(this->getVida())
  {
  for(int i = 0; i < balas.size(); i++)
  {
    if(balas[i]->getVida())
    {
    //cout << "balas[i]->getX(): " << balas[i]->getX() << endl << "balas[i]->getLargura()" << balas[i]->getLargura() << endl;
    if(IntervaloX(balas[i]->getX()) && IntervaloZ(balas[i]->getZ())) {
        if(IntervaloX(balas[i]->getX()) && IntervaloZ(balas[i]->getZ())) {
              this->setVida(false);
              balas[i]->setVida(false);
              //cout << "certou\n";
              //exit(-1);
        }

    }
  }
      //exit(-1);

  }

    if(IntervaloX(play->getX()) && IntervaloZ(play->getZ())){
      //  if(IntervaloX(play->getX()+(play->getLargura())) && IntervaloZ(play->getZ() + (play->getProfundidade()))){
              setVida(false);
              play->setVida(false); //PERDEU COLISAO ENTRE PERSONAGEM E CUBO
      //  }
    }
  }
}

void Cubo::drawCubo()
{
  if(this->getVida())
  {
      glPushMatrix();
      glTranslatef(this->getX(), this->getY(), this->getZ());
      glScalef(this->getLado(),this->getLado(),this->getLado());
      glColor4f(1.0,1.0,1.0, 1.0);

      glBindTexture( GL_TEXTURE_2D, this->texture);
      glBegin (GL_QUADS);
            glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0, -1.0);
            glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, 1.0, -1.0);
            glTexCoord2f(1.0, 1.0); glVertex3f(1.0, 1.0, -1.0);
            glTexCoord2f(1.0, 0.0); glVertex3f(1.0, -1.0, -1.0);
      glEnd();

       glBindTexture( GL_TEXTURE_2D, this->texture);
      glBegin (GL_QUADS);
            glTexCoord2f(0.0, 0.0); glVertex3f(-1.0,-1.0, 1.0);
            glTexCoord2f(0.0, 1.0); glVertex3f(1.0, -1.0, 1.0);
            glTexCoord2f(1.0, 1.0); glVertex3f(1.0, 1.0, 1.0);
            glTexCoord2f(1.0, 0.0); glVertex3f(-1.0, 1.0, 1.0);
      glEnd();


       glBindTexture( GL_TEXTURE_2D, this->texture);
       glBegin (GL_QUADS);
            glTexCoord2f(0.0, 0.0); glVertex3f(1.0,-1.0, -1.0);
            glTexCoord2f(0.0, 1.0); glVertex3f(1.0, 1.0, -1.0);
            glTexCoord2f(1.0, 1.0); glVertex3f(1.0, 1.0, 1.0);
            glTexCoord2f(1.0, 0.0); glVertex3f(1.0,-1.0, 1.0);
      glEnd();

       glBindTexture( GL_TEXTURE_2D, this->texture);
       glBegin (GL_QUADS);
           glTexCoord2f(0.0, 0.0); glVertex3f(-1.0,-1.0, -1.0);
            glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, -5, 1.0);
            glTexCoord2f(1.0, 1.0); glVertex3f(-1.0, 1.0, 1.0);
            glTexCoord2f(1.0, 0.0); glVertex3f(-1.0, 1.0, -1.0);

      glEnd();

       glBindTexture( GL_TEXTURE_2D, this->texture);
       glBegin (GL_QUADS);
            glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0, -1.0);
            glTexCoord2f(0.0, 1.0); glVertex3f(1.0, -1.0, -1.0);
            glTexCoord2f(1.0, 1.0); glVertex3f(1.0, -1.0, 1.0);
            glTexCoord2f(1.0, 0.0); glVertex3f(-1.0, -1.0, 1.0);
      glEnd();

       glBindTexture( GL_TEXTURE_2D, this->texture);
       glBegin (GL_QUADS);
            glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, 1.0, -1.0);
            glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, 1.0, 1.0);
            glTexCoord2f(1.0, 1.0); glVertex3f(1.0, 1.0, 1.0);
            glTexCoord2f(1.0, 0.0); glVertex3f(1.0,1.0, -1.0);
      glEnd();

      glPopMatrix();
    }
}

GLuint Cubo::loadTexture(const char* nome, int width, int height){
    GLuint textura;
    int red,green,blue;
    ifstream iFile(nome);
    string val;

    if (iFile == NULL)
    {
        cout << "Missing file!" << endl;
        exit(-1);
    }

    unsigned char *data = new unsigned char[width * height * 3];

    getline(iFile, val, '\n');
    getline(iFile, val, '\n');
    getline(iFile, val, '\n');

    for (int i=0;i<(width*height*3);i+=3){

        iFile >> red >> green >> blue;
        data[i]=(unsigned char)red;
        data[i+1]=(unsigned char)green;
        data[i+2]=(unsigned char)blue;

    }
    iFile.close();

    glGenTextures(1, &textura); // gera a textura vazia
    glBindTexture(GL_TEXTURE_2D, textura); //define a textura como a atual

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);// ativa repretição horizontal
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);// ativa a repetição vertical

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);// Ativam a interpolação
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);               //

    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);//mapeia o arquivo para a textura


    delete []data;
    return textura;
}
