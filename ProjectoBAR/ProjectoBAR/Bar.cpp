#include <math.h>
#include <glew.h>
#include <GL/glut.h>
#include "primitivas.h"
#include "Paredes.h"


void Bar(){

	float ladox = 10.0f;
	float ladoz = 6.0f;
	float espessura = 0.15f;
	float altura = 3.0f;
	float porta = 2.0f;
	float baseporta = 0.8f;
	glPushMatrix();
		plano(ladoz,ladox,50,50);
		glTranslatef(0.0f,altura/2,0.0f);;
		
		glPushMatrix();
			paredesparalelas(altura,ladoz,espessura,ladox-2*espessura);
			glRotatef(90.0f,0.0f,1.0f,0.0f);
			
			glPushMatrix();
				glTranslatef(0.0f,0.0f,ladoz/2);
				paredeporta(altura,ladox,espessura,porta,baseporta);
			glPopMatrix();
	
			glTranslatef(0.0f,0.0f,-ladoz/2);
			parede(altura,ladox,espessura);
	
		glPopMatrix();
		glTranslatef(0.0f,altura/2,0.0f);
		plano(ladoz,ladox,50,50);	
	glPopMatrix();
	


}
