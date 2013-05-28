#include <stdlib.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include "Maths\Maths.h"

#include "BancoAlto.h"
#include "BancoBalcao.h"
#include "BarVBO.h"
#include "copo.h"
#include "MesaQuadrada.h"
#include "MesaRedonda.h"
#include "Sofa.h"
#include "Bilhar.h"
#include "CandeeiroBilhar.h"
#include "CandeeiroLuz.h"
#include "Balcao.h"
#include "GarrafaAgua.h"


// include para a lib devil
// não esquecer de adicionar a lib (devil.lib) ao projecto
#include <IL/il.h>

#define _USE_MATH_DEFINES
#include <math.h>

#define ANG2RAD 3.14159265358979323846/360.0 
#define N_TEX 6
#define MADEIRA_TEX 0
#define TECIDO_SOFA_TEX 1
#define CHAO_TEX 2
#define PAREDES_TEX 3
#define TECTO_TEX 4
#define BALCAO_TAMPO_TEX 5


#define SENS_RATO 0.001
#define ANG 0.05
#define MOV 0.1



float height = 2.0f;
float x = 0.0f;
float z = 0.0f;


float camX = 00, camY = 1, camZ = 0;
float camDir[3]={1,0,0};
float ang=0;
int startX, startY;

float alpha = 0.0f, beta = 45;

unsigned char *imageData[N_TEX];


unsigned int tex[N_TEX];

unsigned int shadowMapTexture;
unsigned int mFBO;
unsigned int shadowMapSize=4098;

int wHeight;
int wWidth;

MATRIX4X4 lightProjectionMatrix, lightViewMatrix;
MATRIX4X4 cameraProjectionMatrix, cameraViewMatrix;

float pos[4] = {4.9, 1.9, -7.4, 1};
float spotDir[]={-1,-1,1};
float ambLight=0.2;


BancoAlto *bancAlto;
BancoBalcao *bancBalc;
BarVBO *bar;
Copo *copoV;
Copo *copoL;
Copo *flt;
MesaQuadrada *mesaQ;
MesaRedonda *mesaR;
Sofa *sofa;
Bilhar *bil;
CandeeiroBilhar *cBilhar;
Balcao *balcao;
CandeeiroLuz *cLuz;

int count;
GLuint buffers[2];


void initMatrix(){

	glPushMatrix();
	
	glLoadIdentity();
	gluPerspective(107, 1, 0.1, 20);
	
	glGetFloatv(GL_MODELVIEW_MATRIX, lightProjectionMatrix);
	
	glLoadIdentity();
	gluLookAt(	pos[0], pos[1], pos[2],
		pos[0]+spotDir[0], pos[1]+spotDir[1],pos[2]+spotDir[2],
		0.0f, 1.0f, 0.0f);
	
	glGetFloatv(GL_MODELVIEW_MATRIX, lightViewMatrix);
	
	camDir[0]=cos(alpha)*sin(beta);
	camDir[1]=cos(beta);
	camDir[2]=sin(alpha)*sin(beta);

	glLoadIdentity();
	gluPerspective(45,(float)wWidth/wHeight,0.1,20);
	glGetFloatv(GL_MODELVIEW_MATRIX, cameraProjectionMatrix);
	
	glLoadIdentity();
	gluLookAt(	camX,camY,camZ,
		camX+camDir[0],camY+camDir[1],camZ+camDir[2],
		0.0f, 1.0f, 0.0f);
	glGetFloatv(GL_MODELVIEW_MATRIX, cameraViewMatrix);
	
	glPopMatrix();

}








void changeSize(int w, int h) {

	wHeight=h;
	wWidth=w;

	//// Prevent a divide by zero, when window is too short
	//// (you cant make a window with zero width).
	//if(h == 0)
	//	h = 1;

	//// compute window's aspect ratio 
	//float ratio = w * 1.0 / h;

	//// Reset the coordinate system before modifying
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//
	//// Set the viewport to be the entire window
	//glViewport(0, 0, w, h);

	//// Set the correct perspective
	//gluPerspective(45,ratio,1,500);

	//// return to the model view matrix mode
	//glMatrixMode(GL_MODELVIEW);
}




void drawScene() {
	
	bar->desenhar(tex[CHAO_TEX],tex[PAREDES_TEX],0);

	glPushMatrix();
	glTranslatef(4.9,1.9,-7.4);
	glRotatef(-45,1,0,1);
	cLuz->desenhar();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,0,-3);
	glRotatef(90,0,1,0);
	balcao->desenhar(tex[BALCAO_TAMPO_TEX],tex[MADEIRA_TEX]);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(4.3,0,-7.15);
	
	glPushMatrix();
	glRotatef(-90,0,1,0);
	sofa->desenharTex(tex[TECIDO_SOFA_TEX]);
	glPopMatrix();
	glTranslatef(0,0,1);
	mesaQ->desenharTex(tex[MADEIRA_TEX]);
	glPushMatrix();
	glTranslatef(0.0,0.425,0);
	copoV->desenhar();
	glTranslatef(0.07,0,0.07);
	copoL->desenhar();
	glPopMatrix();
	glTranslatef(0,0,1);
	glPushMatrix();
	glRotatef(90,0,1,0);
	sofa->desenharTex(tex[TECIDO_SOFA_TEX]);
	glPopMatrix();
	
	glTranslatef(0,0,0.7);

	glPushMatrix();
	glRotatef(-90,0,1,0);
	sofa->desenharTex(tex[TECIDO_SOFA_TEX]);
	glPopMatrix();
	glTranslatef(0,0,1);
	mesaQ->desenharTex(tex[MADEIRA_TEX]);
	glPushMatrix();
	glTranslatef(0.0,0.425,0);
	copoV->desenhar();
	glTranslatef(0.07,0,0.07);
	copoL->desenhar();
	glPopMatrix();
	glTranslatef(0,0,1);
	glPushMatrix();
	glRotatef(90,0,1,0);
	sofa->desenharTex(tex[TECIDO_SOFA_TEX]);
	glPopMatrix();
	
	glTranslatef(0,0,0.7);

	glPushMatrix();
	glRotatef(-90,0,1,0);
	sofa->desenharTex(tex[TECIDO_SOFA_TEX]);
	glPopMatrix();
	glTranslatef(0,0,1);
	mesaQ->desenharTex(tex[MADEIRA_TEX]);
	glPushMatrix();
	glTranslatef(0.0,0.425,0);
	copoV->desenhar();
	glTranslatef(0.07,0,0.07);
	copoL->desenhar();
	glPopMatrix();
	glTranslatef(0,0,1);
	glPushMatrix();
	glRotatef(90,0,1,0);
	sofa->desenharTex(tex[TECIDO_SOFA_TEX]);
	glPopMatrix();

	glTranslatef(0,0,0.7);

	glPushMatrix();
	glRotatef(-90,0,1,0);
	sofa->desenharTex(tex[TECIDO_SOFA_TEX]);
	glPopMatrix();
	glTranslatef(0,0,1);
	mesaQ->desenharTex(tex[MADEIRA_TEX]);
	glPushMatrix();
	glTranslatef(0.0,0.425,0);
	copoV->desenhar();
	glTranslatef(0.07,0,0.07);
	copoL->desenhar();
	glPopMatrix();
	glTranslatef(0,0,1);
	glPushMatrix();
	glRotatef(90,0,1,0);
	sofa->desenharTex(tex[TECIDO_SOFA_TEX]);
	glPopMatrix();

	glPopMatrix();


	glPushMatrix();
	glTranslatef(-2.5,0,6);
	bil->desenhar(tex[MADEIRA_TEX],tex[TECIDO_SOFA_TEX]);
	glTranslatef(0,1.5,0);
	cBilhar->desenhar();
	glPopMatrix();
	
	
}



void renderScene(void) {
	initMatrix();
	printf("%f-%f-%f\n",camX,camY,camZ);
	
	glBindFramebuffer(GL_DRAW_FRAMEBUFFER, mFBO);

	//First pass - from light's point of view
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(lightProjectionMatrix);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glLoadMatrixf(lightViewMatrix);

	//Use viewport the same size as the shadow map
	glViewport(0, 0, shadowMapSize, shadowMapSize);

	//Draw back faces into the shadow map
	glCullFace(GL_FRONT);
	
	//Draw the scene
	drawScene();

	//restore states
	glCullFace(GL_BACK);
	
	glBindFramebuffer(GL_FRAMEBUFFER,0);

	//2nd pass - Draw from camera's point of view
	glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(cameraProjectionMatrix);

	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(cameraViewMatrix);

	glViewport(0, 0, wWidth, wHeight);


	//Use dim light to represent shadowed areas
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHTING);

	glLightfv(GL_LIGHT1, GL_POSITION, pos);
	glLightfv(GL_LIGHT1, GL_AMBIENT, white*ambLight);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, white*ambLight);
	glLightfv(GL_LIGHT1, GL_SPECULAR, black);
	
	
	
	glEnable(GL_TEXTURE0);
	glActiveTexture(GL_TEXTURE0);
	glEnable(GL_TEXTURE_2D);

	drawScene();
	
	
	
	//3rd pass
	//Draw with bright light
	glLightfv(GL_LIGHT1, GL_DIFFUSE, white);
	glLightfv(GL_LIGHT1, GL_SPECULAR, white);
	glLightf(GL_LIGHT1,GL_SPOT_CUTOFF,90.0);
	glLightf(GL_LIGHT1,GL_SPOT_EXPONENT,1.0);
	glLightfv(GL_LIGHT1,GL_SPOT_DIRECTION,spotDir);


	//Calculate texture matrix for projection
	//This matrix takes us from eye space to the light's clip space
	//It is postmultiplied by the inverse of the current view matrix when specifying texgen
	static MATRIX4X4 biasMatrix(0.5f, 0.0f, 0.0f, 0.0f,
								0.0f, 0.5f, 0.0f, 0.0f,
								0.0f, 0.0f, 0.5f, 0.0f,
								0.5f, 0.5f, 0.5f, 1.0f);	//bias from [-1, 1] to [0, 1]
	MATRIX4X4 textureMatrix=biasMatrix*lightProjectionMatrix*lightViewMatrix;

	//Set up texture coordinate generation.
	glEnable(GL_TEXTURE1);
	glActiveTexture(GL_TEXTURE1);
	

	glBindTexture(GL_TEXTURE_2D, shadowMapTexture);



	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
	glTexGenfv(GL_S, GL_EYE_PLANE, textureMatrix.GetRow(0));
	glEnable(GL_TEXTURE_GEN_S);

	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
	glTexGenfv(GL_T, GL_EYE_PLANE, textureMatrix.GetRow(1));
	glEnable(GL_TEXTURE_GEN_T);

	glTexGeni(GL_R, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
	glTexGenfv(GL_R, GL_EYE_PLANE, textureMatrix.GetRow(2));
	glEnable(GL_TEXTURE_GEN_R);

	glTexGeni(GL_Q, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
	glTexGenfv(GL_Q, GL_EYE_PLANE, textureMatrix.GetRow(3));
	glEnable(GL_TEXTURE_GEN_Q);

	//Bind & enable shadow map texture
	glBindTexture(GL_TEXTURE_2D, shadowMapTexture);
	glEnable(GL_TEXTURE_2D);
	

	
	glActiveTexture(GL_TEXTURE0);

	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	


	drawScene();
	
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE1);
	glDisable(GL_TEXTURE0);
	glActiveTexture(GL_TEXTURE1);

	//Disable textures and texgen
	glDisable(GL_TEXTURE_2D);

	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glDisable(GL_TEXTURE_GEN_R);
	glDisable(GL_TEXTURE_GEN_Q);

	//Restore other states
	glDisable(GL_LIGHTING);
	glDisable(GL_ALPHA_TEST);

	glActiveTexture(GL_TEXTURE0);
	glDisable(GL_TEXTURE1);

	

// End of frame
	glutSwapBuffers();
	
}



void processMouseButtons(int button, int state, int xx, int yy) 
{
	if(button==GLUT_LEFT_BUTTON){
		startX=xx;
		startY=yy;
	}
	glutPostRedisplay();
}


void processMouseMotion(int xx, int yy)
{

	int deltaX=startX-xx;
	int deltaY=startY-yy;
	startX=xx;
	startY=yy;

	beta-=deltaY*SENS_RATO;
	alpha+=deltaX*SENS_RATO;

	glutPostRedisplay();
}


void init() {

	bancAlto  = new BancoAlto(0.6);
	bancBalc = new BancoBalcao(0.5);
	bar = Bar(1);
	copoV=copo_vinho(0.025);
	copoL=copo_largo(0.025);
	flt=flute(0.025);
	mesaQ=new MesaQuadrada(0.5,0.2);
	mesaR=new MesaRedonda(0.4);
	sofa=new Sofa(0.7,2);
	bil=new Bilhar(0.7);
	cBilhar=new CandeeiroBilhar(2,0.3);
	balcao=new Balcao(5,1,2);
	cLuz=new CandeeiroLuz(0.1);
	
	GLfloat fLargest;
	glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &fLargest);

	ILuint ima[N_TEX];

	ilInit();
	ilGenImages(N_TEX,ima);
	glGenTextures(N_TEX,tex);

	int imagew,imageh;
	
	ilBindImage(ima[MADEIRA_TEX]);
	ilLoadImage((ILstring)"madeira_tex.jpg");
	ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);
	imagew=ilGetInteger(IL_IMAGE_WIDTH);
	imageh=ilGetInteger(IL_IMAGE_HEIGHT);
	imageData[MADEIRA_TEX]=ilGetData();
	glBindTexture(GL_TEXTURE_2D,tex[MADEIRA_TEX]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, fLargest);
	gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, imagew, imageh, GL_RGBA, GL_UNSIGNED_BYTE, imageData[MADEIRA_TEX]);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_BASE_LEVEL,0);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAX_LEVEL,10);

	ilBindImage(ima[TECIDO_SOFA_TEX]);
	ilLoadImage((ILstring)"tecido_sofa_tex.jpg");
	ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);
	imagew=ilGetInteger(IL_IMAGE_WIDTH);
	imageh=ilGetInteger(IL_IMAGE_HEIGHT);
	imageData[TECIDO_SOFA_TEX]=ilGetData();
	glBindTexture(GL_TEXTURE_2D,tex[TECIDO_SOFA_TEX]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, fLargest);
	gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, imagew, imageh, GL_RGBA, GL_UNSIGNED_BYTE, imageData[TECIDO_SOFA_TEX]);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_BASE_LEVEL,0);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAX_LEVEL,10);

	ilBindImage(ima[CHAO_TEX]);
	ilLoadImage((ILstring)"madeira_tex_alt.jpg");
	ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);
	imagew=ilGetInteger(IL_IMAGE_WIDTH);
	imageh=ilGetInteger(IL_IMAGE_HEIGHT);
	imageData[CHAO_TEX]=ilGetData();
	glBindTexture(GL_TEXTURE_2D,tex[CHAO_TEX]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, fLargest);
	gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, imagew, imageh, GL_RGBA, GL_UNSIGNED_BYTE, imageData[CHAO_TEX]);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_BASE_LEVEL,0);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAX_LEVEL,10);
	
	ilBindImage(ima[PAREDES_TEX]);
	ilLoadImage((ILstring)"parede_tex.jpg");
	ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);
	imagew=ilGetInteger(IL_IMAGE_WIDTH);
	imageh=ilGetInteger(IL_IMAGE_HEIGHT);
	imageData[PAREDES_TEX]=ilGetData();
	glBindTexture(GL_TEXTURE_2D,tex[PAREDES_TEX]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, fLargest);
	gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, imagew, imageh, GL_RGBA, GL_UNSIGNED_BYTE, imageData[PAREDES_TEX]);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_BASE_LEVEL,0);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAX_LEVEL,10);

	ilBindImage(ima[BALCAO_TAMPO_TEX]);
	ilLoadImage((ILstring)"balcao_tampo_tex.jpg");
	ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);
	imagew=ilGetInteger(IL_IMAGE_WIDTH);
	imageh=ilGetInteger(IL_IMAGE_HEIGHT);
	imageData[BALCAO_TAMPO_TEX]=ilGetData();
	glBindTexture(GL_TEXTURE_2D,tex[BALCAO_TAMPO_TEX]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, fLargest);
	gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, imagew, imageh, GL_RGBA, GL_UNSIGNED_BYTE, imageData[BALCAO_TAMPO_TEX]);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_BASE_LEVEL,0);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAX_LEVEL,10);


	//Create the shadow map texture
	glGenTextures(1, &shadowMapTexture);
	glBindTexture(GL_TEXTURE_2D, shadowMapTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	//Enable shadow comparison
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE_ARB, GL_COMPARE_R_TO_TEXTURE);
	//Shadow comparison should be true (ie not in shadow) if r<=texture
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_FUNC_ARB, GL_LEQUAL);
	glTexParameteri(GL_TEXTURE_2D, GL_DEPTH_TEXTURE_MODE_ARB, GL_ALPHA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, shadowMapSize, shadowMapSize, 0,GL_DEPTH_COMPONENT, GL_UNSIGNED_BYTE, NULL);

	//Load identity modelview
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Shading states
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glGenFramebuffers(1,&mFBO);
	glBindFramebuffer(GL_DRAW_FRAMEBUFFER, mFBO);
	glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, shadowMapTexture, 0);

	// Disable writes to the color buffer
	glDrawBuffer(GL_NONE);

	//Depth states
	glClearDepth(1.0f);
	glDepthFunc(GL_LEQUAL);
	

	//We use glScale when drawing the scene
	glEnable(GL_NORMALIZE);

// alguns settings para OpenGL
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D,0);
}

void teclado(unsigned char key, int x, int y){

	switch(key){

	case 'a': 
	case'A':
		alpha-=ANG;
		break;
	case 'd':
	case 'D':
		alpha+=ANG;
		break;
	case 'w':
	case 'W':
		camX+=MOV*camDir[0];
		camY+=MOV*camDir[1];
		camZ+=MOV*camDir[2];
		break;

	case 's':
	case 'S':
		camX-=MOV*camDir[0];
		camY-=MOV*camDir[1];
		camZ-=MOV*camDir[2];
		break;

	}
	glutPostRedisplay();
}


void main(int argc, char **argv) {

// inicialização
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(0,0);
	wWidth=350;
	wHeight=350;
	glutInitWindowSize(wWidth,wHeight);
	glutCreateWindow("CG@DI-UM");
		

// registo de funções 
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);
	glutReshapeFunc(changeSize);

// registo da funções do rato
	glutMouseFunc(processMouseButtons);
	glutMotionFunc(processMouseMotion);
	glutKeyboardFunc(teclado);


	glewInit();

	init();	

// entrar no ciclo do GLUT 
	glutMainLoop();
}

