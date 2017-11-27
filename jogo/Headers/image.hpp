#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include <string>




struct pixel
{
    int r;
    int g;
    int b;
};

class image
{
public:
    image();
    image(int nwidth, int nheight);
    image(int nwidth, int nheight, pixel color, int maxcolor);
    ~image();
    void loadimage(std::string nombre);
    void saveimage(std::string nombre);
    void putPixel(float x, float y, int red, int green, int blue);
    void setMC(int color);
    void putimage(pixel color);
    int getred(int x, int y);
    int getgreen(int x, int y);
    int getblue(int x, int y);
    void drawline(float x0, float y0, float xn, float yn,int r,int g,int b);
    int getWidth();
    int getHeight();
private:
    int width;
    int height;
    int maxcolor;
    std::vector< std::vector<pixel> > buffer;
};
#endif
