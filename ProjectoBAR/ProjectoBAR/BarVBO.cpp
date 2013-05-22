#define _USE_MATH_DEFINES
#include <math.h>
#include <GL/glew.h>
#include <GL/glut.h>

#include "BarVBO.h"
#include "Plano.h"
#include "Cubo.h"


#define CAMADAS 60

BarVBO:: BarVBO(float size){
	this->size=size;

}

void  BarVBO::setSize(float size){
	this->size=size;
}


void BarVBO::Chao_params(float comp, float larg){


	float cateto,hipotnusa;
	float dir,sul;
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
	Plano* p1 = new Plano(hipotnusa,hipotnusa,CAMADAS,CAMADAS);
	Plano* p2 = new Plano(cateto*2,dir,CAMADAS,CAMADAS);
	Plano* p3 = new Plano(cateto+sul,cateto,CAMADAS,CAMADAS);
				

	glPushMatrix();
		glTranslatef(comp/2-cateto,0.0f,larg/2-cateto);
		glRotatef(45,0,1,0);
		p1->desenhar();
		//plano(hipotnusa,hipotnusa,CAMADAS,CAMADAS);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(comp/2-cateto,0.0f,-(larg/2-dir/2));
		p2->desenhar();
		//plano(cateto*2,dir,CAMADAS,CAMADAS);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-(comp/2-(cateto+sul)/2),0.0f,larg/2-cateto/2);
		p3->desenhar();
	//plano(cateto+sul,cateto,CAMADAS,CAMADAS);
	glPopMatrix();



} 

void BarVBO::Parede_params(float comp,float larg,float altura){
	float cateto,hipotnusa;
	float dir,sul;
	float aux;
	float base_porta,altura_porta;
	if((0.3*comp) < (0.3*larg)){
		cateto=0.3*comp;
		}
	else{
		cateto=0.3*larg;
	}
	hipotnusa = sqrt(pow(cateto,2)*2);
	
	base_porta= 0.2*cateto;
	altura_porta=0.7*altura;


	dir = larg-cateto;
	sul = comp-cateto*2;
	if (dir<cateto)
		dir=cateto;
	if(sul<0)
		sul=cateto;


	glPushMatrix(); //PAREDE DIAGONAL
		glTranslatef(comp/2-cateto,0.0f,larg/2-cateto);
		glRotatef(45,0,1,0);
		glRotatef(90,0,0,1);
		glRotatef(90,1,0,0);
		glTranslatef(altura/2,hipotnusa/2,0);
		Plano* p1 = new Plano(altura,hipotnusa,CAMADAS,CAMADAS);
		p1->desenhar();
		//plano(altura,hipotnusa,CAMADAS,CAMADAS);
		glRotatef(180,1,0,0);
		p1->desenhar();
		//plano(altura,hipotnusa,CAMADAS,CAMADAS);
	glPopMatrix();

	glPushMatrix();//PAREDE NORTE
	glTranslatef(comp/2-cateto,altura/2,-larg/2);
		glRotatef(90,0,0,1);
		glRotatef(90,1,0,0);
		//plano(altura,cateto*2,CAMADAS,CAMADAS);
		Plano* p2 = new Plano(altura,cateto*2,CAMADAS,CAMADAS);
		p2->desenhar();
		glRotatef(180,1,0,0);
		p2->desenhar();
		//plano(altura,cateto*2,CAMADAS,CAMADAS);
	glPopMatrix();
	
	glPushMatrix();//PAREDE DIR
	glTranslatef(comp/2,altura/2,-(larg/2-dir/2));
		glRotatef(90,0,0,1);
		Plano* p3 = new Plano(altura,dir,CAMADAS,CAMADAS);
		p3->desenhar();
		//plano(altura,dir,CAMADAS,CAMADAS);
		glRotatef(180,1,0,0);
		p3->desenhar();
		//plano(altura,dir,CAMADAS,CAMADAS);
	glPopMatrix();
	
	
	glPushMatrix();//PAREDE ESQ
	glTranslatef(-comp/2+sul,altura/2,-(larg/2-dir/2));
		glRotatef(90,0,0,1);
		p3->desenhar();
		
		//plano(altura,dir,CAMADAS,CAMADAS);
		glRotatef(180,1,0,0);
		p3->desenhar();
		//plano(altura,dir,CAMADAS,CAMADAS);
	glPopMatrix();
	
	glPushMatrix(); //PAREDE SULNORTE
	 aux = (sul-cateto)*2;
	glTranslatef(-comp/2+aux,altura/2,larg/2-cateto);
		glRotatef(90,0,0,1);
		glRotatef(90,1,0,0);
		Plano* p4 = new Plano(altura,sul,CAMADAS,CAMADAS);
		p4->desenhar();
		//plano(altura,sul,CAMADAS,CAMADAS);
		glRotatef(180,1,0,0);
		p4->desenhar();
		//plano(altura,sul,CAMADAS,CAMADAS);
	glPopMatrix();
	
	glPushMatrix(); //PAREDE SULESQ
	 aux = (sul-cateto)*2;
	glTranslatef(-comp/2+aux,altura/2,larg/2);
		glRotatef(90,0,0,1);
		glRotatef(90,1,0,0);
		p4->desenhar();
		//plano(altura,sul,CAMADAS,CAMADAS);
		glRotatef(180,1,0,0);
		p4->desenhar();
		//plano(altura,sul,CAMADAS,CAMADAS);
	glPopMatrix();
	

	glPushMatrix(); //PAREDE SULDIR
	glTranslatef(comp/2-cateto-cateto/2,altura/2,larg/2);
		glRotatef(90,0,0,1);
		glRotatef(90,1,0,0);
		Plano* p5  = new Plano(altura,cateto,CAMADAS,CAMADAS);
		p5->desenhar();
		//plano(altura,cateto,CAMADAS,CAMADAS);
		glRotatef(180,1,0,0);
		p5->desenhar();
		//plano(altura,cateto,CAMADAS,CAMADAS);
	glPopMatrix();

	glPushMatrix(); //PAREDE SULESQ
		glTranslatef(-comp/2,altura/2,larg/2-cateto/2);
		glRotatef(90,0,1,0);
		glRotatef(90,0,0,1);
		glRotatef(90,1,0,0);
		p5->desenhar();
		//plano(altura,cateto,CAMADAS,CAMADAS);
		glRotatef(180,1,0,0);
		p5->desenhar();
		//plano(altura,cateto,CAMADAS,CAMADAS);
	glPopMatrix();

	glPushMatrix();//PAREDESWCDIR
		glTranslatef(-comp/2+sul,altura/2,larg/2-cateto/2);
		glRotatef(90,0,1,0);
		glRotatef(90,0,0,1);
		glRotatef(90,1,0,0);
		glPushMatrix();
			Plano* p6 = new Plano(altura,2*base_porta,CAMADAS,CAMADAS);
			p6->desenhar();
			//plano(altura,2*base_porta,CAMADAS,CAMADAS);
			glRotatef(180,1,0,0);
			p6->desenhar();
			//plano(altura,2*base_porta,CAMADAS,CAMADAS);
		glPopMatrix();
		
		glPushMatrix();
		glTranslatef(altura/2-(altura-altura_porta)/2,0,0);
			Plano* p7 = new Plano(altura-altura_porta,cateto,CAMADAS,CAMADAS);
			p7->desenhar();
			//plano(altura-altura_porta,cateto,CAMADAS,CAMADAS);
			glRotatef(180,1,0,0);
			p7->desenhar();
			//plano(altura-altura_porta,cateto,CAMADAS,CAMADAS);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0,-0.15,-base_porta);
			glRotatef(-90,1,0,0);
			Plano*p8 = new Plano(altura,0.30f,CAMADAS,CAMADAS);
			p8->desenhar();
			//plano(altura,0.30,CAMADAS,CAMADAS);
			glPopMatrix();
		glPushMatrix();
			glTranslatef(0,-0.15,base_porta);
			glRotatef(90,1,0,0);
			p8->desenhar();
			//plano(altura,0.30,CAMADAS,CAMADAS);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();//PAREDESWCESQ
		glTranslatef(-comp/2+sul-0.30,altura/2,larg/2-cateto/2);
		glRotatef(90,0,1,0);
		glRotatef(90,0,0,1);
		glRotatef(90,1,0,0);
		glPushMatrix();
			Plano* p9 = new Plano(altura,2*base_porta,CAMADAS,CAMADAS);
			p9->desenhar();
			//plano(altura,2*base_porta,CAMADAS,CAMADAS);
			glRotatef(180,1,0,0);
			p9->desenhar();
			//plano(altura,2*base_porta,CAMADAS,CAMADAS);
		glPopMatrix();
		
		glPushMatrix();
		glTranslatef(altura/2-(altura-altura_porta)/2,0,0);
			p7->desenhar();
			//plano(altura-altura_porta,cateto,CAMADAS,CAMADAS);
			glRotatef(180,1,0,0);
			p7->desenhar();
			//plano(altura-altura_porta,cateto,CAMADAS,CAMADAS);
		glPopMatrix();
	glPopMatrix();
}

void BarVBO::Tecto_params(float comp, float larg, float altura){
	float cateto,hipotnusa;
	float dir,sul;
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

	glPushMatrix();

		glTranslatef(0,altura,0);
	
		glPushMatrix();
			glTranslatef(comp/2-cateto,0.0f,larg/2-cateto);
			glRotatef(180,1,0,0);
			glRotatef(45,0,1,0);
			Plano* p1 = new Plano(hipotnusa,hipotnusa,CAMADAS,CAMADAS);
			p1->desenhar();
			//plano(hipotnusa,hipotnusa,CAMADAS,CAMADAS);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(comp/2-cateto,0.0f,-(larg/2-dir/2));
			glRotatef(180,1,0,0);
			Plano* p2 = new Plano(cateto*2,dir,CAMADAS,CAMADAS);
			p2->desenhar();
			//plano(cateto*2,dir,CAMADAS,CAMADAS);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-(comp/2-(cateto+sul)/2),0.0f,larg/2-cateto/2);
			glRotatef(180,0,0,1);
			Plano* p3 = new Plano(cateto+sul,cateto,CAMADAS,CAMADAS);
			p3->desenhar();
			//plano(cateto+sul,cateto,CAMADAS,CAMADAS);
		glPopMatrix();
	glPopMatrix();
	glPushMatrix(); //WCENTRADA
		glTranslatef(0,0.7*altura,0);
		glTranslatef(-comp/2+sul-0.15,0,larg/2-cateto/2);
		glRotated(180,1,0,0);
		Plano* p4 = new Plano(0.3f,cateto,CAMADAS,CAMADAS);
		//plano(0.3,cateto,CAMADAS,CAMADAS);
	glPopMatrix();
	
}


void BarVBO::Chao(){
	float larg = 15;
	float comp = 10;

	glPushMatrix();
		glScalef(size,size,size);
		Chao_params(comp,larg);
	glPopMatrix();
}

void BarVBO::Tecto(){
	float larg=15;
	float comp=10;
	float altura=3;

	glPushMatrix();
		glScalef(size,size,size);
		Tecto_params(comp,larg,altura);
	glPopMatrix();
}

void BarVBO::Parede(){
	float larg=15;
	float comp=10;
	float altura=3;

	glPushMatrix();
		glScalef(size,size,size);
		Parede_params(comp,larg,altura);
	glPopMatrix();
}

