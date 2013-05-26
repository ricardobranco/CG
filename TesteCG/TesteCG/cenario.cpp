#include <stdlib.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include "C:\Users\Cesar\documents\GitHub\CG\ProjectoBAR\ProjectoBAR\Esfera.h"
#include "C:\Users\Cesar\Documents\GitHub\CG\ProjectoBAR\ProjectoBAR\Cone.h"
#include "C:\Users\Cesar\documents\visual studio 2012\Projects\TesteCG\TesteCG\Maths\Maths.h"
#include "C:\Users\Cesar\Documents\GitHub\CG\ProjectoBAR\ProjectoBAR\copo.h"

// include para a lib devil
// não esquecer de adicionar a lib (devil.lib) ao projecto
#include <IL/il.h>

#define _USE_MATH_DEFINES
#include <math.h>

#define ANG2RAD 3.14159265358979323846/360.0 

#define COWBOYS 8
#define RAIO_COWBOYS 10
#define INDIOS 16
#define RAIO_INDIOS 25
#define ARVORES 700
#define STEP_COWBOY 1.0f
#define STEP_INDIO 0.5f


float step = 0.0;

float height = 2.0f;
float x = 0.0f;
float z = 0.0f;


float camX = 00, camY = 30, camZ = 40;
int startX, startY, tracking = 0;

int alpha = 0, beta = 45, r = 50;

int imageWidth;
unsigned char *imageData;
unsigned char *relvaTex;
unsigned char *terraTex;

unsigned int tex[2];

unsigned int shadowMapTexture;
unsigned int mFBO;
unsigned int shadowMapSize=4096;

int wHeight;
int wWidth;

MATRIX4X4 lightProjectionMatrix, lightViewMatrix;
MATRIX4X4 cameraProjectionMatrix, cameraViewMatrix;

float pos[4] = {-100, 100, 100, 1};



Esfera *e;
Cone *base;
Cone *copa;
Copo *copo;

int count;
GLuint buffers[2];


void initMatrix(){

	glPushMatrix();
	
	glLoadIdentity();
	gluPerspective(101, 1, 70, 250);
	
	glGetFloatv(GL_MODELVIEW_MATRIX, lightProjectionMatrix);
	
	glLoadIdentity();
	gluLookAt(	pos[0], pos[1], pos[2],
				-65.5f, 0.0f, 65.5f,
				0.0f, 1.0f, 0.0f);
	
	glGetFloatv(GL_MODELVIEW_MATRIX, lightViewMatrix);
	
	glLoadIdentity();
	gluPerspective(45,(float)wWidth/wHeight,1,500);
	glGetFloatv(GL_MODELVIEW_MATRIX, cameraProjectionMatrix);
	
	glLoadIdentity();
	gluLookAt(	camX,camY,camZ,
				0,0,0,
				0.0f, 1.0f, 0.0f);
	glGetFloatv(GL_MODELVIEW_MATRIX, cameraViewMatrix);
	
	glPopMatrix();

}







// função que devolve a altura nos vértices da grelha
float h(int i , int j) {

	return(imageData[i*imageWidth+j] * 0.2f);
}

// função que devolve a altura para pontos no interior das células da grelha
float h2(float x, float z) {


	int x1, x2,z1,z2;
	float xGrid, zGrid;
	float fracX, fracZ, ha, hb;

	xGrid = x + imageWidth/2;
	zGrid = z + imageWidth/2;

	x1 = (int)floor(xGrid);
	x2 = x1 + 1;
	fracX = xGrid - x1;

	z1 = (int)floor(zGrid);
	z2 = z1 + 1;
	fracZ = zGrid - z1;

	ha = h(x2,z1) * fracX + (1-fracX) * h(x1,z1);
	hb = h(x2,z2) * fracX + (1-fracX) * h(x1,z2);

	return(hb * fracZ + (ha * (1-fracZ)));
}

void normal(int i, int j) {

	GLfloat x,y,z;
	float d1 = h(i,j+1)-h(i,j-1);
	float d2 = h(i+1,j)-h(i-1,j);
	x=-2*d2;
	y=4;
	z=-2*d1;
	float norma=sqrt(pow(x,2)+pow(y,2)+pow(z,2));
	x/=norma;
	y/=norma;
	z/=norma;

	// calcular o vector normal (x,y,z) do ponto da grelha com coordenadas (i,j)
	glNormal3f(x,y,z);
}

void changeSize(int w, int h) {

	wHeight=h;
	wWidth=w;

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
	gluPerspective(45,ratio,1,500);

	// return to the model view matrix mode
	glMatrixMode(GL_MODELVIEW);
}




void drawTree() {

	glPushMatrix();
	//glRotatef(-90,1.0,0.0,0.0);
	static float color[] = {1.0,1.0,0.5,1.0};
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,color);
	base->desenhar();
	
	static float color2[] = {0.0, 0.5 + rand() * 0.5f/RAND_MAX,0.0,1.0};
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,color2);

	glTranslatef(0.0,2.0,0.0);
	copa->desenhar();
	glPopMatrix();
}


void placeTrees() {

	float r = 35.0;
	float alpha;
	float rr;
	float x,z;

	srand(31457);
	int arvores = 0;

	while (arvores < ARVORES) {

		rr = rand() * 150.0/ RAND_MAX;
		alpha = rand() * 6.28 / RAND_MAX;

		x = cos(alpha) * (rr + r);
		z = sin(alpha) * (rr + r);

		if (fabs(x) < 100 && fabs(z) < 100) {

			glPushMatrix();
			glTranslatef(x,h2(x,z),z);
			drawTree();
			glPopMatrix();
			arvores++;
		}
	}
}


void drawDonut() {

	glPushMatrix();
	glTranslatef(0.0,0.5,0.0);

	float color[] = {1.0,1.0,1.0,1.0};
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,color);
	float colorS[] = {1.0,1.0,1.0,1.0};
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,colorS);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 100);
	
	//desenhaCilindro();
	glBindTexture(GL_TEXTURE_2D,tex[1]);
	e->desenhar();
	glBindTexture(GL_TEXTURE_2D, 0);


	glPopMatrix();
}


void drawIndios() {

	float angulo;
	float color[] = {1.0,0.0,0.0,1.0};
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,color);
	for (int i = 0; i < INDIOS; i++) {
		
		angulo = i * 360.0/INDIOS + step * STEP_INDIO;
		glPushMatrix();
		glRotatef(angulo,0.0,1.0,0.0);
		glTranslatef(0.0,0.0,RAIO_INDIOS);
		copo->desenhar();
		glPopMatrix();
	}
}


void drawCowboys() {

	float angulo;
	float color[] = {0.0,0.0,1.0,1.0};
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,color);
	for (int i = 0; i < COWBOYS; i++) {
		
		angulo = i * 360.0/COWBOYS + step * STEP_COWBOY;
		glPushMatrix();
		glRotatef(-angulo,0.0,1.0,0.0);
		glTranslatef(RAIO_COWBOYS,0.0,0.0);
		copo->desenhar();
		glPopMatrix();
	}
}


void drawTerreno() {

	
	float color[] = {1, 1, 1, 1};
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,color);
	float spec[]={0.0,0.0,0.0};
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,spec);
	
	glBindTexture(GL_TEXTURE_2D,tex[0]);
	for (int i = 1; i < imageWidth - 2 ; i++) {
		glBegin(GL_TRIANGLE_STRIP);
		for(int j = 1 ; j < imageWidth -1; j++) {
			normal(i+1,j);
			glTexCoord2f(i+1,j);
			glVertex3f(i-imageWidth*0.5f + 1, h(i+1,j), j - imageWidth*0.5f);
			normal(i,j);
			glTexCoord2f(i,j);
			glVertex3f(i-imageWidth*0.5f, h(i,j), j - imageWidth*0.5f);
		}	
		glEnd();
	}
	glBindTexture(GL_TEXTURE_2D, 0);
}


void drawScene() {

	
	placeTrees();
	drawDonut();
	// move teapots up so that they are placed on top of the ground plane
	glPushMatrix();
	glTranslatef(0.0,1.0,0.0);
	drawCowboys();
	drawIndios();
	glPopMatrix();
	drawTerreno();
}



void renderScene(void) {
	initMatrix();

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
	glLightfv(GL_LIGHT1, GL_POSITION, pos);
	glLightfv(GL_LIGHT1, GL_AMBIENT, white*0.2f);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, white*0.2f);
	glLightfv(GL_LIGHT1, GL_SPECULAR, black);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHTING);

	
	
	glEnable(GL_TEXTURE0);
	glActiveTexture(GL_TEXTURE0);
	glEnable(GL_TEXTURE_2D);

	//drawScene();
	
	
	
	//3rd pass
	//Draw with bright light
	glLightfv(GL_LIGHT1, GL_DIFFUSE, white);
	glLightfv(GL_LIGHT1, GL_SPECULAR, white);

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

	drawScene();
	
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

	

	step++;
// End of frame
	glutSwapBuffers();
	
}



void processMouseButtons(int button, int state, int xx, int yy) 
{
	if (state == GLUT_DOWN)  {
		startX = xx;
		startY = yy;
		if (button == GLUT_LEFT_BUTTON)
			tracking = 1;
		else if (button == GLUT_RIGHT_BUTTON)
			tracking = 2;
		else
			tracking = 0;
	}
	else if (state == GLUT_UP) {
		if (tracking == 1) {
			alpha += (xx - startX);
			beta += (yy - startY);
		}
		else if (tracking == 2) {
			
			r -= yy - startY;
			if (r < 3)
				r = 3.0;
		}
		tracking = 0;
	}
}


void processMouseMotion(int xx, int yy)
{

	int deltaX, deltaY;
	int alphaAux, betaAux;
	int rAux;

	if (!tracking)
		return;

	deltaX = xx - startX;
	deltaY = yy - startY;

	if (tracking == 1) {


		alphaAux = alpha - deltaX;
		betaAux = beta + deltaY;

		if (betaAux > 85.0)
			betaAux = 85.0;
		else if (betaAux < -85.0)
			betaAux = -85.0;

		rAux = r;
	}
	else if (tracking == 2) {

		alphaAux = alpha;
		betaAux = beta;
		rAux = r - deltaY;
		if (rAux < 3)
			rAux = 3;
	}
	camX = rAux * sin(alphaAux * 3.14 / 180.0) * cos(betaAux * 3.14 / 180.0);
	camZ = rAux * cos(alphaAux * 3.14 / 180.0) * cos(betaAux * 3.14 / 180.0);
	camY = rAux * 							     sin(betaAux * 3.14 / 180.0);
}


void init() {

	e=new Esfera(3,10,50);
	base=new Cone(0.25,4,1,5,1);
	copa=new Cone(2.0,5.0,1,5,1);
	copo=copo_vinho(2);
	ILuint ima[3];

	ilInit();
	ilGenImages(3,ima);
	ilBindImage(ima[0]);
	ilLoadImage((ILstring)"terreno2.jpg");
	ilConvertImage(IL_LUMINANCE, IL_UNSIGNED_BYTE);

	imageWidth = ilGetInteger(IL_IMAGE_WIDTH);
	imageData = ilGetData();



	ilBindImage(ima[1]);
	ilLoadImage((ILstring)"relva1.jpg");
	ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);
	int relvaw,relvah;
	relvaw=ilGetInteger(IL_IMAGE_WIDTH);
	relvah=ilGetInteger(IL_IMAGE_HEIGHT);
	relvaTex=ilGetData();

	glGenTextures(2,tex); // unsigned int texID - variavel global;
	glBindTexture(GL_TEXTURE_2D,tex[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, relvaw, relvah, 0, GL_RGBA, GL_UNSIGNED_BYTE, relvaTex);

	ilBindImage(ima[2]);
	ilLoadImage((ILstring)"earth_flat_map.jpg");
	ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);
	int terraw, terrah;
	terraw=ilGetInteger(IL_IMAGE_WIDTH);
	terrah=ilGetInteger(IL_IMAGE_HEIGHT);
	terraTex=ilGetData();


	glBindTexture(GL_TEXTURE_2D,tex[1]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, terraw, terrah, 0, GL_RGBA, GL_UNSIGNED_BYTE, terraTex);

	
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
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_FAIL_VALUE_ARB,0.3);
	printf("%d\n",__GLEW_ARB_shadow);
	glTexParameteri(GL_TEXTURE_2D, GL_DEPTH_TEXTURE_MODE_ARB, GL_INTENSITY);
	
	

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

// inicialização da luz
	//glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0);

	//preparaCilindro(5,2,50);
	glBindTexture(GL_TEXTURE_2D,0);
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

	glewInit();

	init();	

// entrar no ciclo do GLUT 
	glutMainLoop();
}

