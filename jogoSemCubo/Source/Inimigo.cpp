#include "../Headers/Inimigo.hpp"
#include "../Headers/Object.h"
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <vector>

#include "GL/glut.h"

Inimigo::Inimigo()
{

}

Inimigo::Inimigo(Object* objeto, float x, float y, float z, float raio, int velocidade)
{
    this->setObject(objeto);
    this->setX(x);
    this->setY(y);
    this->setZ(z);
    this->setRaio(raio);
    this->setVelocidade(velocidade);
    this->setVida(true);
    this->setFlag(true);
}

Inimigo::~Inimigo()
{
    delete(objeto);
}

void Inimigo::setObject(Object *objeto)
{
    this->objeto = objeto;
}

float Inimigo::getX()
{
    return this->x;
}

float Inimigo::getY()
{
    return this->y;
}

float Inimigo::getZ()
{
    return this->z;
}

float Inimigo::getRaio()
{
    return this->raio;
}

bool Inimigo::getVida()
{
    return this->vida;
}

void Inimigo::setX( float x)
{
    this->x = x;
}

void Inimigo::setY( float y)
{
    this->y = y;
}

void Inimigo::setZ( float z)
{
    this->z = z;
}

void Inimigo::setRaio(float raio)
{
    this->raio = raio;
}

void Inimigo::setVida(bool vida)
{
    this->vida = vida;
}

void Inimigo::MoveInimigo()
{
    this->setZ(this->getZ()-1);
}

bool Inimigo::IntervaloX(float x)
{
    if((this->getX() - this->getRaio() <= x) && (this->getX() + this->getRaio() >= x))
    {
        return true;
    }
    return false;
}

bool Inimigo::IntervaloZ(float z)
{
    if((this->getZ()- this->getRaio()) <= z && (this->getZ() + this->getRaio() >= z))
    {
        //ESTA NO INTERVALO
        return true;
    }
    return false;
}

void Inimigo::Colisao(vector <Bala*> balas, Player *play)
{
    if(this->getVida())
    {
        for(int i = 0; i < balas.size(); i++)
        {
            if(balas[i]->getVida())
            {

                if(IntervaloX(balas[i]->getX()) && IntervaloZ(balas[i]->getZ()))
                {
                    if(IntervaloX(balas[i]->getX()) && IntervaloZ(balas[i]->getZ()))
                    {
                        this->setVida(false);
                        balas[i]->setVida(false);
                        play->addMortos();
                        play->Bonus();
                    }

                }
                //PASSOU OS LIMITES DO PLANO
                if(balas[i]->getZ() > 300)
                {
                    balas[i]->setVida(false);
                }
            }


        }

        if(IntervaloX(play->getX()) && IntervaloZ(play->getZ()))
        {

            play->setVida(false); //PERDEU COLISAO ENTRE PERSONAGEM E CUBO

        }

        //CUBO PASSOU PELO JOGADOR
        if(this->getZ() < play->getZ())
        {
            play->setVida(false);
        }

    }
}

void Inimigo::drawInimigo()
{
    if(this->getVida())
    {
        glPushMatrix();
        glTranslatef(this->getX(), this->getY(),this->getZ());
        glScalef(this->getRaio(), this->getRaio(), this->getRaio());
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        this->objeto->glObject();
        glPopMatrix();
    }
}

void Inimigo::ia(Player *nave)
{
    if (this->getX() >= 250 || this->getX() <= -250)
    {
        this->setVelocidade(-this->getVelocidade());
    }
    else if(this->IntervaloX(nave->getX()))
    {
        int anda = rand()%2;

        if(anda == 0 &&  this->getFlag())
        {
            this->setVelocidade(-this->getVelocidade());
            this->setFlag(false);
        }
        else if(anda == 1 &&  this->getFlag())
        {
            this->setVelocidade(this->getVelocidade()+1);
            this->setFlag(false);
        }

    }


    this->setX(getX() + this->getVelocidade());

}

void Inimigo::setFlag(bool flag)
{
    this->flag = flag;
}

bool Inimigo::getFlag()
{
    return this->flag;
}

void Inimigo::setVelocidade(int velocidade)
{
    this->velocidade = velocidade;
}

int Inimigo::getVelocidade()
{
    return this->velocidade;
}
