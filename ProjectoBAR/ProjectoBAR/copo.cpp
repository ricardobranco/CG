#define _USE_MATH_DEFINES
#include <math.h>
#include <glew.h>
#include <GL/glut.h>

void desenha_copo(float size) {

	glPushMatrix();

	glScalef(1,1.4,1);

	
	int divh=100;
	int divv=60;

	float incv = M_PI /((float) divv);
	float inch = 2*M_PI /((float) divh);

	glBegin(GL_TRIANGLES);
	float raio1=1.0;
	float raio2=0.95;
	float av=20*incv;
	
	

	for(int iv=20; iv<divv; iv++){

		float ah=0.0f;

		for(int ih=0; ih<divh; ih++){

			glVertex3f(raio1*sin(av)*sin(ah), raio1*cos(av), raio1*sin(av)*cos(ah));
			glVertex3f(raio1*sin(av+incv)*sin(ah), raio1*cos(av+incv), raio1*sin(av+incv)*cos(ah));
			glVertex3f(raio1*sin(av+incv)*sin(ah+inch), raio1*cos(av+incv), raio1*sin(av+incv)*cos(ah+inch));

			glVertex3f(raio1*sin(av)*sin(ah), raio1*cos(av), raio1*sin(av)*cos(ah));
			glVertex3f(raio1*sin(av+incv)*sin(ah+inch), raio1*cos(av+incv), raio1*sin(av+incv)*cos(ah+inch));
			glVertex3f(raio1*sin(av)*sin(ah+inch), raio1*cos(av), raio1*sin(av)*cos(ah+inch));

			ah+=inch;
		}
		av+=incv;
	}
	
	

	float av2=acos((cos(20*incv))/raio2);
	float incv2=(M_PI-av2)/40;
	for(int iv=20; iv<divv; iv++){

		float ah=0.0f;

		for(int ih=0; ih<divh; ih++){

			glVertex3f(raio2*sin(av2)*sin(ah), raio2*cos(av2), raio2*sin(av2)*cos(ah));
			glVertex3f(raio2*sin(av2+incv2)*sin(ah+inch), raio2*cos(av2+incv2), raio2*sin(av2+incv2)*cos(ah+inch));
			glVertex3f(raio2*sin(av2+incv2)*sin(ah), raio2*cos(av2+incv2), raio2*sin(av2+incv2)*cos(ah));

			glVertex3f(raio2*sin(av2)*sin(ah), raio2*cos(av2), raio2*sin(av2)*cos(ah));
			glVertex3f(raio2*sin(av2)*sin(ah+inch), raio2*cos(av2), raio2*sin(av2)*cos(ah+inch));
			glVertex3f(raio2*sin(av2+incv2)*sin(ah+inch), raio2*cos(av2+incv2), raio2*sin(av2+incv2)*cos(ah+inch));

			ah+=inch;
		}
		av2+=incv2;
	}

	

	float y =raio1*cos(incv*20);
	
	float raiob1=raio1*sin(incv*20);
	float raiob2=raio2*sin(acos((cos(20*incv))/raio2));
	
	for(int ih=0;ih<divh;ih++){
		float ah=((float)ih)*inch;

		glVertex3f(raiob1*sin(ah),y,raiob1*cos(ah));
		glVertex3f(raiob2*sin(ah+inch),y,raiob2*cos(ah+inch));
		glVertex3f(raiob2*sin(ah),y,raiob2*cos(ah));

		glVertex3f(raiob1*sin(ah),y,raiob1*cos(ah));
		glVertex3f(raiob1*sin(ah+inch),y,raiob1*cos(ah+inch));
		glVertex3f(raiob2*sin(ah+inch),y,raiob2*cos(ah+inch));

	}

	glEnd();

	glPopMatrix();

}