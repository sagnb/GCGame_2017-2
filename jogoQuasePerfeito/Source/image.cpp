#include <fstream>
#include <iostream>

#include <vector>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <cstring>
#include "../Headers/image.hpp"

using namespace std;

image::image()
{
    buffer.resize(1920,vector<pixel> (1280));
}

image::image(int nwidth, int nheight)
{
    buffer.resize(nwidth,vector<pixel> (nheight));
}

image::image(int nwidth, int nheight, pixel color,int maxcolor)
{
    width = nwidth;
    height = nheight;
    buffer.resize(nwidth,vector<pixel> (nheight));
    setMC(maxcolor);
    putimage(color);
}

image::~image()
{

}

int image::getWidth()
{
    return width;
}
int image::getHeight()
{
    return height;
}


void image::loadimage(string nome)
{
    int red,green,blue;
    cout << "Arquivo de entrada "<< nome <<endl;
    ifstream iFile(nome.c_str());

    if (iFile == NULL)
    {
        cout << "Missing file!" << endl;
        exit(-1);
    }

    iFile.ignore(INT_MAX, '\n');
//    iFile.ignore(INT_MAX, '\n'); // REMOVED BECAUSE OF imagemagick-CONVERT NOT INSERTING COMMENT LINE IN IMAGE
// IF USING IRFANVIEW, UNCOMMENT LINE ABOVE

    iFile >> width;
    iFile >> height;
    iFile >> maxcolor;
    buffer.resize(width,vector<pixel> (height));
    cout << width << " " << height << endl << maxcolor << endl;

    for(int j=0; j<height; j++)
        for(int i=0; i<width; i++)
        {

            iFile >> red;
            iFile >> green;
            iFile >> blue;

            putPixel(i,j,red,green,blue);
        }

    iFile.close();
}

void image::saveimage(string nombre)
{
    ofstream oFile(nombre.c_str());
    /*
        if (oFile == NULL)
        {
            cout << "Missing file!" << endl;
            exit(0);
        }
    */
    oFile << "P3\n" << width << " " << height << "\n" << maxcolor << "\n";


    for(int j=0; j<height; j++)
    {
        for(int i=0; i<width; i++)
        {
            oFile << getred(i,j) << " " << getgreen(i,j) << " " << getblue(i,j) << " ";
        }
        oFile << endl;
    }

    oFile.close();
}

void image::putPixel(float i,float j,int red=0,int green=0,int blue=0)
{
    buffer[i][j].r=red;
    buffer[i][j].g=green;
    buffer[i][j].b=blue;
}

void image::setMC(int color)
{
    maxcolor = color;
}

void image::putimage(pixel color)
{
    for(int i = 0; i<width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            putPixel(i,j,color.r,color.g,color.b);
        }
    }
}


int image::getred(int i, int j)
{
    return  buffer[i][j].r;
}
int image::getgreen(int i, int j)
{
    return  buffer[i][j].g;
}
int image::getblue(int i, int j)
{
    return  buffer[i][j].b;
}

void image::drawline(float x0, float y0, float xn, float yn,int r,int g,int b)
{
    float dx=0, dy=0, sdx, sdy, px, py;

    if((xn - x0) >= 0)
    {
        sdx = 1;
    }
    else
    {
        sdx = -1;
    }

    if((yn-y0) >= 0)
    {
        sdy = 1;
    }
    else
    {
        sdy = -1;
    }
    dx = abs(xn-x0);
    dy = abs(yn-y0);
    px=dy/*>>1*/;
    py=dx/*>>1*/;

    if(dx >= dy)  /* A linha é mais horizontal do que vertical */
    {
        for(int i=0; i<dx; i++)
        {
            py+=dy;
            if (py >= dx)
            {
                py -= dx;
                y0 += sdy;
            }
            x0 += sdx;
            if( (x0 > 0) && (x0 < width) && (y0 > 0) && (y0 < height) )
            {
                putPixel(x0, y0, r, g, b);
            }
        }
    }
    else    /* the line is more vertical than horizontal */
    {
        for(int i=0; i<dy; i++)
        {
            px += dx;
            if (px >= dy)
            {
                px -= dy;
                x0 += sdx;
            }
            y0 += sdy;
            if( (x0 > 0) && (x0 < width) && (y0 > 0) && (y0 < height) )
            {
                putPixel(x0, y0, r, g, b);
            }
        }
    }
}
