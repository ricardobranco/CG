#define _USE_MATH_DEFINES

#include <math.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include "primitivas.h"

void chao_params(float comp, float larg){

	int camadas = 60;
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
		glTranslatef(comp/2-cateto,0.0f,larg/2-cateto);
		glRotatef(45,0,1,0);
		plano(hipotnusa,hipotnusa,camadas,camadas);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(comp/2-cateto,0.0f,-(larg/2-dir/2));
		plano(cateto*2,dir,camadas,camadas);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-(comp/2-(cateto+sul)/2),0.0f,larg/2-cateto/2);
	plano(cateto+sul,cateto,camadas,camadas);
	glPopMatrix();


} 

void paredes_params(float comp,float larg,float altura){
	

	int camadas=60;
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
		plano(altura,hipotnusa,camadas,camadas);
		glRotatef(180,1,0,0);
		plano(altura,hipotnusa,camadas,camadas);
	glPopMatrix();

	glPushMatrix();//PAREDE NORTE
	glTranslatef(comp/2-cateto,altura/2,-larg/2);
		glRotatef(90,0,0,1);
		glRotatef(90,1,0,0);
		plano(altura,cateto*2,camadas,camadas);
		glRotatef(180,1,0,0);
		plano(altura,cateto*2,camadas,camadas);
	glPopMatrix();
	
	glPushMatrix();//PAREDE DIR
	glTranslatef(comp/2,altura/2,-(larg/2-dir/2));
		glRotatef(90,0,0,1);
		plano(altura,dir,camadas,camadas);
		glRotatef(180,1,0,0);
		plano(altura,dir,camadas,camadas);
	glPopMatrix();
	
	
	glPushMatrix();//PAREDE ESQ
	glTranslatef(-comp/2+sul,altura/2,-(larg/2-dir/2));
		glRotatef(90,0,0,1);
		plano(altura,dir,camadas,camadas);
		glRotatef(180,1,0,0);
		plano(altura,dir,camadas,camadas);
	glPopMatrix();
	
	glPushMatrix(); //PAREDE SULNORTE
	 aux = (sul-cateto)*2;
	glTranslatef(-comp/2+aux,altura/2,larg/2-cateto);
		glRotatef(90,0,0,1);
		glRotatef(90,1,0,0);
		plano(altura,sul,camadas,camadas);
		glRotatef(180,1,0,0);
		plano(altura,sul,camadas,camadas);
	glPopMatrix();
	
	glPushMatrix(); //PAREDE SULESQ
	 aux = (sul-cateto)*2;
	glTranslatef(-comp/2+aux,altura/2,larg/2);
		glRotatef(90,0,0,1);
		glRotatef(90,1,0,0);
		plano(altura,sul,camadas,camadas);
		glRotatef(180,1,0,0);
		plano(altura,sul,camadas,camadas);
	glPopMatrix();
	

	glPushMatrix(); //PAREDE SULDIR
	glTranslatef(comp/2-cateto-cateto/2,altura/2,larg/2);
		glRotatef(90,0,0,1);
		glRotatef(90,1,0,0);
		plano(altura,cateto,camadas,camadas);
		glRotatef(180,1,0,0);
		plano(altura,cateto,camadas,camadas);
	glPopMatrix();

	glPushMatrix(); //PAREDE SULESQ
		glTranslatef(-comp/2,altura/2,larg/2-cateto/2);
		glRotatef(90,0,1,0);
		glRotatef(90,0,0,1);
		glRotatef(90,1,0,0);
		
		plano(altura,cateto,camadas,camadas);
		glRotatef(180,1,0,0);
		plano(altura,cateto,camadas,camadas);
	glPopMatrix();

	glPushMatrix();//PAREDESWCDIR
		glTranslatef(-comp/2+sul,altura/2,larg/2-cateto/2);
		glRotatef(90,0,1,0);
		glRotatef(90,0,0,1);
		glRotatef(90,1,0,0);
		glPushMatrix();
			plano(altura,2*base_porta,camadas,camadas);
			glRotatef(180,1,0,0);
			plano(altura,2*base_porta,camadas,camadas);
		glPopMatrix();
		
		glPushMatrix();
		glTranslatef(altura/2-(altura-altura_porta)/2,0,0);
			plano(altura-altura_porta,cateto,camadas,camadas);
			glRotatef(180,1,0,0);
			plano(altura-altura_porta,cateto,camadas,camadas);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0,-0.15,-base_porta);
			glRotatef(-90,1,0,0);
			plano(altura,0.30,camadas,camadas);
			glPopMatrix();
		glPushMatrix();
			glTranslatef(0,-0.15,base_porta);
			glRotatef(90,1,0,0);
			plano(altura,0.30,camadas,camadas);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();//PAREDESWCESQ
		glTranslatef(-comp/2+sul-0.30,altura/2,larg/2-cateto/2);
		glRotatef(90,0,1,0);
		glRotatef(90,0,0,1);
		glRotatef(90,1,0,0);
		glPushMatrix();
			plano(altura,2*base_porta,camadas,camadas);
			glRotatef(180,1,0,0);
			plano(altura,2*base_porta,camadas,camadas);
		glPopMatrix();
		
		glPushMatrix();
		glTranslatef(altura/2-(altura-altura_porta)/2,0,0);
			plano(altura-altura_porta,cateto,camadas,camadas);
			glRotatef(180,1,0,0);
			plano(altura-altura_porta,cateto,camadas,camadas);
		glPopMatrix();
	glPopMatrix();
	
}

void tecto_params(float comp, float larg,float altura){


	int camadas = 60;
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
			plano(hipotnusa,hipotnusa,camadas,camadas);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(comp/2-cateto,0.0f,-(larg/2-dir/2));
			glRotatef(180,1,0,0);
			plano(cateto*2,dir,camadas,camadas);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-(comp/2-(cateto+sul)/2),0.0f,larg/2-cateto/2);
			glRotatef(180,0,0,1);
			plano(cateto+sul,cateto,camadas,camadas);
		glPopMatrix();
	glPopMatrix();
	glPushMatrix(); //WCENTRADA
		glTranslatef(0,0.7*altura,0);
		glTranslatef(-comp/2+sul-0.15,0,larg/2-cateto/2);
		glRotated(180,1,0,0);
		plano(0.3,cateto,camadas,camadas);
	glPopMatrix();
	
} 


void chao(float scale){
	float larg = 15;
	float comp = 10;

	glPushMatrix();
		glScalef(scale,scale,scale);
		chao_params(comp,larg);
	glPopMatrix();

}

void paredes(float scale){
	float larg=15;
	float comp=10;
	float altura=3;

	glPushMatrix();
		glScalef(scale,scale,scale);
		paredes_params(comp,larg,altura);
	glPopMatrix();
}


void tecto(float scale){
	float larg=15;
	float comp=10;
	float altura=3;

	glPushMatrix();
		glScalef(scale,scale,scale);
		tecto_params(comp,larg,altura);
	glPopMatrix();

}