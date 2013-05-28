#include "GarrafaAgua.h"
#include <GL/glut.h>

#define DIV 20

GarrafaAgua::GarrafaAgua(float alt)
{
	raio=alt*0.15;
	altura=alt;
	e=new Esfera(raio,DIV,DIV);
	c1=new Cilindro(raio,altura*0.6,DIV,DIV,DIV);
	c2=new Cilindro(raio*0.4,altura*0.1,DIV,DIV,DIV);
}


GarrafaAgua::~GarrafaAgua(void)
{
}

void GarrafaAgua:: desenhar(){
	glPushMatrix();
	glTranslatef(0,altura*0.3,0);
	c1->desenhar();
	glTranslatef(0,altura*0.3,0);
	e->desenhar();
	glTranslatef(0,raio,0);
	c2->desenhar();
	glPopMatrix();


}
