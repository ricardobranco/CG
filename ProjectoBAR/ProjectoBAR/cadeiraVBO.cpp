#define _USE_MATH_DEFINES
#include <math.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include "primitivas.h"
#include "Cone.h"
#include "Cilindro.h"
#include "cadeiraVBO.h"
#include "Esfera.h"

#define CAM 50
#define LAD 50
#define DR 50


Cadeira:: Cadeira(float sizes){
	size=sizes;

}

void Cadeira::banco_alto_parametros(float altura, float raio){

	
	Cone* cc;
	Cilindro* c1,*c2;



	//Parte do centro
	glPushMatrix();
	glRotatef(180,1,0,0);
	glTranslatef(0,-altura,0);
	
	cc=new Cone(raio*0.22,altura,CAM,LAD,DR);
	cc->desenhar();

	glPopMatrix();
	
	
	glPushMatrix();
	glTranslatef(0,altura,0);
	
	c1=new Cilindro(raio,altura*1/8,CAM,LAD,DR);
	c1->desenhar();
	glPopMatrix();

	c2=new Cilindro(raio*0.4,altura*1/8,CAM,LAD,DR);
	c2->desenhar();
}

void Cadeira::bancoAlto(){

	float altura=0.6, raio=0.3;
	glPushMatrix();
	glScalef(size,size,size);
	banco_alto_parametros(altura,raio);
	glPopMatrix();
}

void Cadeira::banco_balcao_parametros(float altura,float raio){


	Cilindro *c1;
	Cilindro *c2;
	Cilindro *c3;

	
	//Parte do centro
	glPushMatrix();
	glTranslatef(0,altura/2,0);
	c1=new Cilindro(raio*1/7,altura,CAM,LAD,DR);
	c1->desenhar();
	glPopMatrix();


	//tampo
	glPushMatrix();
	glTranslatef(0,altura,0);
	c2=new Cilindro(raio,altura*1/8,CAM,LAD,DR);
	c2->desenhar();
	glPopMatrix();
	
	//chão
	c2=new Cilindro(raio*1/1.2,altura*1/20,CAM,LAD,DR);
	c2->desenhar();

}

void Cadeira::bancoBalcao()
{
	float altura=0.6, raio=0.3;

	glPushMatrix();
	glScalef(size,size,size);
	banco_balcao_parametros(altura,raio);
	glPopMatrix();

}


void Cadeira::banco_sofa_parametros(float altura,float raio){

	Cilindro *c1,*c2,*c3;
	Esfera*e;
	//centro
	glPushMatrix();
	glTranslatef(0,altura/2,0);
	c1=new Cilindro(raio*1/6,altura,CAM,LAD,DR);
	c1->desenhar();
	glPopMatrix();

	//acento
	glPushMatrix();
	glTranslatef(0,altura,0);
	glScalef(raio*1.2,raio/3,raio*1.2);
	e= new Esfera (raio,CAM,LAD);
	e->desenhar();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0,altura/1.3,0);
	glScalef(raio*1.2,raio/2,raio*1.2);
	c2=new Cilindro(raio,raio,CAM,LAD,DR);
	c2->desenhar();
	glPopMatrix();

	
	
	//base
	c3=new Cilindro(raio*0.3,altura*1/20,CAM,LAD,DR);
	c3->desenhar();
}

void Cadeira::bancoSofa(){

	float altura=0.1, raio=0.3;

	glPushMatrix();
	glScalef(size,size,size);
	banco_sofa_parametros(altura,raio);
	glPopMatrix();
}

void Cadeira::setSize(float sizes){
	size=sizes;
}