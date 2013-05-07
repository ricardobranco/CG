#define _USE_MATH_DEFINES
#include "Cone.h"

#include <stdlib.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include <math.h>

Cone::Cone(float raio,float altura,float div,float divh,float divr)
{

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	float csize=3*4*div*divh;
	float *vertexC=(float*)malloc(csize*sizeof(float));
	float* normalB= (float*) malloc(csize*sizeof(float));
	float alf=0.0,dalf=(2*M_PI)/div;
	float draio=raio/divh;
	float h=0,dh=altura/divh;
	//incremento no array
	int iv=0;
	int nj=0;
	count=csize;
	//falta o valor
	indices=(int*)malloc(count*sizeof(int));

	for(int idivh=0;idivh<divh;idivh++)
	{
		raio-=(draio);

		alf=idivh*dalf;

		for(int idiv=0;idiv<div;idiv++)
		{ 
			h=altura/2-(idiv*dh);
			vertexC[iv]=raio*sin(alf);
			normalB[iv]=sin(alf);
			iv++;
			vertexC[iv]=h;
			normalB[iv]=0;
			iv++;
			vertexC[iv]=raio*cos(alf);
			normalB[iv]=cos(alf);
			iv++;
		}
	
	}


	for(int ih=0; ih<divh;ih++){

			for(int iv=0; iv<div;iv++){

				//Entender estes c1/c2/c3/c4
			int c1,c2,c3,c4;
			c1=(div+1)*(ih)+iv;
			c2=(div+1)*(ih)+iv+1;
			c3=(div+1)*(ih+1)+iv+1;
			c4=(div+1)*(ih+1)+iv;

			indices[nj]=c1; nj++;
			indices[nj]=c2; nj++;
			indices[nj]=c3; nj++;
			indices[nj]=c3; nj++;
			indices[nj]=c4; nj++;
			indices[nj]=c1; nj++;

			}
	}


	glGenBuffers(2, buffers);
	glBindBuffer(GL_ARRAY_BUFFER,buffers[0]);
	glBufferData(GL_ARRAY_BUFFER,count,vertexC, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER,buffers[1]);
	glBufferData(GL_ARRAY_BUFFER,count,normalB, GL_STATIC_DRAW);


	free(vertexC);
	free(normalB);
	

}


Cone::~Cone()
{
}




void Cone::desenhar(){
		
	glBindBuffer(GL_ARRAY_BUFFER,buffers[0]);
	glVertexPointer(3,GL_FLOAT,0,0);
	glBindBuffer(GL_ARRAY_BUFFER,buffers[1]);
	glNormalPointer(GL_FLOAT,0,0);

	glDrawElements(GL_TRIANGLES, count ,GL_UNSIGNED_INT,indices);
}
