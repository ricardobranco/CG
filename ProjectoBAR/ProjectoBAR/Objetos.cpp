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


void Candi1(float tamanho){
	float raiocone=0.65*tamanho;
	float altcone=0.9*tamanho;
	cone_solid(altcone,raiocone,20,20);
	esfera_solid(raiocone/2,20,20);
}

void Candi2(float tamanho){
	float raiofio=0.005*tamanho;
	float alturafio=tamanho*2;
	float raio=0.4*tamanho;
	float comp=tamanho;
	float larg=0.65*tamanho;
	float alt=0.8*tamanho;
	glPushMatrix();
	glScalef(comp,alt,larg);
	esfera_wire(1,20,20);
	glPopMatrix();
	esfera_solid(raio,20,20);
	glPopMatrix();
	glTranslatef(0.0f,alt+alturafio/2,0.0f);
	cilindro_solid(alturafio,raiofio,20,20);
	glPopMatrix();
}


void Candi3(float tamanho){
	float altura=tamanho;
	float raioesf=0.35*tamanho;
	float raio= 0.5*tamanho;
	glPushMatrix();
	glRotatef(90,1,0,0);
	esfera_solid(raioesf,20,20);
	glTranslatef(0.0f,raioesf*0.5,0.0f);
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
	cilindro_solid(alt/10,0.65*raio,20,20);
	glTranslatef(0.0f,alt/20+alt/10,0.0f);
	cilindro_solid(0.4*alt,raio/6,20,20);
	glTranslatef(0.0f,alt/5,0.0f);
	ovo(raio/4,alt/10,raio/4);
	glTranslatef(0.0f,alt/5,0.0f);
	cilindro_solid(0.4*alt,raio/6,20,20);
	glTranslatef(0.0f,alt/5,0.0f);
	ovo(raio/4,alt/5,raio/4);
	glTranslatef(0.0f,alt/5,0.0f);
	cilindro_solid(alt/10,raio,20,20);
	glPopMatrix();

}