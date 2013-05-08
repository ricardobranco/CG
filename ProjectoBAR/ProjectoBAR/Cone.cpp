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

	float arraySize=3*(divh+1)*(div+1)+3*(div+1)*(divr+1);
	float *vertexC=(float*)malloc(arraySize*sizeof(float));
	float* normalB= (float*) malloc(arraySize*sizeof(float));
	float alf=0.0,dalf=(2*M_PI)/(float)div;
	float draio=raio/(float)divh;
	float r1,r2=0;
	float r2_inc=raio/(float)divr;
	float h=0,dh=altura/(float)divh;
	//incremento no array
	int iv=0;
	int nj=0;
	count=6*(div)*(divh)+6*(divr)*div;
	//falta o valor
	indices=(int*)malloc(count*sizeof(int));

	for(int i=0;i<=divh;i++)
	{
		r1=raio-(i*draio);
		h=i*dh;
		

		for(int j=0;j<=div;j++)
		{ 
			alf=j*dalf;

			vertexC[iv]=r1*sin(alf);
			normalB[iv]=sin(alf);
			iv++;
			vertexC[iv]=h;
			normalB[iv]=0;
			iv++;
			vertexC[iv]=r1*cos(alf);
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
	//base inferior
			for(int r=0;r<=divr;r++){
				r2=r2_inc*r;

			for (int d = 0; d<=div; d++)
			{
				alf=d*dalf;
				vertexC[iv]=r2*sin(alf);
				normalB[iv]=0;
				iv++;
				vertexC[iv]=0;
				normalB[iv]=-1;
				iv++;
				vertexC[iv]=r2*cos(alf);
				normalB[iv]=0;
				iv++;

			}
			}

			int b2= (divh+1)*(div+1);
			for(int r=0;r<divr;r++){

			for (int d= 0; d <div; d++)
			{
				int c1,c2,c3,c4;
				c1=((div+1)*(r+1)+d+1)+b2;
				c2=((div+1)*(r)+d+1)+b2;
				c3=((div+1)*(r)+d)+b2;
				c4=((div+1)*(r+1)+d)+b2;

				indices[nj]=c3;	nj++;
				indices[nj]=c2;	nj++;
				indices[nj]=c1;	nj++;
				indices[nj]=c1;	nj++;
				indices[nj]=c4;	nj++;
				indices[nj]=c3;	nj++;
				
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
