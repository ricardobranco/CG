#include "Solido.h"
#include <GL/glew.h>
#include <GL/glut.h>
#include <IL/il.h>

Solido::Solido(void)
{
	
}


Solido::~Solido(void)
{
}

void Solido::desenhar(void){

	glBindBuffer(GL_ARRAY_BUFFER,buffers[0]);
	glVertexPointer(3,GL_FLOAT,0,0);
	glBindBuffer(GL_ARRAY_BUFFER,buffers[1]);
	glNormalPointer(GL_FLOAT,0,0);
	
	glDrawElements(GL_TRIANGLES, nvertex ,GL_UNSIGNED_INT, indices);
}
