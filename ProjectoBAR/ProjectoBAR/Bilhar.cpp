#include "Bilhar.h"
#include <GL/glut.h>

#define DIV 80

Bilhar::Bilhar(float s)
{
	size=s;
	cone=new Cone(0.3*size,0.9*size,DIV,DIV,DIV);
	bola=new Esfera(size*0.0525,DIV,DIV);
	cubo=new Cubo(1,DIV);
}


Bilhar::~Bilhar(void)
{
}

void Bilhar::desenhar(){
	float comp,alt,larg,margem,tabelasEsp,raioEsf;
	comp=3.1*size;
	alt=size;
	larg=1.7*size;
	margem=0.3*size;
	tabelasEsp=0.15*size;
	raioEsf=0.0525;
	//perna --
	float cor5[]={0.7,0.5,0.25,1.0};
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,cor5);
	glPushMatrix();
	glTranslatef(-comp*0.5+margem,0,-larg*0.5+margem);
	glPushMatrix();
	glTranslatef(0,alt*0.7,0);
	glPushMatrix();
	glRotatef(180,0,0,1);
	cone->desenhar();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	//perna -+
	glPushMatrix();
	glTranslatef(-comp*0.5+margem,0,larg*0.5-margem);
	glPushMatrix();
	glTranslatef(0,alt*0.7,0);
	glPushMatrix();
	glRotatef(180,0,0,1);
	cone->desenhar();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	//perna +-
	glPushMatrix();
	glTranslatef(comp*0.5-margem,0,-larg*0.5+margem);
	glPushMatrix();
	glTranslatef(0,alt*0.7,0);
	glPushMatrix();
	glRotatef(180,0,0,1);
	cone->desenhar();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	//perna ++
	glPushMatrix();
	glTranslatef(comp*0.5-margem,0,larg*0.5-margem);
	glPushMatrix();
	glTranslatef(0,alt*0.7,0);
	glPushMatrix();
	glRotatef(180,0,0,1);
	cone->desenhar();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	//Pano

	glPushMatrix();
	glTranslatef(0,alt*0.75,0);
	glPushMatrix();
	glScalef(comp,alt*0.3,larg);
	float cor4[]={0,1.0,0,1.0};
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,cor4);
	cubo->desenhar();
	glPopMatrix();
	glPopMatrix();
	//tabelas
	glPushMatrix();
	glTranslatef(-comp*0.5+tabelasEsp*0.5,alt*0.95,0);
	glPushMatrix();
	glScalef(tabelasEsp,alt*0.1,larg-2*tabelasEsp);
	cubo->desenhar();
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(comp*0.5-tabelasEsp*0.5,alt*0.95,0);
	glPushMatrix();
	glScalef(tabelasEsp,alt*0.1,larg-2*tabelasEsp);
	cubo->desenhar();
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,alt*0.95,-larg*0.5+tabelasEsp*0.5);
	glPushMatrix();
	glScalef(comp,alt*0.1,tabelasEsp);
	cubo->desenhar();
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,alt*0.95,larg*0.5-tabelasEsp*0.5);
	glPushMatrix();
	glScalef(comp,alt*0.1,tabelasEsp);
	cubo->desenhar();
	glPopMatrix();
	glPopMatrix();
	//bolas
	glPushMatrix();
	glTranslatef(0,alt*0.9+raioEsf,0);
	float cor3[]={1.0,0,0,1.0};
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,cor3);
	bola->desenhar();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(comp*0.4,alt*0.9+raioEsf,larg*0.3);
	float cor1[]={1.0,0,0,1.0};
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,cor1);
	bola->desenhar();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-comp*0.2,alt*0.9+raioEsf,-larg*0.3);
	float cor2[]={0,0,0,1.0};
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,cor2);
	bola->desenhar();
	glPopMatrix();
	float cor[]={1.0,1.0,1.0,1.0};
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,cor);





}
