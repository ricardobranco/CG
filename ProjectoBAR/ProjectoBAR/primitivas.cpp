#define _USE_MATH_DEFINES

#include "primitivas.h"
#include <GL/glut.h>
#include <math.h>


void esfera_solid(float raio, int divv, int divh){

	float incv = M_PI /((float) divv);
	float inch = 2*M_PI /((float) divh);
	
	glBegin(GL_TRIANGLES);

	float av=0.0f;

	for(int iv=0; iv<divv; iv++){
		
		float ah=0.0f;

		for(int ih=0; ih<divh; ih++){
			
			
			
			glVertex3f(raio*sin(av)*cos(ah), raio*cos(av), raio*sin(av)*sin(ah));
			glVertex3f(raio*sin(av+incv)*cos(ah), raio*cos(av+incv), raio*sin(av+incv)*sin(ah));
			glVertex3f(raio*sin(av+incv)*cos(ah+inch), raio*cos(av+incv), raio*sin(av+incv)*sin(ah+inch));
			
			glVertex3f(raio*sin(av)*cos(ah), raio*cos(av), raio*sin(av)*sin(ah));
			glVertex3f(raio*sin(av+incv)*cos(ah+inch), raio*cos(av+incv), raio*sin(av+incv)*sin(ah+inch));
			glVertex3f(raio*sin(av)*cos(ah+inch), raio*cos(av), raio*sin(av)*sin(ah+inch));
				
			ah+=inch;
		}
		av+=incv;
	}

	glEnd();
}

void esfera_wire(float raio, int divv, int divh){

	float incv = M_PI /((float) divv);
	float inch = 2*M_PI /((float) divh);
	
	glBegin(GL_LINES);
	
	float av=0.0f;
	
	for(int iv=0; iv<divv; iv++){
		
		float ah=0.0f;
		
		for(int ih=0; ih<divh; ih++){
			
			
			
			glVertex3f(raio*sin(av)*cos(ah), raio*cos(av), raio*sin(av)*sin(ah));
			glVertex3f(raio*sin(av+incv)*cos(ah), raio*cos(av+incv), raio*sin(av+incv)*sin(ah));
			glVertex3f(raio*sin(av+incv)*cos(ah), raio*cos(av+incv), raio*sin(av+incv)*sin(ah));
			glVertex3f(raio*sin(av+incv)*cos(ah+inch), raio*cos(av+incv), raio*sin(av+incv)*sin(ah+inch));

			ah+=inch;
		}
		av+=incv;
	}

	glEnd();
}



void cilindro_solid(float altura, float raio, int div){

	float ang=0.0f;
	float ang_inc=2*M_PI/((float)div);
	glBegin(GL_TRIANGLES);
	for(int i=0; i<div;i++){

		

			glVertex3f(0.0,altura/2.0f, 0.0);
			glVertex3f(raio*sin(ang),altura/2.0f, raio*cos(ang));
			glVertex3f(raio*sin(ang+ang_inc),altura/2.0f, raio*cos(ang+ang_inc));

			glVertex3f(0.0,-altura/2.0f, 0.0);
			glVertex3f(raio*sin(ang+ang_inc),-altura/2.0f, raio*cos(ang+ang_inc));
			glVertex3f(raio*sin(ang),-altura/2.0f, raio*cos(ang));
			

			
			glVertex3f(raio*sin(ang),altura/2.0f, raio*cos(ang));
			glVertex3f(raio*sin(ang),-altura/2.0f, raio*cos(ang));
			glVertex3f(raio*sin(ang+ang_inc),-altura/2.0f, raio*cos(ang+ang_inc));
			
			glVertex3f(raio*sin(ang),altura/2.0f, raio*cos(ang));
			glVertex3f(raio*sin(ang+ang_inc),-altura/2.0f, raio*cos(ang+ang_inc));
			glVertex3f(raio*sin(ang+ang_inc),altura/2.0f, raio*cos(ang+ang_inc));

		

		ang+=ang_inc;

	}
	glEnd();
}

void cilindro_wire(float altura, float raio, int div){

	float ang=0.0f;
	float ang_inc=2*M_PI/((float)div);

	glBegin(GL_LINES);

	for(int i=0; i<div;i++){

		

			glVertex3f(0.0,altura/2.0f, 0.0);
			glVertex3f(raio*sin(ang),altura/2.0f, raio*cos(ang));
			
			glVertex3f(raio*sin(ang),altura/2.0f, raio*cos(ang));
			glVertex3f(raio*sin(ang+ang_inc),altura/2.0f, raio*cos(ang+ang_inc));

			glVertex3f(0.0,-altura/2.0f, 0.0);
			glVertex3f(raio*sin(ang),-altura/2.0f, raio*cos(ang));
			
			glVertex3f(raio*sin(ang),-altura/2.0f, raio*cos(ang));
			glVertex3f(raio*sin(ang+ang_inc),-altura/2.0f, raio*cos(ang+ang_inc));
			
			glVertex3f(raio*sin(ang),altura/2.0f, raio*cos(ang));
			glVertex3f(raio*sin(ang),-altura/2.0f, raio*cos(ang));
		
		ang+=ang_inc;

	}

	glEnd();
}

void cone_solid(float altura, float raio, int div){

	float ang=0.0f;
	float ang_inc=2*M_PI/((float) div);
	
	glBegin(GL_TRIANGLES);
	
	for(int i=0; i<div;i++){

		glVertex3f(0.0f, altura, 0.0f);
		glVertex3f(raio*sin(ang),0.0f,raio*cos(ang));
		glVertex3f(raio*sin(ang+ang_inc),0.0f,raio*cos(ang+ang_inc));

		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(raio*sin(ang+ang_inc),0.0f,raio*cos(ang+ang_inc));
		glVertex3f(raio*sin(ang),0.0f,raio*cos(ang));
		
		ang+=ang_inc;
	}
	glEnd();
}



void cone_wire(float altura, float raio, int div){

	float ang=0.0f;
	float ang_inc=2*M_PI/((float) div);
	
	glBegin(GL_LINES);
	
	for(int i=0; i<div;i++){

		glVertex3f(0.0f, altura, 0.0f);
		glVertex3f(raio*sin(ang),0.0f,raio*cos(ang));

		glVertex3f(raio*sin(ang),0.0f,raio*cos(ang));
		glVertex3f(raio*sin(ang+ang_inc),0.0f,raio*cos(ang+ang_inc));

		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(raio*sin(ang),0.0f,raio*cos(ang));

		ang+=ang_inc;
	}
	glEnd();

}