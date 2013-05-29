#include "GarrafaAgua.h"
#include <GL/glut.h>
#include "Maths\COLOR.h"

#define DIV 20

GarrafaAgua::GarrafaAgua(float alt)
{
	raio=alt*0.15;
	altura=alt;
	e=new Esfera(raio,DIV*4,DIV*8);
	c1=new Cilindro(raio,altura*0.6,DIV,DIV,DIV);
	c2=new Cilindro(raio*0.4,altura*0.3,DIV,DIV,DIV);
}


GarrafaAgua::~GarrafaAgua(void)
{
}

void GarrafaAgua:: desenhar(){
	
	static float cor[]={0.1,0.3,0.1,1};
	glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,cor);
	glMaterialfv(GL_FRONT,GL_SPECULAR,white);
	glMateriali(GL_FRONT,GL_SHININESS,85);
	
	glPushMatrix();
	glTranslatef(0,altura*0.3,0);
	c1->desenhar();
	glTranslatef(0,altura*0.3,0);
	e->desenhar();
	glTranslatef(0,raio+altura*0.12,0);
	c2->desenhar();
	glPopMatrix();


}
