#include "Player.hpp"

#include <SDL/SDL.h>
#include "SDL/SDL_opengl.h"
#include <iostream>
#include <vector>

using namespace std;

Player::Player()
{
  this->positionX = 0;
  this->positionY = 0;
  this->length = 30;
  this->height = 50;
  this->hp = 100;
  this->jFrameLength = 600;
  this->jFrameHeight = 400;
}

Player::Player(float positionX, float positionY, float positionZ, float length, float height, float depth, float hp, float jFrameLength, float jFrameHeight)
{
  this->positionX = positionX;
  this->positionY = positionY;
  this->positionZ = positionZ;
  this->length = length;
  this->height = height;
  this->depth = depth;
  this->hp = hp;
  this->jFrameLength = jFrameLength;
  this->jFrameHeight = jFrameHeight;
}

Player::~Player(){}

void Player::moveUp(bool up)
{
  if(up)//move to up
  {
    if(this->positionY-1 >= 0)//if player position y > 0
    {
      positionY--;
    }
  }
}

void Player::moveDown(bool down)
{
  if(down)//move to down
  {
    if(this->positionY+this->height+1 <= this->jFrameHeight)//if player position y < max y
    {
      positionY++;
    }
  }
}

void Player::moveLeft(bool left)
{
  if(left)//move to left
  {
    if(this->positionX-1 >= 0)//if player position x > 0
    {
      positionX--;
    }
  }
}

void Player::moveRight(bool right)
{
  if(right)//move to right
  {
    if(this->positionX+this->length+1 <= this->jFrameLength)//if player position x < max x
    {
      positionX++;
    }
  }
}

float Player::getPositionY()
{
  return this->positionY;
}

float Player::getPositionZ()
{
  return this->positionZ;
}

float Player::getPositionX()
{
  return this->positionX;
}

float Player::getLength()
{
  return this->length;
}

float Player::getHeight()
{
  return this->height;
}

float Player::getDepth()
{
  return this->depth;
}

void Player::drawPlayer()
{
  glBegin(GL_QUADS);

    //glVertex2f(x, y);
    glVertex3f(this->getPositionX(), this->getPositionY(), this->getPositionZ());
    glVertex3f(this->getPositionX()+this->getLength(), this->getPositionY(), this->getPositionZ());
    glVertex3f(this->getPositionX()+this->getLength(), this->getPositionY()+this->getHeight(), this->getPositionZ());
    glVertex3f(this->getPositionX(), this->getPositionY()+this->getHeight(), this->getPositionZ());

  glEnd();
}
