#include "BancoSofa.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <GL/glut.h>
#define CAM 50
#define LAD 50
#define DR 50

BancoSofa::BancoSofa(float size)
{ 
	altura=0.1*size, raio=0.3*size;
	c1=new Cilindro(raio*1/6,altura,CAM,LAD,DR);
	e= new Esfera (raio,CAM,LAD);
	c2=new Cilindro(raio,raio,CAM,LAD,DR);
	c3=new Cilindro(raio*0.3,altura*1/20,CAM,LAD,DR);
}


BancoSofa::~BancoSofa(void)
{
}


void BancoSofa::desenhar(){


	glPushMatrix();
	glTranslatef(0,altura/2,0);
	c1->desenhar();
	glPopMatrix();

	//acento
	glPushMatrix();

	glTranslatef(0,altura,0);
	glScalef(raio*1.2,raio/3,raio*1.2);
	e->desenhar();

	glPopMatrix();
	
	glPushMatrix();

	glTranslatef(0,altura/1.3,0);
	glScalef(raio*1.2,raio/2,raio*1.2);
	
	c2->desenhar();

	glPopMatrix();

	
	
	//base
	c3=new Cilindro(raio*0.3,altura*1/20,CAM,LAD,DR);
	c3->desenhar();
}
