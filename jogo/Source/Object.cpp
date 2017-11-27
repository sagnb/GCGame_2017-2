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
        faces[i].glFace(comTextura, texture);
    }
}

void Object::readObject(char *nomeArquivo){
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
