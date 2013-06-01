#include "BancoBalcao.h"
#include <GL/glut.h>

#define CAM 20
#define LAD 20
#define DR 20

BancoBalcao::BancoBalcao(float size)
{
	raio= 0.2*size;
	altura=0.6*size;
	c1=new Cilindro(raio/7,altura,CAM,LAD,DR);
	c2=new Cilindro(raio,altura/8,CAM,LAD,DR);
	c3=new Cilindro(raio/1.2,altura/20,CAM,LAD,DR);
	
}


BancoBalcao::~BancoBalcao(void)
{
}

void BancoBalcao::desenhar(int texture){
	
	static float ambient[]={0.19225,0.19225,0.19225,1};
	static float difuse[]={0.50754, 0.50754, 0.50754,1};
	static float specular[]={0.508273,0.508273,0.508273,1};
	static float shinenes=0.4;

	glMaterialfv(GL_FRONT,GL_AMBIENT,ambient);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,difuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR,specular);
	glMaterialf(GL_FRONT,GL_SHININESS,shinenes);

	glPushMatrix();
	glTranslatef(0,altura/40,0);

	glPushMatrix();
	glTranslatef(0,altura/2,0);
	c1->desenhar();
	glPopMatrix();
	//chão
	c3->desenhar();
	glBindTexture(GL_TEXTURE_2D,texture);
	//tampo
	glPushMatrix();
	glTranslatef(0,altura,0);
	c2->desenhar();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D,0);
	
	
	glPopMatrix();
}

