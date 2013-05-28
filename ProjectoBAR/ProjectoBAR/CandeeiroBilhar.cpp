#include "CandeeiroBilhar.h"
#include <GL/glut.h>

#define DIV 80

CandeeiroBilhar::CandeeiroBilhar(float comp, float tam)
{
	comprimento=comp;
	raio=0.65*tam;
	altura=0.9*tam;
	raioCil=0.05*tam;
	lamp=new Esfera(raio*0.25,DIV,DIV);
	cone=new Cone(raio,altura,DIV,DIV,DIV);
	cil=new Cilindro(raioCil,comprimento,DIV,DIV,DIV);
	cil2=new Cilindro(raioCil*0.2,comprimento*0.25,DIV,DIV,DIV);
}


CandeeiroBilhar::~CandeeiroBilhar(void)
{
}

void CandeeiroBilhar:: desenhar(){
	float margem;
	margem=comprimento*0.1;
	glPushMatrix();
	glTranslatef(0,raio*0.25,0);
	glPushMatrix();
	float cor[]={1,1,0.5,1.0};
	float spec[]={0.0,0.0,0.0,1.0};
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,cor);
	glMaterialfv(GL_FRONT,GL_SPECULAR,spec);
	lamp->desenhar();
	float cor1[]={0.4,0.4,0.4,1.0};
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,cor1);
	glMaterialfv(GL_FRONT,GL_SPECULAR,spec);
	cone->desenhar();

	glPushMatrix();
	glTranslatef(0,altura*comprimento*0.5,0);
	float cor2[]={0,0,0,1.0};
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,cor2);
	glMaterialfv(GL_FRONT,GL_SPECULAR,spec);
	cil2->desenhar();
	glPopMatrix();

	glTranslatef(-comprimento*0.5+margem,0,0);
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,cor);
	glMaterialfv(GL_FRONT,GL_SPECULAR,spec);
	lamp->desenhar();
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,cor1);
	glMaterialfv(GL_FRONT,GL_SPECULAR,spec);
	cone->desenhar();


	glPushMatrix();
	glTranslatef(0,altura*comprimento*0.5,0);
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,cor2);
	glMaterialfv(GL_FRONT,GL_SPECULAR,spec);
	cil2->desenhar();
	glPopMatrix();

	glPopMatrix();
	glPushMatrix();
	glTranslatef(comprimento*0.5-margem,0,0);
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,cor);
	glMaterialfv(GL_FRONT,GL_SPECULAR,spec);
	lamp->desenhar();
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,cor1);
	glMaterialfv(GL_FRONT,GL_SPECULAR,spec);
	cone->desenhar();

	glPushMatrix();
	glTranslatef(0,altura*comprimento*0.5,0);
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,cor2);
	glMaterialfv(GL_FRONT,GL_SPECULAR,spec);
	cil2->desenhar();
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,altura,0);
	glPushMatrix();
	glRotatef(90,0,0,1);
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,cor2);
	glMaterialfv(GL_FRONT,GL_SPECULAR,spec);
	cil->desenhar();
	glPopMatrix();

	glPopMatrix();
}

