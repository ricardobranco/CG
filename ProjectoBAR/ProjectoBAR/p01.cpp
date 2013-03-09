#include "primitivas.h"

#include <GL/glut.h>

#include <math.h>
#include <time.h>
#include <stdio.h>



void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window with zero width).
	if(h == 0)
		h = 1;

	// compute window's aspect ratio 
	float ratio = w * 1.0 / h;

	// Set the projection matrix as current
	glMatrixMode(GL_PROJECTION);
	// Load Identity Matrix
	glLoadIdentity();
	
	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set perspective
	gluPerspective(45.0f ,ratio, 1.0f ,1000.0f);

	// return to the model view matrix mode
	glMatrixMode(GL_MODELVIEW);
}



void renderScene(void) {

	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the camera
	glLoadIdentity();
	gluLookAt(0.0,3.0,5.0, 
			  0.0,0.0,-1.0,
			  0.0f,1.0f,0.0f);

// pôr instruções de desenho aqui
	static float t = 0.0;
	t+=0.01;
	float s = (0.3 * sin(t)) + 0.7;
	//glutWireTeapot(s);
	plano(s,2*s);
	
	glColor3f((sin(t+1.5)+1)/2, (sin(t)+1)/2, (cos(t)+1)/2);

	// End of frame
	glutSwapBuffers();
}




int main(int argc, char **argv) {

// pôr inicialização aqui
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);

	glutCreateWindow("CG@DI");


// pôr registo de funções aqui
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);



// alguns settings para OpenGL
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glClearColor(0.0f,0.0f,0.0f,0.0f);

// entrar no ciclo do GLUT aqui
	glutMainLoop();
	return 0;
}