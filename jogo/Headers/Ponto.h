#ifndef PONTO_H
#define PONTO_H

class Ponto{
    private:
        float x;
        float y;
        float z;
    public:
        Ponto();
        ~Ponto();
        Ponto(float x, float y, float z);
        float* vector(float vetor[]);
        float getX();
        float getY();
        float getZ();
	    void setX(float x);
	    void setY(float y);
	    void setZ(float z);

};

#endif
