#include "CandeeiroLuz.h"
#include <GL/glut.h>
#include "Maths\COLOR.h"

#define DIV 20

CandeeiroLuz::CandeeiroLuz(float tam)
{
	raio=0.5*tam;
	raioEsf=0.35*tam;
	altura=tam;
	c1=new Cilindro(raio,altura*0.5,DIV,DIV,DIV);
	c2=new Cilindro(raio*0.25,altura,DIV,DIV,DIV);
	cone=new Cone(raio,altura*0.45,DIV,DIV,DIV);
	lamp=new Esfera(raioEsf,DIV,DIV);
}


CandeeiroLuz::~CandeeiroLuz(void)
{
}

void CandeeiroLuz:: desenhar(){
	static float corLamp[]={0.3,1,1,1};

	glPushMatrix();
	glTranslatef(0,raioEsf*0.5,0);
	glPushMatrix();
	glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,corLamp);
	glMaterialfv(GL_FRONT,GL_EMISSION,white);
	lamp->desenhar();
	glTranslatef(0.0f,raioEsf*0.5,0.0f);
	glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,red);
	glMaterialfv(GL_FRONT,GL_EMISSION,black);
	c1->desenhar();
	glTranslatef(0.0f,0.25*altura,0.0f);
	cone->desenhar();
	glTranslatef(0.0f,0.4*altura,0.0f);
	c2->desenhar();
	glPopMatrix();
	glPopMatrix();

}
