#include "Plano.h"

#include <stdlib.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include <math.h>


Plano::Plano(float ladoX, float ladoZ, int divX, int divZ){
	
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	
	count=6*divX*divZ;
	int arraySize = 3*(divX+1)*(divZ+1)*sizeof(float);
	float* vertexB= (float*) malloc(arraySize);
	float* normalB= (float*) malloc(arraySize);
	float* texturaB = (float*) malloc(arraySize);

	indices=(int*) malloc(count*sizeof(int));
	int i = 0;
	int texI = 0;

	float divladoX = ladoX/divX;
	float divladoZ = ladoZ/divZ;
	
	float y = 0;
	float z = -ladoZ/2;
	float x= -ladoX/2;

	float incTextS = 1/(float)divZ;
	float incTextT = 1/(float)divX;



	for(int iv=0; iv<=divZ; iv++){
		 
		z=-ladoZ/2+iv*divladoZ;
		
		for(int ih=0; ih<=divX; ih++){
			
			x=-ladoX/2+ih*divladoX;

			vertexB[i]=x;
			normalB[i]=0;
			i++;
			vertexB[i]=y;
			normalB[i]=1;
			i++;
			vertexB[i]=z; 
			normalB[i]=0;
			i++;
			
			texturaB[texI] = ih * incTextT; texI++;
			texturaB[texI] = 1-iv * incTextS; texI++;
			
		}
		
	} 

	i=0;


	for(int iv=0; iv<divZ;iv++){
	
		
		for(int ih=0; ih<divX;ih++){

			int c1,c2,c3,c4;
			c1=(divX+1)*(iv)+ih;
			c2=(divX+1)*(iv)+ih+1;
			c3=(divX+1)*((iv+1))+ih;
			c4=(divX+1)*((iv+1))+ih+1;
			
			indices[i]=c1; i++;
			indices[i]=c3; i++;
			indices[i]=c2; i++;
			
			indices[i]=c3; i++;
			indices[i]=c4; i++;
			indices[i]=c2; i++;

		}

	}





	glGenBuffers(3, buffers);
	glBindBuffer(GL_ARRAY_BUFFER,buffers[0]);
	glBufferData(GL_ARRAY_BUFFER, arraySize, vertexB, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER,buffers[1]);
	glBufferData(GL_ARRAY_BUFFER, arraySize, normalB, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER,buffers[2]);
	glBufferData(GL_ARRAY_BUFFER,arraySize,texturaB,GL_STATIC_DRAW);

	free(vertexB);
	free(normalB);
	free(texturaB);
	
}


Plano::~Plano(void)
{
}


void Plano::desenhar(){
	
	glBindBuffer(GL_ARRAY_BUFFER,buffers[0]);
	glVertexPointer(3,GL_FLOAT,0,0);
	glBindBuffer(GL_ARRAY_BUFFER,buffers[1]);
	glNormalPointer(GL_FLOAT,0,0);
	glBindBuffer(GL_ARRAY_BUFFER,buffers[2]);
	glTexCoordPointer(2,GL_FLOAT,0,0);


	glDrawElements(GL_TRIANGLES, count ,GL_UNSIGNED_INT, indices);
}