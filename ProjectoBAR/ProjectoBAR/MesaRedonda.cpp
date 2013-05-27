#include "MesaRedonda.h"
#include <GL\glut.h>

#define NCAMADAS 60
#define NLAD 60

MesaRedonda::MesaRedonda(float alt)
{
	altura=alt;
	float expMesa=altura/13;
	float altCone=altura*0.2, altCilin=altura-altCone;
	con = new Cone(altCone*1.5,altCone,NCAMADAS,NLAD,NCAMADAS);
	cilAlt = new Cilindro(altCone*1.5/2,altCilin,NCAMADAS,NLAD,NCAMADAS);
	cilTampo = new Cilindro(altCone*2.5,expMesa,NCAMADAS,NLAD,NCAMADAS);

}


MesaRedonda::~MesaRedonda(void)
{
}

void MesaRedonda::desenhar() {
	float altCone=altura*0.2;
	float altCilin=altura-altCone;
	float expMesa=altura/13;

//figuras
	glPushMatrix();

	con->desenhar();

	glPopMatrix();
	glPushMatrix();

	glTranslatef(0,(altCone*0.5)+(altCilin/2),0);
	cilAlt->desenhar();

	glPopMatrix();
	glPushMatrix();
	
	glTranslatef(0,(altCone*0.5)+(altCilin)+(expMesa/2),0);
	
	cilTampo->desenhar();
	
	glPopMatrix();
	
}