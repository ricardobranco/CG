#include <stdlib.h>
#include <GL/glew.h>
#include <GL/glut.h>

#include <math.h>

#include "Esfera.h"

#define _PI_ 3.14159

float alfa = 0.0f, beta = 0.0f, raio = 5.0f;
float camX, camY, camZ;

Esfera *e;

// declarar variáveis para armazenar os VBOs e número de vértices total
//...

void converte() {

	camX = raio * cos(beta) * sin(alfa);
	camY = raio * sin(beta);
	camZ = raio * cos(beta) * cos(alfa);
}


void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window with zero width).
	if(h == 0)
		h = 1;

	// compute window's aspect ratio 
	float ratio = w * 1.0 / h;

	// Reset the coordinate system before modifying
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective
	gluPerspective(45,ratio,1,1000);

	// return to the model view matrix mode
	glMatrixMode(GL_MODELVIEW);
}




/*----------------------------------------------------------------------------------- 
		RENDER SCENE
-----------------------------------------------------------------------------------*/

void renderScene(void) {

	float pos[4] = {1.0, 1.0, 1.0, 0.0};

	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	
	gluLookAt(camX,camY,camZ, 
			  0.0,0.0,0.0,
			  0.0f,1.0f,0.0f);

	glLightfv(GL_LIGHT0, GL_POSITION, pos);

// Desenhar Cilindro
	float cor[]={0.3,0.3,0.3};
	float spec[]={0.7,0.7,0.7,1.0};
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,cor);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,spec);
	glMateriali(GL_FRONT_AND_BACK,GL_SHININESS,128);
	e->desenhar();
	glTranslatef(3,0,0);
	e->desenhar();

// End of frame
	glutSwapBuffers();
}


// função de processamento do teclado
void processKeys(int key, int xx, int yy) 
{
	switch(key) {
	
		case GLUT_KEY_RIGHT: 
						alfa -=0.1; break;

		case GLUT_KEY_LEFT: 
						alfa += 0.1; break;

		case GLUT_KEY_UP : 
						beta += 0.1f;
						if (beta > 1.5f)
							beta = 1.5f;
						break;

		case GLUT_KEY_DOWN: 
						beta -= 0.1f; 
						if (beta < -1.5f)
							beta = -1.5f;
						break;

		case GLUT_KEY_PAGE_UP : raio -= 0.1f; 
			if (raio < 0.1f)
				raio = 0.1f;
			break;

		case GLUT_KEY_PAGE_DOWN: raio += 0.1f; break;
	
	}
	converte();
	glutPostRedisplay();
}


void main(int argc, char **argv) {

// inicialização
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(320,320);
	glutCreateWindow("CG@DI-UM");
		
// registo de funções 
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);
	glutReshapeFunc(changeSize);

// registo da funções do teclado e rato
	glutSpecialFunc(processKeys);

	glewInit();
	
// alguns settings para OpenGL
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

// inicialização da luz
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

// init
	converte();
	
	e=new Esfera(1,150,300);

// entrar no ciclo do GLUT 
	glutMainLoop();
}

