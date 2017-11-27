#include <cstdlib>
#include <iostream>
#include "../Headers/Aresta.h"
#include "../Headers/Ponto.h"
#include "../Headers/image.hpp"
#include <GL/glut.h>

using namespace std;

Aresta::Aresta(){}
Aresta::~Aresta(){}

Aresta::Aresta(Ponto p1, Ponto p2){
    this->p1 = p1;
    this->p2 = p2;
    this->calcula_vetDir ();
}

void Aresta::glAresta(){
    float v1[3], v2[3];
    glVertex3fv(p1.vector(v1));
    glVertex3fv(p2.vector(v2));
}
void Aresta::calcula_vetDir ()
{
    this->vetDir.setX(p2.getX() - p1.getX());
    this->vetDir.setY(p2.getY() - p1.getY());
    this->vetDir.setZ(p2.getZ() - p1.getZ());
}

Ponto Aresta::getP1(){
    return this->p1;
}
Ponto Aresta::getP2(){
    return this->p2;
}
Ponto Aresta::getvetDir()
{
    return this->vetDir;
}
