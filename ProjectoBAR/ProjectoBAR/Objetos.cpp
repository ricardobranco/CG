#define _USE_MATH_DEFINES
#include <math.h>
#include <glew.h>
#include <GL/glut.h>
#include "primitivas.h"

void Paralelipipedo(float comp,float alt,float larg){
	glPushMatrix();
	glScalef(comp,alt,larg);
	cubo_solid(1,5);
	glPopMatrix();
}

void sofa(float comp,float alt,float larg){
	float margem=0.4*larg;
	glPushMatrix();
	Paralelipipedo(comp,alt,margem);
	glTranslatef(0.0f,alt/2,0.0f);
	glRotatef(90,0.0f,0.0f,1.0f);
	cilindro_solid(comp,margem/2,20,20);
	glPopMatrix();
	glPopMatrix();
	glTranslatef(0.0f,-alt/4,larg/2);
	Paralelipipedo(comp,alt/2,0.6*larg);
	glTranslatef(0.0f,0,0.6*larg/2);
	glRotatef(90,0.0f,0.0f,1.0f);
	cilindro_solid(comp,alt/4,20,20);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}

void Candi1(float raiomax,float alt){
	cone_solid(alt,raiomax,20,20);
	esfera_solid(raiomax/2,20,20);
}

void Candi2(float comp,float alt,float larg,float raio,float alturafio,float raiofio){
	glPushMatrix();
	esfera_wire(1,20,20);
	glScalef(comp,alt,larg);
	esfera_solid(1,20,20);
	glPopMatrix();
	glTranslatef(0.0f,alt+alturafio/2,0.0f);
	cilindro_solid(alturafio,raiofio,20,20);
	glPopMatrix();
}

void Candi3(float raioesf,float raio,float altura){
	glPushMatrix();
	glRotatef(90,1,0,0);
	esfera_solid(raioesf,20,20);
	glTranslatef(0.0f,raioesf*1.3,0.0f);
	cilindro_solid(0.5*altura,raio,20,20);
	glTranslatef(0.0f,0.25*altura,0.0f);
	cone_solid(0.45*altura,raio,20,20);
	glTranslatef(0.0f,0.4*altura,0.0f);
	cilindro_solid(0.1*altura,raio/4,20,20);
	glPopMatrix();
}

void ovo(float comp,float alt,float larg){
	glPushMatrix();
	glScalef(comp,alt,larg);
	esfera_solid(1,20,20);
	glPopMatrix();
}

void Mesacafe(float raio, float alt){
	glPushMatrix();
	cilindro_solid(alt/10,raio/4,20,20);
	glTranslatef(0.0f,alt/20+alt/10,0.0f);
	cilindro_solid(alt/5,raio/6,20,20);
	glTranslatef(0.0f,alt/5+alt/10,0.0f);
	ovo(raio/5,alt/5,raio/5);
	glTranslatef(0.0f,alt/5+alt/10,0.0f);
	cilindro_solid(alt/5,raio/6,20,20);
	glTranslatef(0.0f,alt/5+alt/10,0.0f);
	ovo(raio/5,alt/5,raio/5);
	glTranslatef(0.0f,alt/5+alt/10,0.0f);
	cilindro_solid(alt/10,raio,20,20);
	glPopMatrix();
}