#define _USE_MATH_DEFINES
#include <math.h>
#include <glew.h>
#include <GL/glut.h>
#include "primitivas.h"


//A funçao apenas depende da variavel altura

void mesa(float alt) {
	float altura=alt;
//Extras
	float expMesa=altura/13;
	float altCone=altura*0.2, altCilin=altura-altCone;

	glPushMatrix();

	cone_solid(altCone,altCone*1.5,50,50);

	glPopMatrix();
	glPushMatrix();

	glTranslatef(0,(altCone*0.5)+(altCilin/2),0);
	
	cilindro_solid(altCilin,altCone*1.5/2,60,60);

	glPopMatrix();
	glPushMatrix();
	
	glTranslatef(0,(altCone*0.5)+(altCilin)+(expMesa/2),0);

	cilindro_solid(expMesa,altCone*2.5,60,10);
	
	glPopMatrix();
	
}

//a funçao depende das variaveis mesa(tamanho da mesa(quadrada)) e altura
void mesa1(float ms,float alt){
	float mesa=ms;
	float altura=alt;
//Extra
	float meiaMesa=mesa/2,posicaoPerna=meiaMesa-(meiaMesa*0.4);
	int nCubosPerna=30;
	int nCubosMesa=50;
//Escalas
	float escLargPerna=0.2,escAltPerna=2;


	glPushMatrix();
//Perna	
	glTranslatef(posicaoPerna,altura,posicaoPerna);
	glScalef(escLargPerna,escAltPerna,escLargPerna);

	cubo_solid(altura,nCubosPerna);

	glPopMatrix();
//Perna
	glPushMatrix();
	
	glTranslatef(-(posicaoPerna),altura,posicaoPerna);
	glScalef(escLargPerna,escAltPerna,escLargPerna);

	cubo_solid(altura,nCubosPerna);

	glPopMatrix();
//Perna
	glPushMatrix();
	
	glTranslatef(posicaoPerna,altura,-(posicaoPerna));
	glScalef(escLargPerna,escAltPerna,escLargPerna);

	cubo_solid(altura,nCubosPerna);

	glPopMatrix();
//Perna
	glPushMatrix();
	
	glTranslatef(-(posicaoPerna),altura,-(posicaoPerna));
	glScalef(escLargPerna,escAltPerna,escLargPerna);

	cubo_solid(altura,nCubosPerna);

	glPopMatrix();
//Mesa
	glPushMatrix();
	glTranslatef(0,altura*escAltPerna,0);
	glScalef(1,0.05,1);
	glTranslatef(0,meiaMesa,0);
	cubo_solid(mesa,nCubosMesa);

	glPopMatrix();
}

void desenha_mesa(float size){
	glPushMatrix();
	glScalef(size,size,size); 
	mesa(2);
	glPopMatrix();
}

void desenha_mesa1(float size){
	glPushMatrix();
	glScalef(size,size,size); 
	mesa1(2.5,1);
	glPopMatrix();
}