#include "BancoAlto.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <GL/glut.h>
#define CAM 50
#define LAD 50
#define DR 50

BancoAlto::BancoAlto(float size)
{
	this->altura=0.6*size;
	this->raio=0.3*size;

	this->cc=new Cone(raio*0.22,altura,CAM,LAD,DR);
	this->c1=new Cilindro(raio,altura*1/8,CAM,LAD,DR);
	this->c2=new Cilindro(raio*0.4,altura*1/8,CAM,LAD,DR);

}


BancoAlto::~BancoAlto(void)
{
}


void BancoAlto:: desenhar(){
	
	//Parte do centro
	glPushMatrix();
	glRotatef(180,1,0,0);
	glTranslatef(0,-altura,0);
	
	cc->desenhar();

	glPopMatrix();
	
	
	glPushMatrix();
	glTranslatef(0,altura,0);
	c1->desenhar();
	glPopMatrix();

	c2->desenhar();
}