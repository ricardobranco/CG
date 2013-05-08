#define _USE_MATH_DEFINES
#include "Cone.h"

#include <stdlib.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include <math.h>

Cone::Cone(float raio, float altura, int divh, int divc,int divr){
	float ang,ang_inc,alt,alt_inc,r1,r2,r1_inc,r2_inc;
	ang=0;
	alt=0;
	ang_inc=2* M_PI/(float)divc;
	alt_inc=altura/(float)divh;
	r1=0;
	r2=0;
	r1_inc=raio/(float)divh;
	r2_inc=raio/(float)divr;
	int i=0,j=0;

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);

	count=(divr*1)*(divc+1)*(divh+1);
	int arraySize = (divr+1)*(divc+1)*(divh+1)*sizeof(float);

	float* vertexB= (float*) malloc(arraySize);
	float* normalB= (float*) malloc(arraySize);

	indices=(int*) malloc(count*sizeof(int));
		//lateral
	for (int d = 0; d <=divh; d++)
	{
		alt=d*alt_inc;
		r1=raio-(d*r1_inc);
		for(int f=0;f<=divc;f++){
			ang=f*ang_inc;

			vertexB[i]=r1*sin(ang);
			normalB[i]=sin(ang);
			i++;
			vertexB[i]=alt;
			normalB[i]=0;
			i++;
			vertexB[i]=r1*cos(ang);
			normalB[i]=cos(ang);
			i++;

		}
	}

		for(int ih=0; ih<divh;ih++){

			for(int iv=0; iv<divc;iv++){

			int c1,c2,c3,c4;
			c1=(divc+1)*(ih)+iv;
			c2=(divc+1)*(ih)+iv+1;
			c3=(divc+1)*(ih+1)+iv+1;
			c4=(divc+1)*(ih+1)+iv;

			indices[j]=c1; j++;
			indices[j]=c2; j++;
			indices[j]=c3; j++;
			indices[j]=c3; j++;
			indices[j]=c4; j++;
			indices[j]=c1; j++;

		}

	}
		//base
			for(int r=0;r<=divr;r++){
				r2=r2_inc*r;

			for (int d = 0; d<=divc; d++)
			{
				ang=d*ang_inc;
				vertexB[i]=r2*sin(ang);
				normalB[i]=0;
				i++;
				vertexB[i]=0;
				normalB[i]=-1;
				i++;
				vertexB[i]=r2*cos(ang);
				normalB[i]=0;
				i++;
			}
			}

			int b1= (divc+1)*(divh+1);
			for(int r=0;r<divr;r++){

			for (int d= 0; d <divc; d++)
			{
				int c1,c2,c3,c4;
				c1=((divc+1)*(r+1)+d+1)+b1;
				c2=((divc+1)*(r)+d+1)+b1;
				c3=((divc+1)*(r)+d)+b1;
				c4=((divc+1)*(r+1)+d)+b1;

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

Cone::~Cone(void)
{
}


void Cone::desenhar(){
		
	glBindBuffer(GL_ARRAY_BUFFER,buffers[0]);
	glVertexPointer(3,GL_FLOAT,0,0);
	glBindBuffer(GL_ARRAY_BUFFER,buffers[1]);
	glNormalPointer(GL_FLOAT,0,0);

	glDrawElements(GL_TRIANGLES, count ,GL_UNSIGNED_INT,indices);

}