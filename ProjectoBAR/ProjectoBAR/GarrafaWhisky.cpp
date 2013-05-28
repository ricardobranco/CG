#include "GarrafaWhisky.h"
#include <GL/glut.h>
#include "Maths\COLOR.h"

#define DIV 20

GarrafaWhisky::GarrafaWhisky(float tam)
{
	comprimento=0.5*tam;
	altura=0.7*tam;
	largura=0.4*tam;
	tamanho=tam;
	c1=new Cilindro(0.1*tam,0.3*tam,DIV,DIV,DIV);
	cubo=new Cubo(1,DIV);
}


GarrafaWhisky::~GarrafaWhisky(void)
{
}

void GarrafaWhisky:: desenhar(){
	glPushMatrix();
	glTranslatef(0,altura*0.5,0);
	glPushMatrix();
	glScalef(comprimento,altura,largura);
	cubo->desenhar();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,altura*0.5+0.15*tamanho,0);
	c1->desenhar();
	glPopMatrix();
	glPopMatrix();
}
