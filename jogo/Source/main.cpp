#include "../Headers/Object.h"
#include "../Headers/Ponto.h"
#include "../Headers/Aresta.h"
#include "../Headers/image.hpp"
#include "../Headers/Player.hpp"
#include "../Headers/Cubo.hpp"

#include <iostream>
#include "GL/glut.h"
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

double CamX = 0, CamY = 0, CamZ = 0;
float angle = 0;
int theta = 0;
GLfloat ratio;
GLuint textura;

Object *objbala, *objnave;
Player *nave;

vector <Bala*> b;
vector <Cubo*> c;
vector <GLuint> texturas;

void plano (int tam, int passo, float y);
void normalize(float* init);
GLuint loadTexture(const char* nome, int width, int height);


void init(void){

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

void reshape( int w, int h ){
    ratio = 1.0f * w / h;
	  glMatrixMode(GL_PROJECTION);
	  glLoadIdentity();
    glViewport(0, 0, w, h);
	  gluPerspective(90,ratio,0.01,700);

}

void timer(int value){
    theta+=1.5;
    if (theta >= 360){
			theta=0.0;
		}
    glutPostRedisplay();
    glutTimerFunc(10, timer, 0);
}

void PosicUser(){

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glFrustum(-10,10,-10,10,0,200);
	CamX = -280*sin(3.14*angle/180.0);
    CamY = 220;
    CamZ = -280*cos(3.14*angle/180.0);
    gluLookAt(CamX, CamY, CamZ,0.0,0.0,0.0, 0.0,1.0,0.0);

}

void display( void )
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

    PosicUser();


  	plano(800,5, 0.0);
	//ATUALIZA AS BALAS
	for(int i = 0; i < b.size(); i++)
	{
		b[i]->Percurso();
		b[i]->drawBala();
	}
	//ATUALIZA OS CUBOS
	/*for(int j = 0; j < inimigos.size(); j++)
	{
		//if(inimigos[j]->getVida()){
				//inimigos[j]->MoveInimigo();
				inimigos[j]->drawCubo();
		//}
	}*/

	nave->drawPlayer();
	glEnable( GL_TEXTURE_2D );

	for(int i = 0; i < c.size(); i++){
	    c[i]->drawCubo();
	}

	glDisable( GL_TEXTURE_2D );

	nave->drawPlayer();
	nave->defineLuz();

	glutSwapBuffers();
}

void keyboard ( unsigned char key, int x, int y ){
	switch (key){
        case 27:
            exit (0);
        break;
        case 'a':
			nave->moveEsq();
        break;
        case 'd':
			nave->moveDir();
        break;
		case ' ': //espaco
		    b.push_back(new Bala(objbala, nave->getX(), 10, -200, 2));
		break;
        default:

        break;
    }
}

void load(){

    objbala = new Object();
    objnave = new Object();

	objnave->readObject("./Accets/ship.obj");
    objbala->readObject("./Accets/bala.obj");

    texturas.push_back(loadTexture("./Accets/kepler.ppm", 200, 200));

    for(int i = -10; i < 10; i++){
        for(int j = 0; j < 10; j++)
            c.push_back( new Cubo(texturas[0], i*30,10,j*30,10) );
    }

    nave = new Player(objnave, 0, 15, -200, 4, 4, 4, 0, 0, 0.3, 1);
}


int main(int argc, char** argv){
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition (0,0);
	glutInitWindowSize(600, 500);
	glutCreateWindow("Leitura de OBJ");

  load();
	init();

	glutDisplayFunc ( display );
	glutReshapeFunc ( reshape );
	glutKeyboardFunc ( keyboard );
	glutTimerFunc(10, timer, 0);
	glutIdleFunc ( display );

	glutMainLoop ( );
	return 0;

}

void plano(int tam, int passo, float y){

    glPushMatrix();
	    glTranslatef ( -tam/2, y, -tam/2 );
        for(int i=0;i<tam;i += passo) {
            for(int j = 0; j < tam; j+=passo){
                glBegin(GL_POLYGON);
                glColor3f(1.0f,1.0f,1.0f);
                glNormal3f(0.0,1.0,0.0);
                glVertex3f(i        , 0.0  , j);
                glVertex3f(i        , 0.0  , j+passo);
                glVertex3f(i+passo  , 0.0  , j+passo);
                glVertex3f(i+passo  , 0.0  , j);
                glEnd();
            }
        }
    glPopMatrix();
}
/*void cubo() {

    glBindTexture( GL_TEXTURE_2D, texture[0]);
    glBegin (GL_QUADS);
          glTexCoord2f(0.0, 0.0); glVertex3f(-5, -5, -5.0);
          glTexCoord2f(0.0, 1.0); glVertex3f(-5, 5, -5.0);
          glTexCoord2f(1.0, 1.0); glVertex3f(5, 5, -5.0);
          glTexCoord2f(1.0, 0.0); glVertex3f(5, -5, -5.0);
    glEnd();

     glBindTexture( GL_TEXTURE_2D, texture[0]);
    glBegin (GL_QUADS);
        glTexCoord2f(0.0, 0.0); glVertex3f(-5.0,-5.0, 5.0);
          glTexCoord2f(0.0, 1.0); glVertex3f(5, -5, 5.0);
          glTexCoord2f(1.0, 1.0); glVertex3f(5, 5, 5.0);
          glTexCoord2f(1.0, 0.0); glVertex3f(-5, 5, 5.0);
    glEnd();


     glBindTexture( GL_TEXTURE_2D, texture[0]);
     glBegin (GL_QUADS);
          glTexCoord2f(0.0, 0.0); glVertex3f(5.0,-5.0, -5.0);
          glTexCoord2f(0.0, 1.0); glVertex3f(5.0, 5.0, -5.0);
          glTexCoord2f(1.0, 1.0); glVertex3f(5.0, 5.0, 5.0);
          glTexCoord2f(1.0, 0.0); glVertex3f(5.0,-5.0, 5.0);
    glEnd();

     glBindTexture( GL_TEXTURE_2D, texture[0]);
     glBegin (GL_QUADS);
         glTexCoord2f(0.0, 0.0); glVertex3f(-5.0,-5.0, -5.0);
          glTexCoord2f(0.0, 1.0); glVertex3f(-5.0, -5, 5.0);
          glTexCoord2f(1.0, 1.0); glVertex3f(-5.0, 5.0, 5.0);
          glTexCoord2f(1.0, 0.0); glVertex3f(-5.0, 5.0, -5.0);

    glEnd();

     glBindTexture( GL_TEXTURE_2D, texture[0]);
     glBegin (GL_QUADS);
          glTexCoord2f(0.0, 0.0); glVertex3f(-5.0, -5.0, -5.0);
          glTexCoord2f(0.0, 1.0); glVertex3f(5.0, -5.0, -5.0);
          glTexCoord2f(1.0, 1.0); glVertex3f(5.0, -5.0, 5.0);
          glTexCoord2f(1.0, 0.0); glVertex3f(-5.0, -5.0, 5.0);
    glEnd();

     glBindTexture( GL_TEXTURE_2D, texture[0]);
     glBegin (GL_QUADS);
          glTexCoord2f(0.0, 0.0); glVertex3f(-5.0, 5.0, -5.0);
          glTexCoord2f(0.0, 1.0); glVertex3f(-5.0, 5.0, 5.0);
          glTexCoord2f(1.0, 1.0); glVertex3f(5.0, 5.0, 5.0);
          glTexCoord2f(1.0, 0.0); glVertex3f(5.0,5.0, -5.0);
    glEnd();

}*/

GLuint loadTexture(const char* nome, int width, int height){
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

    for (int i=0;i<(width*height*3);i+=3){

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
