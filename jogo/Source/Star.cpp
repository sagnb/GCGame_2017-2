#include "../Headers/Star.hpp"
#include "GL/glut.h"

using namespace std;

Star::Star()
{

}

Star::Star(float x, float y, float z, int velocidade)
{
    this->setX(x);
    this->setY(y);
    this->setZ(z);
    this->setVelocidade(velocidade);
}

Star::~Star()
{

}

void Star::setX(float x)
{
    this->x = x;
}

void Star::setY(float y)
{
    this->y = y;
}

void Star::setZ(float z)
{
    this->z = z;
}

void Star::setVelocidade(int velocidade)
{
    this->velocidade = velocidade;
}

float Star::getX()
{
    return this->x;
}

float Star::getY()
{
    return this->y;
}

float Star::getZ()
{
    return this->z;
}

int Star::getVelocidade()
{
    return this->velocidade;
}

void Star::move()
{
    this->setZ(this->getZ()-this->getVelocidade());
}

void Star::draw()
{
    glPushMatrix();

    glTranslatef(this->getX(), this->getY(),this->getZ());
    glColor4f(20.0f,20.0f,20.0f, 1.0f);
    glLineWidth(3.0f);
    glBegin (GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 4);
    glEnd();
    glPopMatrix();
}
