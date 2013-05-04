#define _USE_MATH_DEFINES
#include "Cilindro.h"

#include <stdlib.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include <math.h>

Cilindro::Cilindro(float raio, float altura, int divf, int divc){
	float ang,ang_inc,alt,alt_inc;
	ang=0;
	ang_inc=2*M_PI/divc;
	alt=alt/2;
	alt_inc=altura/divf;
	int i=0;

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);

	count=20*divf*divc;
	int arraySize = 20*(divf+1)*(divc+1)*sizeof(float);

	float* vertexB= (float*) malloc(arraySize);
	float* normalB= (float*) malloc(arraySize);

	indices=(int*) malloc(count*sizeof(int));

	for(int bi=0;bi<divc;bi++,ang=ang+ang_inc){
		vertexB[i]=cos(ang)*raio;
		normalB[i]=0;
		i++;
		vertexB[i]=-alt;
		normalB[i]=-1;
		i++;
		vertexB[i]=-sin(ang)*raio;
		normalB[i]=0;
		i++;
	}

	for(int bi=0;bi<divc;bi++,ang=ang+ang_inc){
		vertexB[i]=cos(ang)*raio;
		normalB[i]=0;
		i++;
		vertexB[i]=alt;
		normalB[i]=1;
		i++;
		vertexB[i]=sin(ang)*raio;
		normalB[i]=0;
		i++;
	}

	for (int f = 0; f < divf; f++)
	{
		ang=0;
		alt=alt-alt_inc*f;
		for (int fi = 0; fi < divc; fi++,ang=ang+ang_inc)
		{
			vertexB[i]=cos(ang)*raio;
			normalB[i]=0;
			i++;
			vertexB[i]=alt-alt_inc;
			normalB[i]=0;
			i++;
			vertexB[i]=sin(ang);
			normalB[i]=0;
			i++;
		}
	}
		i=0;

	for(int ih=0; ih<divc;ih++){

		for(int iv=0; iv<divf;iv++){

			int c1,c2,c3,c4;
			c1=(divf+1)*((ih)%divc)+iv;
			c2=(divf+1)*((ih)%divc)+iv+1;
			c3=(divf+1)*((ih+1)%(divc+1))+iv;
			c4=(divf+1)*((ih+1)%(divc+1))+iv+1;
			
			indices[i]=c1; i++;
			indices[i]=c3; i++;
			indices[i]=c2; i++;
			
			indices[i]=c3; i++;
			indices[i]=c4; i++;
			indices[i]=c2; i++;

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

Cilindro::~Cilindro(void)
{
}


void Cilindro::desenhar(){
		
	glBindBuffer(GL_ARRAY_BUFFER,buffers[0]);
	glVertexPointer(3,GL_FLOAT,0,0);
	glBindBuffer(GL_ARRAY_BUFFER,buffers[1]);
	glNormalPointer(GL_FLOAT,0,0);

	glDrawElements(GL_TRIANGLES, count ,GL_UNSIGNED_INT, indices);

}

