#define _USE_MATH_DEFINES
#include <math.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include "primitivas.h"
#include "Cone.h"
#include "Cilindro.h"
#include "Extras.h"
#include "Esfera.h"
#include "Cubo.h"
#define CAM 50
#define LAD 50
#define DR 50


Extras:: Extras(float sizes){
	size=sizes;
}

void paraleli(float comp,float alt,float larg){
	glPushMatrix();
	glScalef(comp,alt,larg);
	Cubo *c;
	c=new Cubo(1,80);
	c->desenhar();
	glPopMatrix();
}

void pernas(float raio, float altura){
	Cilindro *c;
	c=new Cilindro(raio,altura,80,80,80);
	c->desenhar();
}

void Extras::boB(){
	Esfera *e;
	glPushMatrix();
	float raio=0.0525*size;
	glScalef(1,1,1);
	e=new Esfera(raio,80,80);
	e->desenhar();
	glPopMatrix();
}

void Extras::dbolas(float comp, float alt, float larg){
	// bolas
	glPushMatrix();
	float cor1[]={0.0,0.0,0.0,1.0};
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,cor1);
	glTranslatef(comp*0.3,alt*0.6+0.0525*size,larg*0.13);
	boB();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-comp*0.3,alt*0.6+0.0525*size,larg*0.36);
	float cor2[]={1.0,0.0,0.0,1.0};
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,cor2);
	boB();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(comp*0.3,alt*0.6+0.0525*size,larg*0.34);
	boB();
	glPopMatrix();
	glPopMatrix();
	float cor3[]={1.0,1.0,1.0,1.0};
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,cor3);
}



void Extras::bilharPar(float comp, float alt, float larg){
	float margemC,margemL,raio,altP;
	margemC=comp*0.15;
	margemL=larg*0.15;
	raio=comp*0.1;
	altP=alt*0.7;
	int j=5;
	//pernas
	glPushMatrix();
	glTranslatef(comp*0.5-margemC,0,larg*0.5-margemL);
	pernas(raio,altP);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(comp*0.5-margemC,0,-larg*0.5+margemL);
	pernas(raio,altP);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-comp*0.5+margemC,0,larg*0.5-margemL);
	pernas(raio,altP);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-comp*0.5+margemC,0,-larg*0.5+margemL);
	pernas(raio,altP);
	glPopMatrix();
	glPushMatrix();
	float cor4[]={0.0,1.0,0.0,1.0};
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,cor4);
	//pano
	

	glTranslatef(0,alt*0.35+alt*0.1,0);
	paraleli(comp,alt*0.2,larg);
	glTranslatef(0,alt*0.1+alt*0.05,0);
	glPushMatrix();
	float cor5[]={0.0,1.0,1.0,1.0};
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,cor5);
	//tabelas 
	glTranslatef(comp*0.5-larg*0.05,0,0);
	paraleli(larg*0.1,alt*0.1,larg);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-comp*0.5+larg*0.05,0,0);
	paraleli(larg*0.1,alt*0.1,larg);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,0,larg*0.5-larg*0.05);
	paraleli(comp-larg*0.2,alt*0.1,larg*0.1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,0,-larg*0.5+larg*0.05);
	paraleli(comp-larg*0.2,alt*0.1,larg*0.1);
	glPopMatrix();
	
	float cor3[]={1.0,1.0,1.0,1.0};
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,cor3);
	glPopMatrix();
}

void Extras::bilhar(){
	glPushMatrix();
	glScalef(size*3.1,size,size*1.7);
	bilharPar(1,1,1);
	glPopMatrix();
	glScalef(size,size,size);
	dbolas(1,1,1);
}


void Extras::setSize(float sizes){
	size=sizes;
}