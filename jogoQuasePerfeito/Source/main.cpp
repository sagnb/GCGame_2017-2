#include "../Headers/Object.h"
#include "../Headers/Ponto.h"
#include "../Headers/Aresta.h"
#include "../Headers/image.hpp"
#include "../Headers/Player.hpp"
#include "../Headers/Cubo.hpp"
#include "../Headers/Star.hpp"

#include <iostream>
#include "GL/glut.h"
#include <cmath>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <SDL/SDL_mixer.h> // sudo apt install libsdl-mixer2-dev
#include <SDL/SDL.h>

Mix_Music *musica = NULL; //música de fundo

using namespace std;

double CamX = 0, CamY = 0, CamZ = 0;
float angle = 0;
int theta = 0, qtBalas=0,mouseX=0, moveNave = 0;
GLfloat ratio;
GLuint textura;

Object *objbala, *objnave;
Player *nave;


vector <Bala*> b;
vector <Cubo*> c;
vector <GLuint> texturas;
vector <Star*> s;

void normalize(float* init);
GLuint loadTexture(const char* nome, int width, int height);
void plano(float x, float y, float z, float escalaX, float escalaY, float escalaZ);
void plano2(float x, float y, float z, float escalaX, float escalaY, float escalaZ);
Mix_Music *carregarMus(const char *nome);
int Musica();

Mix_Music *carregarMus(const char *nome){
	 Mix_Music *mus = Mix_LoadMUS(nome);
	  if(!mus)
		    printf("ERRO> arquivo:'%s'\n",nome);
	  return mus;
}

void init(void)
{

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable( GL_BLEND );

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Fundo de tela preto
    glShadeModel(GL_SMOOTH);
    glColorMaterial ( GL_FRONT, GL_AMBIENT_AND_DIFFUSE );
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glFrontFace(GL_CW);    //
    glCullFace(GL_FRONT);  //  Estas tres fazem o culling funcionar
    glEnable(GL_CULL_FACE);//

}

void reshape( int w, int h )
{
    ratio = 1.0f * w / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(90,ratio,0.01,700);

}

void timer(int value)
{
    theta+=1.5;
    if (theta >= 360) theta=0.0;
    glutPostRedisplay();
    glutTimerFunc(10, timer, 0);
}

void PosicUser()
{

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glFrustum(-10,10,-10,10,0,200);
    CamX = -280*sin(3.14*angle/180.0);
    CamY = 220;
    CamZ = -280*cos(3.14*angle/180.0);
    gluLookAt(CamX, CamY, CamZ,0.0,0.0,0.0, 0.0,1.0,0.0);

}

void displayText( float x, float y, int r, int g, int b, const char *string )
{
    int j = strlen( string );
    glColor3f( r, g, b );
    glRasterPos2f( x, y );
    for( int i = 0; i < j; i++ )
    {
        glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, string[i] );
    }
}

void display( void )
{
    if(moveNave > 0)
    {
        if(nave->getVida())
        {

            int dificuldade  = nave->getMortos()*4;
            if(dificuldade > 200)
            {
                dificuldade = 200;
            }
            if(rand()%(256 - (dificuldade)) == 0)
            {

                c.push_back(
                    new Cubo(texturas[rand()%(texturas.size()-1)], -200 + rand()%400 ,10,250,30)
                );
            }
            if(rand()%10 > 5)
            {

                s.push_back(
                    new Star(-300 + rand()%600 ,-300 + rand()%600,250,2)
                );
            }

            for(int i = 0; i < b.size(); i++)
            {
                if(!b[i]->getVida())
                {
                    swap(b[i], b.back());
                    b.pop_back();
                }
            }

            for(int i = 0; i < s.size(); i++)
            {
                if(s[i]->getZ() < -250)
                {
                    swap(s[i], s.back());
                    s.pop_back();
                }
            }



            if(nave->getVida())
            {
                for(int i = 0; i < c.size(); i++)
                {
                    c[i]->MoveInimigo();
                    c[i]->ia(nave);
                }
                for(int i = 0; i < c.size(); i++)
                {
                    c[i]->Colisao(b, nave);
                }
            }

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glMatrixMode(GL_MODELVIEW);
            glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

            PosicUser();

            glEnable( GL_TEXTURE_2D );

            for(int i = -1200; i <= 1200; i+=400)
            {
            plano(i, -200, 0, 200, 0, 200);
            plano(i, -200, 400, 200, 0, 200);
            plano(i, -200, -400, 200, 0, 200);
            }

            for(int i = -1200; i <= 1200; i+=400)
            {
            plano2(i, 0, 250, 200, 200, 0);
            plano2(i, 400, 250, 200, 200, 0);
            plano2(i, 400, 250, 200, 200, 0);
            }

            glDisable( GL_TEXTURE_2D );

            for(int i = 0; i < s.size(); i++)
            {
                s[i]->move();
                s[i]->draw();
            }

            if(nave->getVida())
            {
                for(int i = 0; i < b.size(); i++)
                {

                    b[i]->Percurso();
                    b[i]->drawBala();

                }
            }

            glEnable( GL_TEXTURE_2D );

            for(int i = 0; i < c.size(); i++)
            {
                c[i]->drawCubo();
            }

            glDisable( GL_TEXTURE_2D );
            if(nave->getVida())
            {
                nave->drawPlayer();
                nave->defineLuz();
            }

            stringstream s1;
            s1 << nave->getLimite();

            displayText(200,200, 255,0,0, "Computacao Grafica");
            displayText(-80,200, 255,0,0, "Balas");
            displayText(-130,200, 255,0,0, s1.str().c_str());

            //SEM BALAS
            if(nave->getLimite() <= 0 && b.size() <= 0)
            {
                nave->setVida(false);
            }

        }
        else
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glMatrixMode(GL_MODELVIEW);
            stringstream ss, s2;
            ss << "Pontuacao ";
            ss << nave->getMortos();
            s2 << "Balas Disparadas ";
            s2 << qtBalas;

            displayText(GLUT_SCREEN_WIDTH/2,GLUT_SCREEN_HEIGHT/2,255,255,255, "GAME OVER");
            displayText(GLUT_SCREEN_WIDTH/2,GLUT_SCREEN_HEIGHT/2-140,255,255,255, ss.str().c_str());
            displayText(GLUT_SCREEN_WIDTH/2+55,GLUT_SCREEN_HEIGHT/2-220,255,255,255, s2.str().c_str());
        }

        glutSwapBuffers();
    }
    else
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
        PosicUser();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        displayText(GLUT_SCREEN_WIDTH/2+200,GLUT_SCREEN_HEIGHT/2,255,255,255, "CLICK COM O BOTAO DIREITO DO MOUSE PARA COMECAR A ANDAR");
        displayText(GLUT_SCREEN_WIDTH/2-100,GLUT_SCREEN_HEIGHT/2-60,255,255,255, "OU");
        displayText(GLUT_SCREEN_WIDTH/2+80,GLUT_SCREEN_HEIGHT/2-120,255,255,255, "CLICK NOVAMENTE PARA PARAR");
        glutSwapBuffers();
    }
}

void keyboard ( unsigned char key, int x, int y )
{
    switch (key)
    {
    case 27:
        exit (0);
        break;
    /*
    case 'a':
    nave->moveEsq();
    break;
    case 'd':
    nave->moveDir();
    break;
    case ' ': //espaco
    if(nave->getVida() && (nave->getLimite() > 0))
     {
        b.push_back(new Bala(objbala, nave->getX(), 10, -200, 2));
        qtBalas +=1;
        nave->Tiro();
      }
    break;
    */
    default:

        break;
    }
}

void load()
{

    objbala = new Object();
    objnave = new Object();

    objnave->readObject("./Accets/ship.obj");
    objbala->readObject("./Accets/bala.obj");
//c2
    texturas.push_back(loadTexture("./Accets/ini.ppm", 300, 300));
		texturas.push_back(loadTexture("./Accets/inip.ppm", 300, 300));
    texturas.push_back(loadTexture("./Accets/marr.ppm", 300, 300));
  //  texturas.push_back(loadTexture("./Accets/c7.ppm", 300, 300));
    texturas.push_back(loadTexture("./Accets/uni2.ppm", 300, 300));

    nave = new Player(objnave, 0, 15, -200, 4, 4, 4, 1.0f, 2.5f, 1.0f, 1);

}

void Mouse(int button, int state, int x, int y)
{

    if (button == GLUT_LEFT_BUTTON)
    {
        if (state == GLUT_DOWN)
        {
            if(nave->getVida() && (nave->getLimite() > 0))
            {
                b.push_back(new Bala(objbala, nave->getX(), 10, -200, 2));
                qtBalas +=1;
                nave->Tiro();
            }
        }
    }



    else if(button == GLUT_RIGHT_BUTTON )
    {
        if (state == GLUT_DOWN)
        {
            moveNave++;
        }
    }


}

void moviMouse(int x, int y)
{

    if(moveNave%2 == 1)
    {

        if(mouseX > x)
        {
            nave->moveEsq();

        }
        else if(mouseX < x)
        {
            nave->moveDir();

        }
        mouseX = x;
    }

}

int Musica(){
				if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
							return -1;

				//musica = carregarMus("./Accets/Powder.mp3");
				musica = carregarMus("./Accets/Cub.ogg");

				if( Mix_PlayingMusic() == 0 ){ // sem música
							if( Mix_PlayMusic( musica, -1 ) == -1 ) //- play música
												printf("ERRO> Mix_PlayMusic\n");
				}else{
									if( Mix_PausedMusic() == 1 ){
						            Mix_ResumeMusic(); // continua tacando
									}else{
						            Mix_PauseMusic(); // pausar música
									}
				}
}
int main(int argc, char** argv)
{

    srand(time(NULL));
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowPosition (0,0);
    glutInitWindowSize(1000, 700);
    glutCreateWindow("Game");

    load();
    init();
		Musica();


    glutDisplayFunc ( display );
    glutReshapeFunc ( reshape );
    glutKeyboardFunc ( keyboard );
    glutMouseFunc( Mouse );
    glutPassiveMotionFunc( moviMouse );

    glutTimerFunc(10, timer, 0);
    glutIdleFunc ( display );


    glutMainLoop ( );
		Mix_FreeMusic(musica);
		Mix_CloseAudio();
    return 0;

}

GLuint loadTexture(const char* nome, int width, int height)
{
    GLuint textura;
    int red,green,blue;
    ifstream iFile(nome);
    string val;

    if (iFile == NULL)
    {
        cout << "Missing file!" << endl;
        exit(-1);
    }

    unsigned char *data = new unsigned char[width * height * 3];

    getline(iFile, val, '\n');
    getline(iFile, val, '\n');
    getline(iFile, val, '\n');

    for (int i=0; i<(width*height*3); i+=3)
    {

        iFile >> red >> green >> blue;
        data[i]=(unsigned char)red;
        data[i+1]=(unsigned char)green;
        data[i+2]=(unsigned char)blue;

    }
    iFile.close();

    glGenTextures(1, &textura); // gera a textura vazia
    glBindTexture(GL_TEXTURE_2D, textura); //define a textura como a atual

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);// ativa repretição horizontal
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);// ativa a repetição vertical

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);// Ativam a interpolação
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);               //

    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);//mapeia o arquivo para a textura


    delete []data;
    return textura;
}

void plano(float x, float y, float z, float escalaX, float escalaY, float escalaZ)
{
  glPushMatrix();
  glTranslatef(x, y, z  );
  glScalef(escalaX,escalaY,escalaZ);

  glColor4f(1.0,1.0,1.0, 1.0);

  glBindTexture( GL_TEXTURE_2D, texturas[3]);
  glBegin (GL_QUADS);
  glTexCoord2f(0.0, 0.0);
  glVertex3f(-1.0, 1.0, -1.0);
  glTexCoord2f(0.0, 1.0);
  glVertex3f(-1.0, 1.0, 1.0);
  glTexCoord2f(1.0, 1.0);
  glVertex3f(1.0, 1.0, 1.0);
  glTexCoord2f(1.0, 0.0);
  glVertex3f(1.0,1.0, -1.0);
  glEnd();
  glPopMatrix();
}

void plano2(float x, float y, float z, float escalaX, float escalaY, float escalaZ)
{
  glPushMatrix();
  glTranslatef(x, y, z  );
  glScalef(escalaX,escalaY,escalaZ);

  glColor4f(1.0,1.0,1.0, 1.0);

  glBindTexture( GL_TEXTURE_2D, texturas[3]);
  glBegin (GL_QUADS);
  glTexCoord2f(0.0, 0.0);
  glVertex3f(-1.0, -1.0, -1.0);
  glTexCoord2f(0.0, 1.0);
  glVertex3f(-1.0, 1.0, -1.0);
  glTexCoord2f(1.0, 1.0);
  glVertex3f(1.0, 1.0, -1.0);
  glTexCoord2f(1.0, 0.0);
  glVertex3f(1.0, -1.0, -1.0);
  glEnd();
  glPopMatrix();
}
