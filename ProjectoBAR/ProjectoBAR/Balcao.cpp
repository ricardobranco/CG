#include "Balcao.h"
#include <GL/glut.h>

#define DIV 20

Balcao::Balcao(float comp,float alt,float larg)
{
	comprimento=comp;
	altura=alt;
	largura=larg;
	espLarg=largura*0.2;
	espComp=comprimento*0.1;
	cubo=new Cubo(1,DIV);
}


Balcao::~Balcao(void)
{
}

void Balcao::desenhar(int tampo_tex, int base_tex){
	glPushMatrix();
	glTranslatef(0,altura*0.5,0);

	glPushMatrix();
	glTranslatef(comprimento*0.5-espComp*0.5,0,0);
	glBindTexture(GL_TEXTURE_2D,base_tex);
	glPushMatrix();
	glScalef(espComp,altura,largura);
	cubo->desenhar();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(espComp*0.25,altura*0.5+altura*0.05*0.5,espLarg*0.25);
	
	glBindTexture(GL_TEXTURE_2D,tampo_tex);
	glPushMatrix();
	glScalef(espComp*1.5,altura*0.05,largura+espLarg*0.5);
	cubo->desenhar();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	
	
	glBindTexture(GL_TEXTURE_2D,base_tex);
	glPushMatrix();
	glTranslatef(-espComp*0.5,0,largura*0.5-espLarg*0.5);
	glPushMatrix();
	glScalef(comprimento-espComp,altura,espLarg);
	cubo->desenhar();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,altura*0.5+altura*0.05*0.5,espLarg*0.25);
	glBindTexture(GL_TEXTURE_2D,tampo_tex);
	glPushMatrix();
	glScalef(comprimento-espComp,altura*0.05,espLarg*1.5);
	cubo->desenhar();
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D,0);
}
