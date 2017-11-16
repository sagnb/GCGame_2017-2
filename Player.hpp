#ifndef PLAYER_H
#define PLAYER_H

#include <SDL/SDL.h>
#include "SDL/SDL_opengl.h"
#include <iostream>
#include <vector>

class Player
{
  private:
    float positionX;
    float positionY;
    float length;
    float height;
    float depth;
    float hp;
    float jFrameLength;
    float jFrameHeight;

  public:
    Player();
    ~Player();
    Player(float positionX, float positionY, float length, float height, float depth, float hp, float jFrameLength, float jFrameHeight);
    void moveUp(bool up);
    void moveDown(bool down);
    void moveLeft(bool left);
    void moveRight(bool right);
    float getPositionX();
    float getPositionY();
    float getLength();
    float getHeight();
    float getDepth();
    void drawPlayer();
};

#endif
