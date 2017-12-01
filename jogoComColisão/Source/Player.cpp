#include "../Headers/Cubo.hpp"

#include "GL/glut.h"

using namespace std;

Player::Player() {}

Player::Player(char* nomeArquivo, float x, float y, float z, float escalaX, float escalaY, float escalaZ, float r, float g, float b, float alpha)
{
    this->readObject(nomeArquivo);
    this->setEscalaX(escalaX);
    this->setEscalaY(escalaY);
    this->setEscalaZ(escalaZ);
    this->setX(x);
    this->setY(y);
    this->setZ(z);
    this->setLargura(this->nave->getLargura());
    this->setAltura(this->nave->getAltura());
    this->setProfundidade(this->nave->getProfundidade());
    this->setVida(true);
    this->setColor(r, g, b, alpha);
    this->limite = 10;
    this->mortos = 0;
}

Player::Player(Object* objeto, float x, float y, float z, float escalaX, float escalaY, float escalaZ, float r, float g, float b, float alpha)
{
    this->setObject(objeto);
    this->setEscalaX(escalaX);
    this->setEscalaY(escalaY);
    this->setEscalaZ(escalaZ);
    this->setX(x);
    this->setY(y);
    this->setZ(z);
    this->setLargura(this->nave->getLargura());
    this->setAltura(this->nave->getAltura());
    this->setProfundidade(this->nave->getProfundidade());
    this->setVida(true);
    this->setColor(r, g, b, alpha);
    this->limite = 10;
    this->mortos = 0;
}


Player::~Player()
{
    delete(nave);
}

float Player::getX()
{
    return this->x;
}

float Player::getY()
{
    return this->y;
}

bool Player::getVida()
{
    return this->vida;
}

void Player::setVida(bool vida)
{
    this->vida = vida;
}

float Player::getZ()
{
    return this->z;
}

float Player::getLargura()
{
    return largura;
}

float Player::getAltura()
{
    return altura;
}

float Player::getProfundidade()
{
    return profundidade;
}

void Player::setX(float x)
{
    this->x = x;
}

void Player::setY(float y)
{
    this->y = y;
}

void Player::setZ(float z)
{
    this->z = z;
}

void Player::setLargura(float lar)
{
    this->largura = lar * this->getEscalaX();
}

void Player::setAltura(float alt)
{
    this->altura = alt * this->getEscalaY();
}

void Player::setProfundidade(float pro)
{
    this->profundidade = pro * this->getEscalaZ();
}

void Player::moveDir()
{
    this->x-=7;
}

void Player::moveEsq()
{
    this->x+=7;
}

bool Player::IntervaloX(float x)
{
    if((this->getX() <= x) && (this->getX() + this->getLargura() >= x))
    {
        return true;
    }
    return false;
}

bool Player::IntervaloY(float y)
{
    if((this->getY() <= y) && (this->getY() + this->getAltura() >= y))
    {
        //ESTA NO INTERVALO
        return true;
    }
    return false;
}

/*void Player::Colisao(Cubo *cubo){
  if(IntervaloX(cubo->getX()) && IntervaloY(cubo->getY())){
      if(IntervaloX(cubo->getX()+cubo->getLado()) && IntervaloY(cubo->getY() + cubo->getLado())){
            this->setVida(false);
      }
  }

}*/

void Player::drawPlayer()
{
    //
    glPushMatrix();
    glTranslatef(this->getX(), this->getY(),this->getZ());
    glScalef(this->getEscalaX(), this->getEscalaY(), this->getEscalaZ());
    glColor4f(this->getR(), this->getG(), this->getB(), this->getAlpha());
    this->nave->glObject();
    glPopMatrix();
}

float Player::getEscalaX()
{
    return this->escalaX;
}

float Player::getEscalaY()
{
    return this->escalaY;
}

float Player::getEscalaZ()
{
    return this->escalaZ;
}

float Player::setEscalaX(float escalaX)
{
    this->escalaX = escalaX;
}

float Player::setEscalaY(float escalaY)
{
    this->escalaY = escalaY;
}

float Player::setEscalaZ(float escalaZ)
{
    this->escalaZ = escalaZ;
}

void Player::setObject(Object* objeto)
{
    nave = objeto;
}

void Player::readObject(char* nomeArquivo)
{
    nave = new Object();
    this->nave->readObject(nomeArquivo);
}

void Player::setR(float r)
{
    this->r = r;
}

void Player::setG(float g)
{
    this->g = g;
}

void Player::setB(float b)
{
    this->b = b;
}

void Player::setAlpha(float alpha)
{
    this->alpha = alpha;
}

float Player::getR()
{
    return this->r;
}

float Player::getG()
{
    return this->g;
}

float Player::getB()
{
    return this->b;
}

float Player::getAlpha()
{
    return this->alpha;
}

void Player::setColor(float r, float g, float b, float alpha)
{
    this->setR(r);
    this->setG(g);
    this->setB(b);
    this->setAlpha(alpha);
}

void Player::defineLuz()
{

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

    posLuz1[0]= this->getX();
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

void Player::addMortos(){
    this->mortos++;
}

int Player::getMortos(){
    return this->mortos;
}

int Player::getLimite()
{
  return this->limite;
}

void Player::Tiro()
{
    this->limite -= 1;
}

void Player::Bonus(){
    setLimite(getLimite()+1);
}

void Player::setLimite(int l){
    this->limite = l;
}
