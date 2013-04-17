#define _USE_MATH_DEFINES
#include <math.h>
#include <glew.h>
#include <GL/glut.h>
#include "primitivas.h"
#include "Objetos.h"

void Paralelipiped(float comp,float alt,float larg){
	glPushMatrix();
	glScalef(comp,alt,larg);
	cubo_solid(1,5);
	glPopMatrix();
}


void parede(float altura, float base, float espessura){

	glPushMatrix();
	Paralelipiped(base,altura,espessura);
	glPopMatrix();
}


void paredesparalelas(float altura, float base, float espessura,float distancia){
	glPushMatrix();
	glTranslatef(0.0f,0.0f,distancia/2+espessura/2);
	parede(altura,base,espessura);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0f,0.0f,-(distancia/2+espessura/2));
	parede(altura,base,espessura);
	glPopMatrix();
	
}

void paredeporta(float altura, float base, float espessura, float alturaporta, float baseporta){

	float basesporta = base-baseporta;
	float alturasporta = altura-alturaporta;
	if(basesporta<0)
		basesporta=0;
	if(alturasporta<0)
		alturasporta=0;

	glPushMatrix();
	glTranslatef(0.0f,altura/2-alturasporta/2,0.0f);
	glPushMatrix();
	parede(alturasporta,base,espessura);
	glTranslatef(-(baseporta/2+basesporta/4),-(alturaporta/2+alturasporta/2),0.0f);
	parede(alturaporta,basesporta/2,espessura);
	glPopMatrix();
	glPushMatrix();
	glTranslatef((baseporta/2+basesporta/4),-(alturaporta/2+alturasporta/2),0.0f);
	parede(alturaporta,basesporta/2,espessura);
	glPopMatrix();
	glPopMatrix();

}
