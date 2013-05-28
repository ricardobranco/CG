#include "MesaQuadrada.h"
#include <GL\glut.h>

MesaQuadrada::MesaQuadrada(float ms, float alt)
{
	mesa=ms;
	altura=alt;
	int nCubosPerna=20;
	int nCubosMesa=20;
	//Figuras
	cPernas = new Cubo(altura,nCubosPerna); 
	cTampo = new Cubo(mesa,nCubosMesa);
}


MesaQuadrada::~MesaQuadrada(void)
{
}


void MesaQuadrada::desenhar(){
	
	float meiaMesa=mesa/2,posicaoPerna=meiaMesa-(meiaMesa*0.4);
	
//Escalas
	float escLargPerna=0.2,escAltPerna=2;

	
	static float cor[]={1,1,1,1};
	static float spec[]={0.0,0.0,0.0,1};
	glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,cor);
	glMaterialfv(GL_FRONT,GL_SPECULAR,spec);

	glPushMatrix();
//Perna	
	glTranslatef(posicaoPerna,altura,posicaoPerna);
	glScalef(escLargPerna,escAltPerna,escLargPerna);

	cPernas->desenhar();

	glPopMatrix();
//Perna
	glPushMatrix();
	
	glTranslatef(-(posicaoPerna),altura,posicaoPerna);
	glScalef(escLargPerna,escAltPerna,escLargPerna);

	cPernas->desenhar();

	glPopMatrix();
//Perna
	glPushMatrix();
	
	glTranslatef(posicaoPerna,altura,-(posicaoPerna));
	glScalef(escLargPerna,escAltPerna,escLargPerna);

	cPernas->desenhar();

	glPopMatrix();
//Perna
	glPushMatrix();
	
	glTranslatef(-(posicaoPerna),altura,-(posicaoPerna));
	glScalef(escLargPerna,escAltPerna,escLargPerna);

	cPernas->desenhar();

	glPopMatrix();
//Mesa
	glPushMatrix();
	glTranslatef(0,altura*escAltPerna,0);
	glScalef(1,0.05,1);
	glTranslatef(0,meiaMesa,0);
	
	cTampo->desenhar();

	glPopMatrix();
}

void MesaQuadrada::desenharTex(int texture){
	glBindTexture(GL_TEXTURE_2D,texture);
	this->desenhar();
	glBindTexture(GL_TEXTURE_2D,0);
}