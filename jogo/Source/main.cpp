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
int ppos = 0;

GLuint texture[3];

//Object* objeto = new Object;
Player *nave;
Bala *balas;
Bala *bala;

//
vector <Bala*> b;

//


void cubo ();
void plano (int tam, int passo, float y);
void normalize(float* init);
GLuint loadTexture(char* nome, int width, int height);


void init(void){

	  glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Fundo de tela preto
	  glShadeModel(GL_SMOOTH);
	  //glShadeModel(GL_FLAT);
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
    if (theta >= 360) theta=0.0;
    glutPostRedisplay();
    glutTimerFunc(10, timer, 0);
}

/*
void DefineLuz(){

    glEnable(GL_COLOR_MATERIAL);//Habilita o uso de cores
    glEnable(GL_LIGHTING);// Habilita o uso de iluminação

    GLfloat intAmbiente[] = {0.15, 0.15, 0.15}; //intensidade do componente ambiente da luz
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, intAmbiente);// Habilita a luz ambiente

    //definição dos parametros da luz 0
    GLfloat posLuz[] = {0, 15, 20, 1}; //posicao da luz(w=(1 = luz na posição exata, 0= luz vinda do infinito))
    GLfloat corLuz[] = {50.0, 50.0, 50.0}; //cor e intensidade da luz
    GLfloat dirLuz[] = {0.0, 0.0, 0.0}; //direcao da luz
    GLfloat angulo = 180.0;// angulo de abertura(]0º,90º[ ou 180º)
    GLfloat foco = 120; //grau de concentração(]0,120[)

    posLuz[0]=0;
    posLuz[1]=220.0;
    posLuz[2]=-200;

    dirLuz[0] = 0 - posLuz[0];
    dirLuz[1] = -1;
    dirLuz[2] = 0 - posLuz[2];

    //normalize(dirLuz);

    //Inicia com os parametros setados
    glLightfv(GL_LIGHT0, GL_DIFFUSE, corLuz); // Define a in    tensidade do componenete difuso da luz
    glLightfv(GL_LIGHT0, GL_SPECULAR, corLuz); // Define a intensidade do componenete especular da luz
    glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, angulo); // Define o angulo de abertura da luz
    glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, foco); //Define a concentração da luz na area do cutoff

    glLightfv(GL_LIGHT0, GL_POSITION, posLuz); // Define a posição da luz no ambiente
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, dirLuz); // Define a direção da luz com base na posição

    //atenuação da luz
    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 80);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.0);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.0);

    //inicializacao
    glEnable(GL_LIGHT0);

    //definição dos parametros da luz 0
    GLfloat posLuz1[] = {0, 15, 20, 1}; //posicao da luz(w=(1 = luz na posição exata, 0= luz vinda do infinito))
    GLfloat corLuz1[] = {1.0, 1.0, 1.0}; //cor e intensidade da luz
    GLfloat dirLuz1[] = {0.0, 0.0, 0.0}; //direcao da luz
    GLfloat angulo1 = 45.0;// angulo de abertura(]0º,90º[ ou 180º)
    GLfloat foco1 = 20; //grau de concentração(]0,120[)

    posLuz1[0]=ppos;
    posLuz1[1]=22;
    posLuz1[2]=-230;

    dirLuz1[0] = 0;
    dirLuz1[1] = 0;
    dirLuz1[2] = 1;

    //normalize(dirLuz);

    //Inicia com os parametros setados
    glLightfv(GL_LIGHT1, GL_DIFFUSE, corLuz1); // Define a in    tensidade do componenete difuso da luz
    glLightfv(GL_LIGHT1, GL_SPECULAR, corLuz1); // Define a intensidade do componenete especular da luzdd
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, angulo1); // Define o angulo de abertura da luz
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, foco1); //Define a concentração da luz na area do cutoff

    glLightfv(GL_LIGHT1, GL_POSITION, posLuz1); // Define a posição da luz no ambiente
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, dirLuz1); // Define a direção da luz com base na posição

    //atenuação da luz
    glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 0.2);
    glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.003);
    glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.0);

    //inicializacao
    glEnable(GL_LIGHT1);

    glPushMatrix();
        glColor4f(0.5f,0.0f,0.0f, 1.0f);
        glTranslatef(posLuz[0],posLuz[1],posLuz[2]);
        glutSolidSphere(1, 10, 10);
    glPopMatrix();
    //cubo(posLuz[0],posLuz[1],posLuz[2], 0.5);


}
*/
void PosicUser(){
	// Set the clipping volume

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
    
	nave->defineLuz();
	
  	plano(800,5, 0.0);
	for(int i = 0; i < b.size(); i++)
	{
		b[i]->Percurso();
		b[i]->drawBala();
	}
   
	nave->drawPlayer();
	
	glPushMatrix();
        glEnable( GL_TEXTURE_2D );
        glTranslatef(0,15,100);
        glRotatef(180,0,0,1);
        glScalef(3,3,3);
	    cubo();
	    glDisable( GL_TEXTURE_2D );
	glPopMatrix();

		glutSwapBuffers();
}

void keyboard ( unsigned char key, int x, int y ){
	switch (key){
        case 27:
            exit (0);
        break;
        case 'a':
            //ppos+=2;
						nave->moveEsq();
        break;
        case 'd':
            //ppos-=2;
						nave->moveDir();
        break;
				case ' ': //espaco
						bala = new Bala("./Accets/bala.obj", nave->getX(), 10, -200, 2);
						b.push_back(bala);
				break;
        default:

        break;
    }
}


int main(int argc, char** argv){
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable( GL_BLEND );

	glutInitWindowPosition (0,0);
	glutInitWindowSize(600, 500);
	glutCreateWindow("Leitura de OBJ");

    //objeto->readObject("./Accets/ship.obj");


	//guilherme->FAZENDO()______________________________

	nave = new Player("./Accets/ship.obj", 0, 15, -200, 4, 4, 4, 0, 0, 0.3, 1);
		//__________________________________________________
    texture[0] = loadTexture("./Accets/kepler.ppm", 200, 200);
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
void cubo () {

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

}

GLuint loadTexture(char* nome, int width, int height){
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

    glGenTextures(1, &texture[0]); // gera a textura vazia
    glBindTexture(GL_TEXTURE_2D, texture[0]); //define a textura como a atual

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);// ativa repretição horizontal
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);// ativa a repetição vertical

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);// Ativam a interpolação
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);               //

    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);//mapeia o arquivo para a textura


    delete []data;
    return texture[0];
}


void normalize(float* init){
    float mod = sqrt(init[0]*init[0] + init[1]*init[1] + init[2]*init[2]);
    init[0] = init[0]/mod;
    init[1] = init[1]/mod;
    init[2] = init[2]/mod;
}
