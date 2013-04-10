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
	float margem=0.3*larg;
	glPushMatrix();
	Paralelipipedo(comp,alt,margem);
	glTranslatef(0.0f,-alt/4,larg/2);
	Paralelipipedo(comp,alt/2,0.7*larg);
	glPopMatrix();
}

void Candi1(float raiomax,float alt){
	cone_solid(alt,raiomax,20,20);
	esfera_solid(raiomax/2,20,20);
}