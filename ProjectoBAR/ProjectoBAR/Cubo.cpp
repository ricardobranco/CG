#include "Cubo.h"

#include <stdlib.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include <math.h>


Cubo::Cubo(float lado, int div){
	p=new Plano(lado,lado,div,div);
	this->lado=lado;
}


Cubo::~Cubo(void)
{
}


void Cubo::desenhar(){
	
	glPushMatrix();
		glTranslatef(0,lado/2,0);
		p->desenhar();
		glTranslatef(0,-lado,0);
		glRotatef(180,1,0,0);
		p->desenhar();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(lado/2,0,0);
		glRotatef(-90,0,0,1);
		p->desenhar();
		glTranslatef(0,-lado,0);
		glRotatef(180,1,0,0);
		p->desenhar();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0,0,lado/2);
		glRotatef(90,1,0,0);
		p->desenhar();
		glTranslatef(0,-lado,0);
		glRotatef(180,1,0,0);
		p->desenhar();
	glPopMatrix();

}