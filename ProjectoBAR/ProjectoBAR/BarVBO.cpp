#define _USE_MATH_DEFINES
#include <math.h>
#include <GL/glew.h>
#include <GL/glut.h>

#include "BarVBO.h"
#include "Plano.h"


#define CAMADAS 30

BarVBO:: BarVBO(float size,float altura,float comp,float larg){
	this->size=size;
	this->altura = altura;
	this->larg = larg;
	this->comp = comp;

	//CHAO
	
	
	if((0.3*comp) < (0.3*larg)){
		cateto=0.3*comp;
	}
	else{
		cateto=0.3*larg;
	}
	hipotnusa = sqrt(pow(cateto,2)*2);
	
	dir = larg-cateto;
	sul = comp-cateto*2;
	if (dir<cateto)
		dir=cateto;
	if(sul<0)
		sul=cateto;
	aux = (sul-cateto)*2;
	
	this->chaoDIR = new Plano(hipotnusa,hipotnusa,CAMADAS,CAMADAS);
	this->chaoTOP = new Plano(cateto*2,dir,CAMADAS,CAMADAS);
	this->chaoESQ = new Plano(cateto+sul,cateto,CAMADAS,CAMADAS);

	//PAREDES
	this->parDIAG = new Plano(altura,hipotnusa,CAMADAS,CAMADAS);
	this->parTOP = new Plano(altura,cateto*2,CAMADAS,CAMADAS);
	this->parDIR = new Plano(altura,dir,CAMADAS,CAMADAS);
	this->parESQTOP = new Plano(altura,sul,CAMADAS,CAMADAS);
	this->parSULDIR  = new Plano(altura,cateto,CAMADAS,CAMADAS);

	//TECTO

	this->tecDIR = this->chaoDIR;
	this->tecESQ = this->chaoESQ;
	this->tecTOP = this->chaoTOP;


}

void  BarVBO::setSize(float size){
	size=size;
}


void  BarVBO::desenhar(int chao_tex, int paredes_tex,int tecto_tex){
	static float cor[]={0.6,0.6,0.6,1.0};
	static float spec[]={0.0,0.0,0.0,1.0};
	glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,cor);
	glMaterialfv(GL_FRONT,GL_SPECULAR,spec);
	glPushMatrix();
	glScalef(size,size,size);
	//CHAO
	glBindTexture(GL_TEXTURE_2D,chao_tex);
	glPushMatrix();
	glTranslatef(comp/2-cateto,0.0f,larg/2-cateto);
		glRotatef(45,0,1,0);
		chaoDIR->desenhar();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(comp/2-cateto,0.0f,-(larg/2-dir/2));
		chaoTOP->desenhar();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-(comp/2-(cateto+sul)/2),0.0f,larg/2-cateto/2);
		chaoESQ->desenhar();
	glPopMatrix();

	//PAREDES
	glBindTexture(GL_TEXTURE_2D,paredes_tex);
	glPushMatrix(); //PAREDE DIAGONAL
		glTranslatef(comp/2-cateto,0.0f,larg/2-cateto);
		glRotatef(45,0,1,0);
		glRotatef(90,0,0,1);
		glRotatef(90,1,0,0);
		glTranslatef(altura/2,hipotnusa/2,0);
		glRotatef(180,1,0,0);
		parDIAG->desenhar();
		
	glPopMatrix();

	glPushMatrix();//PAREDE NORTE
	glTranslatef(comp/2-cateto,altura/2,-larg/2);
		glRotatef(90,0,0,1);
		glRotatef(90,1,0,0);
		parTOP->desenhar();
		glRotatef(180,1,0,0);
		//parTOP->desenhar
	glPopMatrix();
	
	glPushMatrix();//PAREDE DIR
	glTranslatef(comp/2,altura/2,-(larg/2-dir/2));
		glRotatef(90,0,0,1);
		parDIR->desenhar();
		glRotatef(180,1,0,0);
		//parDIR->desenhar();
	glPopMatrix();
	
	
	glPushMatrix();//PAREDE ESQ
	glTranslatef(-comp/2+sul,altura/2,-(larg/2-dir/2));
		glRotatef(90,0,0,1);
		//parDIR->desenhar();
		glRotatef(180,1,0,0);
		parDIR->desenhar();
	glPopMatrix();
	
	glPushMatrix(); //PAREDE SULNORTE
	 
	glTranslatef(-comp/2+aux,altura/2,larg/2-cateto);
		glRotatef(90,0,0,1);
		glRotatef(90,1,0,0);
		//glRotatef(180,1,0,0);
		parESQTOP->desenhar();
	glPopMatrix();
	
	glPushMatrix(); //PAREDE SULESQ
	 aux = (sul-cateto)*2;
	glTranslatef(-comp/2+aux,altura/2,larg/2);
		glRotatef(90,0,0,1);
		glRotatef(90,1,0,0);
		//parESQTOP->desenhar();
		glRotatef(180,1,0,0);
		parESQTOP->desenhar();
	glPopMatrix();
	

	glPushMatrix(); //PAREDE SULDIR
	glTranslatef(comp/2-cateto-cateto/2,altura/2,larg/2);
		glRotatef(90,0,0,1);
		glRotatef(90,1,0,0);
		glRotatef(180,1,0,0);
		parSULDIR->desenhar();
	glPopMatrix();

	glPushMatrix(); //PAREDE SULESQ
		glTranslatef(-comp/2,altura/2,larg/2-cateto/2);
		glRotatef(90,0,1,0);
		glRotatef(90,0,0,1);
		glRotatef(90,1,0,0);
		//glRotatef(180,1,0,0);
		parSULDIR->desenhar();
	glPopMatrix();

	//TECTO

	glBindTexture(GL_TEXTURE_2D,tecto_tex);

	glPushMatrix();

		glTranslatef(0,altura,0);
	
		glPushMatrix();
			glTranslatef(comp/2-cateto,0.0f,larg/2-cateto);
			glRotatef(180,1,0,0);
			glRotatef(45,0,1,0);
			tecDIR->desenhar();
			//plano(hipotnusa,hipotnusa,CAMADAS,CAMADAS);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(comp/2-cateto,0.0f,-(larg/2-dir/2));
			glRotatef(180,1,0,0);
			tecTOP->desenhar();
			//plano(cateto*2,dir,CAMADAS,CAMADAS);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-(comp/2-(cateto+sul)/2),0.0f,larg/2-cateto/2);
			glRotatef(180,0,0,1);
			tecESQ->desenhar();
			//plano(cateto+sul,cateto,CAMADAS,CAMADAS);
		glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D,0);

}
	

BarVBO* Bar(float size){
	BarVBO* bar = new BarVBO(size,2,10,15);
	return bar;
}


