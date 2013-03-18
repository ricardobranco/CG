#define _USE_MATH_DEFINES
#include <GL/glut.h>
#include <math.h>
#include "C:\Users\Paxaxa\documents\GitHub\CG\ProjectoBAR\ProjectoBAR\primitivas.h"

#define MOV 0.1
#define ANG 0.05
#define SIZ 0.01
#define SENS_RATO 0.005

float base =1.0f;
float altura =1.0f;

float alpha=0.0f;
float beta=0.0;
float raio=5.0;

int ratoX =0.0;
int ratoY=0.0;

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
	
	//glPolygonMode(GL_FRONT,GL_LINE);
	cuboSOLID(1,10);

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
		default:
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
		glPolygonMode(GL_FRONT,GL_FILL);
		glPolygonMode(GL_BACK,GL_LINE);
		glCullFace(GL_BACK);
		break;
	case 3:
		glPolygonMode(GL_FRONT, GL_LINE);
		glPolygonMode(GL_BACK, GL_FILL);
		glCullFace(GL_FRONT);
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
	int menu = glutCreateMenu(opcao_menu);
	

	glutMouseFunc(rato);
	glutMotionFunc(rato_mov);
	
	
	glutAddMenuEntry("Linhas",1);
	glutAddMenuEntry("Solido",2);
	glutAddMenuEntry("Cenas",3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

// alguns settings para OpenGL
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	
// entrar no ciclo do GLUT 
	glutMainLoop();
	
	return 1;
}

