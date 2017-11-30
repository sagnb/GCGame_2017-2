#ifndef ARESTA_H
#define ARESTA_H

#include "Ponto.h"
#include "image.hpp"

class Aresta{
    private:
        Ponto p1;
        Ponto p2;
        Ponto vetDir;
        int dist;
        void calcProj();
    public:
        Aresta();
        ~Aresta();
        Aresta(Ponto p1, Ponto p2);
        void glAresta();
        Ponto getP1();
        Ponto getP2();
	    Ponto getvetDir();
	    void calcula_vetDir ();
      float getMinX();
      float getMinY();
      float getMinZ();
      float getMaxX();
      float getMaxY();
      float getMaxZ();

};
#endif
