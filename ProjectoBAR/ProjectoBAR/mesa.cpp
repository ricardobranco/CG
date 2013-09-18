#define _USE_MATH_DEFINES
#include <math.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include "mesa.h"

/*
//A funçao apenas depende da variavel altura

void mesa(float alt) {
	float altura=alt;
//Extras
	float expMesa=altura/13;
	float altCone=altura*0.2, altCilin=altura-altCone;
	int camadas=60,lad=60;

	glPushMatrix();

	cone_solid(altCone,altCone*1.5,camadas,lad);

	//glPopMatrix();
	//glPushMatrix();

	glTranslatef(0,(altCone*0.5)+(altCilin/2),0);
	
	cilindro_solid(altCilin,altCone*1.5/2,camadas,lad);

	//glPopMatrix();
	//glPushMatrix();
	
	glTranslatef(0,(altCone*0.5)+(altCilin)+(expMesa/2),0);

	cilindro_solid(expMesa,altCone*2.5,camadas,lad);
	
	glPopMatrix();
	
}

//a funçao depende das variaveis mesa(tamanho da mesa(quadrada)) e altura
void mesa1(float ms,float alt){
	float mesa=ms;
	float altura=alt;
//Extra
	float meiaMesa=mesa/2,posicaoPerna=meiaMesa-(meiaMesa*0.4);
	int nCubosPerna=100;
	int nCubosMesa=100;
//Escalas
	float escLargPerna=0.2,escAltPerna=2;


	glPushMatrix();
//Perna	
	glTranslatef(posicaoPerna,altura,posicaoPerna);
	glScalef(escLargPerna,escAltPerna,escLargPerna);

	cubo_solid(altura,nCubosPerna);

	glPopMatrix();
//Perna
	glPushMatrix();
	
	glTranslatef(-(posicaoPerna),altura,posicaoPerna);
	glScalef(escLargPerna,escAltPerna,escLargPerna);

	cubo_solid(altura,nCubosPerna);

	glPopMatrix();
//Perna
	glPushMatrix();
	
	glTranslatef(posicaoPerna,altura,-(posicaoPerna));
	glScalef(escLargPerna,escAltPerna,escLargPerna);

	cubo_solid(altura,nCubosPerna);

	glPopMatrix();
//Perna
	glPushMatrix();
	
	glTranslatef(-(posicaoPerna),altura,-(posicaoPerna));
	glScalef(escLargPerna,escAltPerna,escLargPerna);

	cubo_solid(altura,nCubosPerna);

	glPopMatrix();
//Mesa
	glPushMatrix();
	glTranslatef(0,altura*escAltPerna,0);
	glScalef(1,0.05,1);
	glTranslatef(0,meiaMesa,0);
	cubo_solid(mesa,nCubosMesa);

	glPopMatrix();
}

void desenha_mesa(float size){
	glPushMatrix();
	glScalef(size,size,size); 
	mesa(2);
	glPopMatrix();
}

void desenha_mesa1(float size){
	glPushMatrix();
	glScalef(size,size,size); 
	mesa1(2.5,1);
	glPopMatrix();
}

*/


//A funçao apenas depende da variavel altura

void mesa_redonda(float alt) {
	float altura=alt;
//Extras
	float expMesa=altura/13;
	float altCone=altura*0.2, altCilin=altura-altCone;
	int camadas=60,lad=60;
//figuras
	Cone *con = new Cone(altCone*1.5,altCone,camadas,lad,camadas);
	Cilindro *cilAlt = new Cilindro(altCone*1.5/2,altCilin,camadas,lad,camadas);
	Cilindro *cilTampo = new Cilindro(altCone*2.5,expMesa,camadas,lad,camadas);

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

//a funçao depende das variaveis mesa(tamanho da mesa(quadrada)) e altura
void mesa_quadrada(float ms,float alt){
	float mesa=ms;
	float altura=alt;
//Extra
	float meiaMesa=mesa/2,posicaoPerna=meiaMesa-(meiaMesa*0.4);
	int nCubosPerna=100;
	int nCubosMesa=100;
//Escalas
	float escLargPerna=0.2,escAltPerna=2;
//Figuras
	Cubo *cPernas = new Cubo(altura,nCubosPerna); 
	Cubo *cTampo = new Cubo(mesa,nCubosMesa); 
	
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

void balcao(){
	Cubo *c = new Cubo(1,50);

	glTranslatef(0,0.5,0);
	glScalef(2,1,0.5);
	c->desenhar();

}


void desenha_mesa_redonda(float size){
	glPushMatrix();
	glScalef(size,size,size); 
	mesa_redonda(2);
	glPopMatrix();
}

void desenha_mesa_quadrada(float size){
	glPushMatrix();
	glScalef(size,size,size); 
	mesa_quadrada(2.5,1);
	glPopMatrix();
}

void desenha_balcao(float size){
	glPushMatrix();
	glScalef(size,size,size); 
	balcao();
	glPopMatrix();
}

