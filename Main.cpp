#include <SDL/SDL.h>
#include "SDL/SDL_opengl.h"
#include <iostream>
#include <vector>
#include "Player.hpp"
#include <cmath>
//
using namespace std;

const float length = 600;
const float height = 400;

const float DEG2RAD = 3.14159/180;


int main(int argc, char *argv[])
{
  SDL_Init(SDL_INIT_EVERYTHING);

  // memo part
  SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

  //name of jframe
  SDL_WM_SetCaption("My First Game!", NULL);

  //size of jframe
  SDL_SetVideoMode(600, 400, 32, SDL_OPENGL);

  //init color/ clear color
  glClearColor(0, 0, 0, 0);

  //display area
  glViewport(0, 0, 600, 400);

  //shadow
  glShadeModel(GL_SMOOTH);

  // 2D
  glMatrixMode(GL_PROJECTION);

  //geometric draw
  glLoadIdentity();

  //disable 3D part
  glDisable(GL_DEPTH_TEST);

  bool exec = true;

  SDL_Event event;


  bool left = false; //esquerda
  bool right = false; //direita


  //loop Game
  cout << "Executando" << endl;
  Player *player;
  player = new Player(300, 350, 0, 30, 50, 10, 100, length, height);

  while(exec)
  {
    //events
    while(SDL_PollEvent(&event))
    {
      // exit for X
      if(event.type == SDL_QUIT)
      {
        exec = false;
      }
      //if keydown
      if(event.type == SDL_KEYDOWN)
      {
        if(event.key.keysym.sym == SDLK_a)//start move to left
        {
          left = true;
        }
        if(event.key.keysym.sym == SDLK_d)//start move to right
        {
          right = true;
        }

      }
      //if keyup
      if(event.type == SDL_KEYUP)
      {
        if(event.key.keysym.sym == SDLK_a)//stop move to left
        {
          left = false;
        }
        if(event.key.keysym.sym == SDLK_d)//stop move to right
        {
          right = false;
        }
        if(event.key.keysym.sym == SDLK_ESCAPE)//stop exec
        {
          exec = false;
        }
      }
    }
    //logic part
      //move part

      player->moveLeft(left);
      player->moveRight(right);


    //rendering part
    glClear(GL_COLOR_BUFFER_BIT);//clear buffer

    //init matrix
    glPushMatrix();

    //dim matrix
    glOrtho(0/*x0*/, length/*xend*/, height/*yend*/, 0/*y0*/, -1, 1);
    //glColor3d(1 ou 0)
    //glColor3f(0.0 ate 1.0)
    //glColor3ub(R, G, B) 0 A 255
    //glColor4ub(R, G, B, ALPHA) 0 A 255



    //draw
    //glBegin();//GL_POINTS, GL_LINES, GL_LINES_LOOP, GL_QUADS, GL_TRIANGLES, GL_POLIGON
    player->drawPlayer();


    //close matrix
    glPopMatrix();

    //animation part
    SDL_GL_SwapBuffers();
  }






  //SDL_Delay(5000);//delay of program code
  delete(player);
  SDL_Quit();

  return 0;
}
