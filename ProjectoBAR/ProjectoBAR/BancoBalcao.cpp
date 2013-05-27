#include "BancoBalcao.h"
#include <GL/glut.h>

#define CAM 50
#define LAD 50
#define DR 50

BancoBalcao::BancoBalcao(float size)
{
	raio= 0.3*size;
	altura=0.6*size;
	c1=new Cilindro(raio*1/7,altura,CAM,LAD,DR);
	c2=new Cilindro(raio,altura*1/8,CAM,LAD,DR);
	c3=new Cilindro(raio*1/1.2,altura*1/20,CAM,LAD,DR);
	
}


BancoBalcao::~BancoBalcao(void)
{
}

void BancoBalcao::desenhar(){
	
	glPushMatrix();
	glTranslatef(0,(raio*1/1.2)/2,0);

	glPushMatrix();
	glTranslatef(0,altura/2,0);
	c1->desenhar();
	glPopMatrix();

	//tampo
	glPushMatrix();
	glTranslatef(0,altura,0);
	c2->desenhar();
	glPopMatrix();
	
	//chão
	c3->desenhar();
	glPopMatrix();
}

