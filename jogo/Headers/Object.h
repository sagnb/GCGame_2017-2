#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include "../Headers/Face.h"
#include "image.hpp"
#include <string>
#include <GL/glut.h>

class Object{
    private:
        std::vector<Face> faces;
        int n_faces;
        float minZ; 
        int comTextura;
        GLuint texture;
    public:
        Object();
        ~Object();
        std::vector<Face> getFaces();
        void addFace(Face face);
        void outObject();
        void printObject(image *im, float s,float d, int r, int g, int b);
        void glObject();
        int getNFaces();
        void readObject(char* nomeArquivo);
        void rotateObject(char eixo, double angle);
        void sortFaces();
        void loadTexture(char* nome, int width, int height);
};

#endif
