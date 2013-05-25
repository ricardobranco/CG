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
	float raio=52.5/1000*size;
	e=new Esfera(raio,80,80);
}


void Extras::bilharPar(float comp, float alt, float larg){
	float margemC,margemL,raio,altP;
	margemC=comp*0.15;
	margemL=larg*0.15;
	raio=comp*0.1;
	altP=alt*0.7;
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
	//pano

	glTranslatef(0,alt*0.35+alt*0.1,0);
	paraleli(comp,alt*0.2,larg);
	glTranslatef(0,alt*0.1+alt*0.05,0);
	glPushMatrix();
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
	// bolas
	glPushMatrix();
	glTranslatef(comp*0.3,0,larg*0.13);
	boB();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-comp*0.3,0,larg*0.36);
	boB();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(comp*0.3,0,larg*0.2);
	boB();
	glPopMatrix();
	glPopMatrix();

}

void Extras::bilhar(){
	glPushMatrix();
	glScalef(size*3.1,size,size*1.7);
	bilharPar(1,1,1);
	glPopMatrix();
}


void Extras::setSize(float sizes){
	size=sizes;
}