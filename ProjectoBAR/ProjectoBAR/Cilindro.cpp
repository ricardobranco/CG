#define _USE_MATH_DEFINES
#include "Cilindro.h"

#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include <math.h>

Cilindro::Cilindro(float raio, float altura, int div, int fat,int divr){
	float ang,ang_inc,alt,alt_inc,raio_inc,rd;
	ang=0;
	ang_inc=2*M_PI/(float)div;
	alt=0;
	rd=0;
	alt_inc=altura/(float)fat;
	raio_inc=raio/(float)divr;
	int i=0,j=0;

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);

	count=(divr*1)*(div+1)*(fat+1);
	int arraySize = (divr+1)*(fat+1)*(div+1)*sizeof(float);

	float* vertexB= (float*) malloc(arraySize);
	float* normalB= (float*) malloc(arraySize);

	indices=(int*) malloc(count*sizeof(int));
		//lateral
	for (int d = 0; d <=div; d++)
	{
		ang=d*ang_inc;
		for(int f=0;f<=fat;f++){
			alt=altura/2-(f*alt_inc);

			vertexB[i]=raio*sin(ang);
			normalB[i]=sin(ang);
			i++;
			vertexB[i]=alt;
			normalB[i]=0;
			i++;
			vertexB[i]=raio*cos(ang);
			normalB[i]=cos(ang);
			i++;

		}
	}

		for(int ih=0; ih<div;ih++){

			for(int iv=0; iv<fat;iv++){

			int c1,c2,c3,c4;
			c1=(fat+1)*(ih)+iv;
			c2=(fat+1)*(ih)+iv+1;
			c3=(fat+1)*(ih+1)+iv+1;
			c4=(fat+1)*(ih+1)+iv;

			indices[j]=c1; j++;
			indices[j]=c2; j++;
			indices[j]=c3; j++;
			indices[j]=c3; j++;
			indices[j]=c4; j++;
			indices[j]=c1; j++;

		}

	}
		//base superior
			for(int r=0;r<=divr;r++){
				rd=raio_inc*r;

			for (int d = 0; d<=div; d++)
			{
				ang=d*ang_inc;
				vertexB[i]=rd*sin(ang);
				normalB[i]=0;
				i++;
				vertexB[i]=altura/2;
				normalB[i]=1;
				i++;
				vertexB[i]=rd*cos(ang);
				normalB[i]=0;
				i++;
			}
			}

			int b1= (fat+1)*(div+1);
			for(int r=0;r<divr;r++){

			for (int d= 0; d <div; d++)
			{
				int c1,c2,c3,c4;
				c1=((div+1)*(r+1)+d+1)+b1;
				c2=((div+1)*(r)+d+1)+b1;
				c3=((div+1)*(r)+d)+b1;
				c4=((div+1)*(r+1)+d)+b1;

				indices[j]=c1;	j++;
				indices[j]=c2;	j++;
				indices[j]=c3;	j++;
				indices[j]=c1;	j++;
				indices[j]=c3;	j++;
				indices[j]=c4;	j++;
				
			}
			}

			//base inferior
			for(int r=0;r<=divr;r++){
				rd=raio_inc*r;

			for (int d = 0; d<=div; d++)
			{
				ang=d*ang_inc;
				vertexB[i]=rd*sin(ang);
				normalB[i]=0;
				i++;
				vertexB[i]=-altura/2;
				normalB[i]=-1;
				i++;
				vertexB[i]=rd*cos(ang);
				normalB[i]=0;
				i++;
			}
			}

			int b2= b1+(div+1)*(divr+1);
			for(int r=0;r<divr;r++){

			for (int d= 0; d <div; d++)
			{
				int c1,c2,c3,c4;
				c1=((div+1)*(r+1)+d+1)+b2;
				c2=((div+1)*(r)+d+1)+b2;
				c3=((div+1)*(r)+d)+b2;
				c4=((div+1)*(r+1)+d)+b2;

				indices[j]=c3;	j++;
				indices[j]=c2;	j++;
				indices[j]=c1;	j++;
				indices[j]=c1;	j++;
				indices[j]=c4;	j++;
				indices[j]=c3;	j++;
				
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

	glDrawElements(GL_TRIANGLES, count ,GL_UNSIGNED_INT,indices);

}

