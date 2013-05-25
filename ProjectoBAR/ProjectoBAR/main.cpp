#include <stdlib.h>
#include <GL/glew.h>
#include <GL/glut.h>

#include <math.h>

#include "Esfera.h"
#include "Cubo.h"
#include "Plano.h"
#include "Cilindro.h"
#include "Cone.h"

#define ESFERA 1
#define PLANO 2
#define CUBO 3
#define CILINDRO 4
#define CONE 5

#include "cadeiraVBO.h"
#include "CandeeirosVBO.h"
#include "Extras.h"




#define _PI_ 3.14159

float alfa = 0.0f, beta = 0.0f, raio = 5.0f;
float camX, camY, camZ;

//Primitivas em VBO
Esfera *esfera;
Cubo *cubo;
Plano *plano;
Cilindro *cilindro;
Cone *cone;
CadeiraVBO *sofa;
Extras *ext;

//BarVBO* bar;

int solido=ESFERA;


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

	float pos[4] = {1.0, 4.0, 1.0, 1};
	float dif[] = {0.3,0.3,0.3,1};

	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	
	gluLookAt(camX,camY,camZ, 
			  0.0,0.0,0.0,
			  0.0f,1.0f,0.0f);

	glLightfv(GL_LIGHT0, GL_POSITION, pos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, dif);

// Desenhar Cilindro
	float cor[]={1.0,1.0,1.0,1.0};
	float spec[]={1,1,1,1.0};
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,cor);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,spec);
	glMateriali(GL_FRONT_AND_BACK,GL_SHININESS,128);
	/*
	switch (solido)
	{
	case ESFERA:
		
		esfera->desenhar(); break;
	
	case PLANO :
		plano->desenhar(); break;
	case CUBO :
		cubo->desenhar(); break;
	case CILINDRO :
		cilindro->desenhar(); break;
	case CONE :
		cone->desenhar(); break;
	}

	*/
	ext->setSize(1);
	ext->bilhar();
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


void teclas(unsigned char key, int x, int y){

	if((key>='1')&&(key<='5')){
		solido=key-'0';
	}

}


void main(int argc, char **argv) {

// inicialização
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	glutCreateWindow("CG@DI-UM");
		
// registo de funções 
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);
	glutReshapeFunc(changeSize);
	

// registo da funções do teclado e rato
	glutSpecialFunc(processKeys);
	glutKeyboardFunc(teclas);

	glewInit();
	
// alguns settings para OpenGL
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

// inicialização da luz
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

// init
	converte();
	
	esfera=new Esfera(1,200,400);
	cubo = new Cubo(1,100);
	plano = new Plano(2,2,100,100);
	cone= new Cone(1,2,50,50,50);
	cilindro = new Cilindro(0.5,1,40,40,20);
	ext=new Extras(1);
	sofa=new CadeiraVBO(1);
	//bar = new BarVBO(1);



// entrar no ciclo do GLUT 
	glutMainLoop();
}

