#include "Sofa.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <GL/glut.h>

#define DIV 40

Sofa::Sofa(float size,int nlugares)
{
	
	this->comp=size;
	this->larg=size*nlugares;
	this->alt=size;
	c1=new Cilindro(alt*0.2,larg,DIV,DIV,DIV);
	c2=new Cilindro(alt*0.25,larg,DIV,DIV,DIV);
	cub1=new Cubo(1,DIV);
}


Sofa::~Sofa(void)
{
}
void Sofa::desenhar(){
	glPushMatrix();
	glTranslatef(0,alt/2,0);
	glPushMatrix();
	glScalef(comp,alt*0.4,larg);
	cub1->desenhar();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(comp*0.5,0,0);
	glRotatef(90,1,0,0);
	c1->desenhar();
	glPopMatrix();
	
	glTranslatef(-comp*0.5+comp*0.25,alt*0.2+alt*0.175,0);
	
	glPushMatrix();
	glScalef(comp*0.5,alt*0.35,larg);
	cub1->desenhar();
	glPopMatrix();
	
	glTranslatef(0,alt*0.175,0);
	glRotatef(90,1,0,0);
	c2->desenhar();
	glPopMatrix();
	
}

//
//void CadeiraVBO::sofa1Pessoa(){
//
//	glPushMatrix();
//	glScalef(size,size,size);
//	sofa_parametros(1,1,1);
//	glPopMatrix();
//}
//
//
//void CadeiraVBO::sofa2Pessoa(){
//
//	glPushMatrix();
//	glScalef(size,size,size*2);
//	sofa_parametros(1,1,1);
//	glPopMatrix();
//}
//
//
//
//void CadeiraVBO::setSize(float sizes){
//	size=sizes;
//}