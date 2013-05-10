#define _USE_MATH_DEFINES
#include <math.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include "Cone.h"
#include "Cilindro.h"
#include "CandeeirosVBO.h"
#include "Esfera.h"

#define CAM 50
#define LAD 50
#define DR 50


CandeeirosVBO:: CandeeirosVBO(float tamanhoN){
	tamanho=tamanhoN;

}


void CandeeirosVBO:: Candi1(){
	Cone* cc;
	Esfera* e;

	float raiocone=0.65*tamanho;
	float altcone=0.9*tamanho;
	cc=new Cone(raiocone,altcone,20,20,20);
	e=new Esfera(raiocone/2,20,20);
	e->desenhar();
}

void CandeeirosVBO:: Candi2(){
	float raiofio=0.005*tamanho;
	float alturafio=tamanho*2;
	float raio=0.4*tamanho;
	float comp=tamanho;
	float larg=0.65*tamanho;
	float alt=0.8*tamanho;

	Esfera* e;
	Cilindro* c;

	glPushMatrix();
	glScalef(comp,alt,larg);
	e=new Esfera(1,20,20);
	e->desenhar();

	glTranslatef(0.0f,alt+alturafio/2,0.0f);
	c=new Cilindro(alturafio,raiofio,20,20,20);
	c->desenhar();
	glPopMatrix();
}


void CandeeirosVBO:: Candi3(){
	float altura=tamanho;
	float raioesf=0.35*tamanho;
	float raio= 0.5*tamanho;

	Esfera* e;
	Cilindro *c1,*c2;
	Cone* cone;

	glPushMatrix();
	glRotatef(90,1,0,0);
	e=new Esfera(raioesf,20,20);
	e->desenhar();
	glTranslatef(0.0f,raioesf*0.5,0.0f);
	c1=new Cilindro(raio,0.5*altura,20,20,20);
	c1->desenhar();
	glTranslatef(0.0f,0.25*altura,0.0f);
	cone=new Cone(raio,0.45*altura,20,20,20);
	cone->desenhar();
	glTranslatef(0.0f,0.4*altura,0.0f);
	c2=new Cilindro(raio/4,0.1*altura,20,20,20);
	c2->desenhar();
	glPopMatrix();
}



void CandeeirosVBO:: Candi4(){
	float raio=0.2*tamanho;

	Cilindro *cil;
	Cone *c1,*c2;

	glPushMatrix();
	cil=new Cilindro(raio,tamanho,20,20,20);
	cil->desenhar();
	c1=new Cone(raio,tamanho/2,20,20,20);
	c1->desenhar();
	glRotatef(180,0,0,1);
	c2=new Cone(raio,tamanho/2,20,20,20);
	c2->desenhar();
	glPopMatrix();
}

void CandeeirosVBO::setSize(float sizes){
	tamanho=sizes;
}
