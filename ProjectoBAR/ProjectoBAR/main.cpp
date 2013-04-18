#define _USE_MATH_DEFINES
#include <GL/glut.h>
#include <math.h>
#include "primitivas.h"
#include "copo.h"
#include "Objetos.h"
#include "Paredes.h"
#include "Bar.h"


#define MOV 0.1
#define ANG 0.05
#define SIZ 1
#define SENS_RATO 0.005

float base=1.0f;
float altura =1.0f;

float alpha=0.0f;
float beta=0.0;
float raio=10.0;

int ratoX =0.0;
int ratoY=0.0;

int solido=1;

void desenha_solid(){
	switch(solido){
	case 1:
		esfera_solid(1,45,90);
		break;
	case 2:
		cone_solid(2,1,45,90);
		break;
	case 3:
		plano(2,1,90,45);
		break;
	case 4:
		cubo_solid(1,45);
		break;
	case 5:
		cilindro_solid(2,1,45,90);
		break;
	}
}

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

	if(beta>M_PI/2-0.0001) beta=M_PI/2-0.0001;
	if(beta<-M_PI/2+0.0001) beta=-M_PI/2+0.0001;

	// set the camera
	glLoadIdentity();
	gluLookAt(raio*cos(beta)*sin(alpha) ,raio*sin(beta), raio*cos(beta)*cos(alpha), 
			  0.0,0.0,0.0,
			  0.0f,1.0f,0.0f);

// pôr instruções de desenho aqui
	//glTranslatef(posx,0.0,posz);
	//glRotatef(angulo,0.0f,1.0f,0.0f);
	
	
	//desenha_solid();

<<<<<<< HEAD
	Bar();
=======
	Candi4(2.0,4,10);
>>>>>>> origin/candeeiro

	//Mesacafe(0.75,1.5);

	// End of frame
	glutSwapBuffers();
}



// escrever função de processamento do teclado

void teclas(unsigned char tecla, int x, int y)
{

	switch (tecla)
	{
		case 'w': 
			raio-=SIZ;
			break;
		case 's':
			raio+=SIZ;
			break;
		case '1':
			solido=1;
			break;
		case '2':
			solido=2;
			break;
		case '3':
			solido=3;
			break;
		case '4':
			solido=4;
			break;
		case '5':
			solido=5;
			break;
	}
	glutPostRedisplay();
}

void teclas_especiais(int tecla, int x, int y){

	switch(tecla){
	case GLUT_KEY_UP:
		beta+=ANG;
		break;
	case GLUT_KEY_DOWN:
		beta-=ANG;
		break;
	case GLUT_KEY_LEFT:
		alpha-=ANG;
		break;
	case GLUT_KEY_RIGHT:
		alpha+=ANG;
	default:
		break;
	}
	glutPostRedisplay();
}

// escrever função de processamento do menu

void opcao_menu(int op){

	switch(op){
	case 1:
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		break;
	case 2:
		glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

void rato(int button, int state, int x, int y){
	if(button==GLUT_LEFT_BUTTON){
		ratoX=x;
		ratoY=y;
	}
}

void rato_mov(int x, int y){
	int deltaX=ratoX-x;
	int deltaY=ratoY-y;
	ratoX=x;
	ratoY=y;

	beta-=deltaY*SENS_RATO;
	alpha+=deltaX*SENS_RATO;

	glutPostRedisplay();
}

int main(int argc, char **argv) {

// inicialização
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	glutCreateWindow("CG@DI-UM");
		

// registo de funções 
	glutDisplayFunc(renderScene);
	//glutIdleFunc(renderScene);
	glutReshapeFunc(changeSize);

// pôr aqui registo da funções do teclado e rato

	glutKeyboardFunc(teclas);
	glutSpecialFunc(teclas_especiais);

// pôr aqui a criação do menu
	
	

	glutMouseFunc(rato);
	glutMotionFunc(rato_mov);
	
	int menu = glutCreateMenu(opcao_menu);

	glutAddMenuEntry("Linhas",1);
	glutAddMenuEntry("Solido",2);

	glutAttachMenu(GLUT_RIGHT_BUTTON);

// alguns settings para OpenGL
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	
// entrar no ciclo do GLUT 
	glutMainLoop();
	
	return 1;
}

