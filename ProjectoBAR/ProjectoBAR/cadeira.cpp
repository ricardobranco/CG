#define _USE_MATH_DEFINES
#include <math.h>
#include <glew.h>
#include <GL/glut.h>
#include "primitivas.h"



void banco_alto_parametros(float altura, float raio){

	int	camadas=60,lad=60;


	//Parte do centro
	glPushMatrix();
	glRotatef(180,1,0,0);
	glTranslatef(0,-altura,0);
	cone_solid(altura,raio*0.22,camadas,lad);
	glPopMatrix();
	

	glPushMatrix();
	glTranslatef(0,altura,0);
	cilindro_solid(altura*1/8,raio,camadas,lad);
	glPopMatrix();

	
	cilindro_solid(altura*1/8,raio*0.4,camadas,lad);

}




void banco_alto(float size){

	float altura=0.6, raio=0.3;
	glPushMatrix();
	glScalef(size,size,size);
	banco_alto_parametros(altura,raio);
	glPopMatrix();
}



void banco_balcao_parametros(float altura,float raio){

	int camadas=60,lad=60;
	//Parte do centro
	glPushMatrix();
	glTranslatef(0,altura/2,0);
	cilindro_solid(altura,raio*1/7,camadas,lad);
	glPopMatrix();


	//tampo
	glPushMatrix();
	glTranslatef(0,altura,0);
	cilindro_solid(altura*1/8,raio,camadas,lad);
	glPopMatrix();
	
	//chão

   cilindro_solid(altura*1/20,raio*1/1.2,camadas,lad);
}


void banco_balcao(float size){
	float altura=0.6, raio=0.3;

	glPushMatrix();
	glScalef(size,size,size);
	banco_balcao_parametros(altura,raio);
	glPopMatrix();

}



void banco_sofa_parametros(float altura,float raio){

	int camadas=60,dim=60;
	//centro
	glPushMatrix();
	glTranslatef(0,altura/2,0);
	cilindro_solid(altura,raio*1/6,camadas,dim);
	glPopMatrix();

	//acento
	glPushMatrix();
	glTranslatef(0,altura,0);
	glScalef(raio*1.2,raio/3,raio*1.2);
	esfera_solid(raio,camadas,dim);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0,altura/1.3,0);
	glScalef(raio*1.2,raio/2,raio*1.2);
	cilindro_solid(raio,raio,camadas,dim);
	glPopMatrix();

	
	




	//base
	cilindro_solid(altura*1/20,raio*0.3,camadas,dim);





}


void banco_sofa(float size){

	float altura=0.1, raio=0.3;

	glPushMatrix();
	glScalef(size,size,size);
	banco_sofa_parametros(altura,raio);
	glPopMatrix();
}