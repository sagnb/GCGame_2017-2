#ifndef CUBO_H
#define CUBO_H

#include "GL/glut.h"

class Cubo()
{
    private:
        GLuint texture[3];
        float x;
        float y;
        float z;
        float lado; // LARGURA / ALTURA / PROFUNDIDADE

    public:
        Cubo(){

        }

        Cubo(float x, float y, float z, float lado)
        {
            this->x = x;
            this->y = y;
            this->z = z;
            this->lado = lado;
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
}
