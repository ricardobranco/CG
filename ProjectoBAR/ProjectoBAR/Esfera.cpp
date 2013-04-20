#include "Esfera.h"

#define _USE_MATH_DEFINES

#include <stdlib.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include <math.h>

Esfera::Esfera(float raio, int divv, int divh)
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	
	count=6*divv*divh;
	int arraySize = 3*(divv+1)*divh*sizeof(float);
	int i=0;


	float* vertexB= (float*) malloc(arraySize);
	float* normalB= (float*) malloc(arraySize);
	indices=(int*) malloc(count*sizeof(int));

	float angv, angh;
	float inch=2*M_PI/divh;
	float incv=M_PI/divv;

	for(int ih=0; ih<divh;ih++){
		angh=inch*ih;

		for(int iv=0; iv<=divv;iv++){
			angv=incv*iv;

			vertexB[i]=raio*sin(angv)*sin(angh);
			normalB[i]=sin(angv)*sin(angh);
			i++;

			vertexB[i]=raio*cos(angv);
			normalB[i]=cos(angv);
			i++;

			vertexB[i]=raio*sin(angv)*cos(angh);
			normalB[i]=sin(angv)*cos(angh);
			i++;

		}

	}

	i=0;

	for(int ih=0; ih<divh;ih++){

		for(int iv=0; iv<divv;iv++){

			int c1,c2,c3,c4;
			c1=(divv+1)*((ih)%divh)+iv;
			c2=(divv+1)*((ih)%divh)+iv+1;
			c3=(divv+1)*((ih+1)%divh)+iv;
			c4=(divv+1)*((ih+1)%divh)+iv+1;

			indices[i]=c1; i++;
			indices[i]=c2; i++;
			indices[i]=c3; i++;
			indices[i]=c2; i++;
			indices[i]=c4; i++;
			indices[i]=c3; i++;

		}

	}

	glGenBuffers(2, buffers);
	glBindBuffer(GL_ARRAY_BUFFER,buffers[0]);
	glBufferData(GL_ARRAY_BUFFER, arraySize, vertexB, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER,buffers[1]);
	glBufferData(GL_ARRAY_BUFFER, arraySize, normalB, GL_STATIC_DRAW);

	free(vertexB);
	free(normalB);

}


Esfera::~Esfera(void)
{
}


void Esfera::desenhar(){
	
	glBindBuffer(GL_ARRAY_BUFFER,buffers[0]);
	glVertexPointer(3,GL_FLOAT,0,0);
	glBindBuffer(GL_ARRAY_BUFFER,buffers[1]);
	glNormalPointer(GL_FLOAT,0,0);

	glDrawElements(GL_TRIANGLES, count ,GL_UNSIGNED_INT, indices);
}