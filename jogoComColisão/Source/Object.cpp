#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>
#include <cmath>
#include "../Headers/Object.h"
#include "../Headers/image.hpp"
#include <GL/glut.h>
#define PI 3.14159265

using namespace std;

Object::Object(){
    comTextura = 0;
}
Object::~Object(){}

int Object::getNFaces(){
    return n_faces;
}

vector<Face> Object::getFaces(){
    return faces;
}
void Object::addFace(Face face){
    faces.push_back(face);
}

void Object::glObject(){
    for(int i = 0; i < faces.size(); i++){
        faces[i].glFace(comTextura, texture);//mostra o obj
    }
}

void Object::readObject(const char *nomeArquivo){
    ifstream file;
    file.open(nomeArquivo,ios::in);

    vector<Ponto> pontos;
    vector<Ponto> normais;
    vector<Ponto> texturas;

    if (!file){
        cout << "Problemas na leitura do arquivo" << endl;
    }else{

        string line;

        char type;
        float a = 0,b = 0,c = 0;
        int aresta;

        do{


            vector<Aresta> arestas;
            Face face;
            stringstream sline;
            getline(file, line);
            sline << line;
            sline >> type;
            if(type == 'v'){

                sline >> a >> b >> c;
                if(abs(c) > minZ){
                    minZ = abs(c);
                }
                Ponto p = Ponto(a,b,c);
                pontos.push_back(p);

            }else if(type == 'f'){

                vector<int> as;
                do{
                    sline >> aresta;
                    as.push_back(aresta);
                }while(sline);

                for(int i = 0; i < as.size();i++){

                    if(i != as.size()-1){
                        arestas.push_back( Aresta(pontos[as[i]-1], pontos[as[i+1]-1]) );
                    } else {
                        arestas.push_back( Aresta(pontos[as[i]-1], pontos[as[0]-1]));

                    }
                }

                for(int i = 0; i < arestas.size();i++){
                    face.addAresta(arestas[i]);
                }
                this->addFace(face);

            }

        }while(file);
        faces.pop_back();

    }

}

float Object::getMinX()
{
  float minX = 0;
  for(int i = 0; i < this->faces.size(); i++)
  {
    if(this->faces[i].getMinX() <= minX)
    {
      minX = this->faces[i].getMinX();
    }
  }
  return minX;
}

float Object::getMinY()
{
  float minY = 0;
  for(int i = 0; i < this->faces.size(); i++)
  {
    if(this->faces[i].getMinY() <= minY)
    {
      minY = this->faces[i].getMinY();
    }
  }
  return minY;
}

float Object::getMinZ()
{
  float minZ = 0;
  for(int i = 0; i < this->faces.size(); i++)
  {
    if(this->faces[i].getMinZ() <= minZ)
    {
      minZ = this->faces[i].getMinZ();
    }
  }
  return minZ;
}

float Object::getMaxX()
{
  float maxX = 0;
  for(int i = 0; i < this->faces.size(); i++)
  {
    if(this->faces[i].getMaxX() >= maxX)
    {
      maxX = this->faces[i].getMaxX();
    }
  }
  return maxX;
}

float Object::getMaxY()
{
  float maxY = 0;
  for(int i = 0; i < this->faces.size(); i++)
  {
    if(this->faces[i].getMaxY() >= maxY)
    {
      maxY = this->faces[i].getMaxY();
    }
  }
  return maxY;
}

float Object::getMaxZ()
{
  float maxZ = 0;
  for(int i = 0; i < this->faces.size(); i++)
  {
    if(this->faces[i].getMaxZ() >= maxZ)
    {
      maxZ = this->faces[i].getMaxZ();
    }
  }
  return maxZ;
}

float Object::getLargura()
{
  return this->getMaxX() - this->getMinX();
}

float Object::getAltura()
{
  return this->getMaxY() - this->getMaxY();
}

float Object::getProfundidade()
{
  return this->getMaxZ() - this->getMaxZ();
}
