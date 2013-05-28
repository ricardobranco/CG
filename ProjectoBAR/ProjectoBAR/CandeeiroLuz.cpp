#include "CandeeiroLuz.h"
#include <GL/glut.h>

#define DIV 80

CandeeiroLuz::CandeeiroLuz(float tam)
{
	raio=0.5*tam;
	raioEsf=0.35*tam;
	altura=tam;
	c1=new Cilindro(raio,altura*0.5,DIV,DIV,DIV);
	c1=new Cilindro(raio*0.25,altura*0.5,DIV,DIV,DIV);
	cone=new Cone(raio,altura*0.45,DIV,DIV,DIV);
	lamp=new Esfera(raioEsf,DIV,DIV);
}


CandeeiroLuz::~CandeeiroLuz(void)
{
}

void CandeeiroLuz:: desenhar(){
	glPushMatrix();
	glTranslatef(0,raioEsf*0.5,0);
	glPushMatrix();
	lamp->desenhar();
	glTranslatef(0.0f,raioEsf*0.5,0.0f);
	c1->desenhar();
	glTranslatef(0.0f,0.25*altura,0.0f);
	cone->desenhar();
	glTranslatef(0.0f,0.4*altura,0.0f);
	c2->desenhar();
	glPopMatrix();
	glPopMatrix();

}
