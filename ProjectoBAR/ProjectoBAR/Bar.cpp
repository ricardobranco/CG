#define _USE_MATH_DEFINES

#include <math.h>
#include <glew.h>
#include <GL/glut.h>
#include "primitivas.h"

void chao(float comp, float larg){


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
		plano(hipotnusa,hipotnusa,60,60);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(comp/2-cateto,0.0f,-(larg/2-dir/2));
		plano(cateto*2,dir,60,60);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-(comp/2-(cateto+sul)/2),0.0f,larg/2-cateto/2);
	plano(cateto+sul,cateto,60,60);
	glPopMatrix();


} 

void paredes(float comp,float larg,float altura){
	
	float cateto,hipotnusa;
	float dir,sul;
	float aux;
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


	glPushMatrix(); //PAREDE DIAGONAL
		glTranslatef(comp/2-cateto,0.0f,larg/2-cateto);
		glRotatef(45,0,1,0);
		glRotatef(90,0,0,1);
		glRotatef(90,1,0,0);
		glTranslatef(altura/2,hipotnusa/2,0);
		plano(altura,hipotnusa,10,10);
		glRotatef(180,1,0,0);
		plano(altura,hipotnusa,60,60);
	glPopMatrix();

	glPushMatrix();//PAREDE NORTE
	glTranslatef(comp/2-cateto,altura/2,-larg/2);
		glRotatef(90,0,0,1);
		glRotatef(90,1,0,0);
		plano(altura,cateto*2,10,10);
		glRotatef(180,1,0,0);
		plano(altura,cateto*2,60,60);
	glPopMatrix();
	
	glPushMatrix();//PAREDE DIR
	glTranslatef(comp/2,altura/2,-(larg/2-dir/2));
		glRotatef(90,0,0,1);
		plano(altura,dir,10,10);
		glRotatef(180,1,0,0);
		plano(altura,dir,60,60);
	glPopMatrix();
	
	
	glPushMatrix();//PAREDE ESQ
	glTranslatef(-comp/2+sul,altura/2,-(larg/2-dir/2));
		glRotatef(90,0,0,1);
		plano(altura,dir,10,10);
		glRotatef(180,1,0,0);
		plano(altura,dir,60,60);
	glPopMatrix();
	
	glPushMatrix(); //PAREDE SULNORTE
	 aux = (sul-cateto)*2;
	glTranslatef(-comp/2+aux,altura/2,larg/2-cateto);
		glRotatef(90,0,0,1);
		glRotatef(90,1,0,0);
		plano(altura,sul,10,10);
		glRotatef(180,1,0,0);
		plano(altura,sul,60,60);
	glPopMatrix();
	
	glPushMatrix(); //PAREDE SULESQ
	 aux = (sul-cateto)*2;
	glTranslatef(-comp/2+aux,altura/2,larg/2);
		glRotatef(90,0,0,1);
		glRotatef(90,1,0,0);
		plano(altura,sul,10,10);
		glRotatef(180,1,0,0);
		plano(altura,sul,60,60);
	glPopMatrix();
	

	glPushMatrix(); //PAREDE SULDIR
	glTranslatef(comp/2-cateto-cateto/2,altura/2,larg/2);
		glRotatef(90,0,0,1);
		glRotatef(90,1,0,0);
		plano(altura,cateto,10,10);
		glRotatef(180,1,0,0);
		plano(altura,cateto,60,60);
	glPopMatrix();

	glPushMatrix(); //PAREDE SULESQ
	 aux = (sul-cateto)*2;
	glTranslatef(-comp/2,altura/2,larg/2-cateto/2);
		glRotatef(90,0,1,0);
		glRotatef(90,0,0,1);
		glRotatef(90,1,0,0);
		
		plano(altura,cateto,10,10);
		glRotatef(180,1,0,0);
		plano(altura,cateto,60,60);
	glPopMatrix();
	
}

void tecto(float comp, float larg,float altura){


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
		plano(hipotnusa,hipotnusa,60,60);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(comp/2-cateto,0.0f,-(larg/2-dir/2));
		glRotatef(180,1,0,0);
		plano(cateto*2,dir,60,60);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-(comp/2-(cateto+sul)/2),0.0f,larg/2-cateto/2);
	glRotatef(180,1,0,0);
	plano(cateto+sul,cateto,60,60);
	glPopMatrix();
	glPopMatrix();

} 


