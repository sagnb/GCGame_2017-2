#ifndef FACE_H
#define FACE_H

#include <vector>
#include "Aresta.h"
#include "Ponto.h"
#include "image.hpp"
#include <GL/glut.h>

class Face{
    private:
        std::vector<Aresta> arestas;
        int n_arestas;
	    float vetZ, vetY, vetX;
	    float pZ;

    public:
        Face();
        ~Face();
        std::vector<Aresta> getArestas();
        void addAresta(Aresta aresta);
        void glFace(int comTextura, GLuint texture);
	    void calcula_vetZ();
        float getvetZ();
        
};

#endif
