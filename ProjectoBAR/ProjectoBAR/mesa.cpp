#define _USE_MATH_DEFINES
#include <math.h>
#include <glew.h>
#include <GL/glut.h>
#include "primitivas.h"

//A funçao apenas depende da variavel altura

void desenha_mesa() {
	float altura=2;
//Extras
	float expMesa=altura/13;
	float altCone=altura*0.2, altCilin=altura-altCone;

	glPushMatrix();

	cone_solid(altCone,altCone*1.5,50,10);

	glPopMatrix();
	glPushMatrix();

	glTranslatef(0,(altCone*0.5)+(altCilin/2),0);
	
	cilindro_solid(altCilin,altCone*1.5/2,50,50);

	glPopMatrix();
	glPushMatrix();
	
	glTranslatef(0,(altCone*0.5)+(altCilin)+(expMesa/2),0);

	cilindro_solid(expMesa,altCone*2.5,50,3);
	
	glPopMatrix();
	
}

//a funçao depende das variaveis mesa(tamanho da mesa(quadrada)) e altura
void desenha_mesa1(){
	float mesa=3;
	float altura=1;
//Extra
	float meiaMesa=mesa/2,posicaoPerna=meiaMesa-(meiaMesa*0.4);
	int nCubosPerna=5;
	int nCubosMesa=5;
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