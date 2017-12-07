#ifndef STAR_H
#define STAR_H

class Star
{
private:
    float x;
    float y;
    float z;
    int velocidade;

public:
    Star();
    Star(float x, float y, float z, int velocidade);
    ~Star();
    void setX(float x);
    void setY(float y);
    void setZ(float z);
    void setVelocidade(int velocidade);
    float getX();
    float getY();
    float getZ();
    int getVelocidade();
    void move();
    void draw();
};

#endif
