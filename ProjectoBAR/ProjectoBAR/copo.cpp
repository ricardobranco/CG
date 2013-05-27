#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include "primitivas.h"
#include "copo.h"

#define DIVH 20

/*
void desenha_copo(float size,float r, float along, float pe, float rbase, float hbase) {

	glPushMatrix();

	glScalef(size,size,size);

	glScalef(1,along,1);

	glTranslatef(0,r+pe,0);
	
	int divh=50;
	int divv=60;

	float incv = M_PI /((float) divv);
	float inch = 2*M_PI /((float) divh);

	glBegin(GL_TRIANGLES);
	float raio1=r;
	float raio2=0.95*r;
	float av=20*incv;
	
	

	for(int iv=20; iv<divv; iv++){

		float ah=0.0f;

		for(int ih=0; ih<divh; ih++){

			glVertex3f(raio1*sin(av)*sin(ah), raio1*cos(av), raio1*sin(av)*cos(ah));
			glVertex3f(raio1*sin(av+incv)*sin(ah), raio1*cos(av+incv), raio1*sin(av+incv)*cos(ah));
			glVertex3f(raio1*sin(av+incv)*sin(ah+inch), raio1*cos(av+incv), raio1*sin(av+incv)*cos(ah+inch));

			glVertex3f(raio1*sin(av)*sin(ah), raio1*cos(av), raio1*sin(av)*cos(ah));
			glVertex3f(raio1*sin(av+incv)*sin(ah+inch), raio1*cos(av+incv), raio1*sin(av+incv)*cos(ah+inch));
			glVertex3f(raio1*sin(av)*sin(ah+inch), raio1*cos(av), raio1*sin(av)*cos(ah+inch));

			ah+=inch;
		}
		av+=incv;
	}
	
	

	float av2=acos((cos(20*incv))/0.95);
	float incv2=(M_PI-av2)/40;
	for(int iv=20; iv<divv; iv++){

		float ah=0.0f;

		for(int ih=0; ih<divh; ih++){

			glVertex3f(raio2*sin(av2)*sin(ah), raio2*cos(av2), raio2*sin(av2)*cos(ah));
			glVertex3f(raio2*sin(av2+incv2)*sin(ah+inch), raio2*cos(av2+incv2), raio2*sin(av2+incv2)*cos(ah+inch));
			glVertex3f(raio2*sin(av2+incv2)*sin(ah), raio2*cos(av2+incv2), raio2*sin(av2+incv2)*cos(ah));

			glVertex3f(raio2*sin(av2)*sin(ah), raio2*cos(av2), raio2*sin(av2)*cos(ah));
			glVertex3f(raio2*sin(av2)*sin(ah+inch), raio2*cos(av2), raio2*sin(av2)*cos(ah+inch));
			glVertex3f(raio2*sin(av2+incv2)*sin(ah+inch), raio2*cos(av2+incv2), raio2*sin(av2+incv2)*cos(ah+inch));

			ah+=inch;
		}
		av2+=incv2;
	}

	

	float y =raio1*cos(incv*20);
	
	float raiob1=raio1*sin(incv*20);
	float raiob2=raio2*sin(acos((cos(20*incv))/0.95));
	
	for(int ih=0;ih<divh;ih++){
		float ah=((float)ih)*inch;

		glVertex3f(raiob1*sin(ah),y,raiob1*cos(ah));
		glVertex3f(raiob2*sin(ah+inch),y,raiob2*cos(ah+inch));
		glVertex3f(raiob2*sin(ah),y,raiob2*cos(ah));

		glVertex3f(raiob1*sin(ah),y,raiob1*cos(ah));
		glVertex3f(raiob1*sin(ah+inch),y,raiob1*cos(ah+inch));
		glVertex3f(raiob2*sin(ah+inch),y,raiob2*cos(ah+inch));

	}

	
	
	

	glEnd();

	glTranslatef(0,-r-pe+(pe+0.05*r)/2,0);
	
	cilindro_solid(pe+0.05*r,0.1,10,50);
	
	glTranslatef(0,-(pe+0.05*r)/2+hbase/2,0);

	cilindro_solid(hbase,rbase,50,3);
	
	glPopMatrix();

	
}
*/

Copo::Copo(float size,float r, float along, float hpe, float rbase, float hbase){


	base=new Cilindro(rbase,hbase,20,1,10);
	pe=new Cilindro(0.1,hpe+0.05*r,5,10,1);

	this->size=size;
	this->raio=r;
	this->along=along;
	this->hpe=hpe;
	this->hbase=hbase;

	copa=new Esfera(r,100,DIVH);
	interior=new Esfera(-0.95*r,100,DIVH);
	
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	int arraySize=2*(DIVH+1)*3*sizeof(float);
	int texSize=2*(DIVH+1)*2*sizeof(float);
	count=DIVH*6;

	float *vertexB=(float*) malloc(arraySize);
	float *normalB=(float*) malloc(arraySize);
	float *textureB=(float*) malloc(texSize);
	indices=(int*) malloc(count*sizeof(int));

	float ang_inc=2*M_PI/DIVH;

	float y= r*cos(33*M_PI/100);

	float raio1=r*sin(33*M_PI/100);
	float raio2=0.95*r*sin(32*M_PI/100);

	float inch=2*M_PI/DIVH;
	
	int i=0;
	int texI=0;
	
	for(int ih=0;ih<=DIVH;ih++){
		float ah=((float)ih)*inch;
		
		vertexB[i]=raio1*sin(ah);
		normalB[i]=0;
		i++;
		
		vertexB[i]=y;
		normalB[i]=1;
		i++;

		vertexB[i]=raio1*cos(ah);
		normalB[i]=0;
		i++;

		textureB[texI]=0.5*sin(ah)+0.5;
		texI++;
		
		textureB[texI]=0.5*cos(ah)+0.5;
		texI++;



		vertexB[i]=raio2*sin(ah);
		normalB[i]=0;
		i++;
		
		vertexB[i]=y;
		normalB[i]=1;
		i++;

		vertexB[i]=raio2*cos(ah);
		normalB[i]=0;
		i++;

		textureB[texI]=0.95*0.5*sin(ah)+0.5;
		texI++;
		
		textureB[texI]=0.95*0.5*cos(ah)+0.5;
		texI++;

	}

	i=0;

	for(int ih=0;ih<DIVH;ih++){
		int c1,c2,c3,c4;
		c1=2*ih;
		c2=2*ih+1;
		c3=2*(ih+1);
		c4=2*(ih+1)+1;

		indices[i]=c1; i++;
		indices[i]=c3; i++;
		indices[i]=c2; i++;
		
		indices[i]=c3; i++;
		indices[i]=c4; i++;
		indices[i]=c2; i++;

	}

	glGenBuffers(3, buffers);
	glBindBuffer(GL_ARRAY_BUFFER,buffers[0]);
	glBufferData(GL_ARRAY_BUFFER, arraySize, vertexB, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER,buffers[1]);
	glBufferData(GL_ARRAY_BUFFER, arraySize, normalB, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER,buffers[2]);
	glBufferData(GL_ARRAY_BUFFER, texSize, textureB, GL_STATIC_DRAW);


	free(vertexB);
	free(normalB);
	free(textureB);


	
}

void Copo::desenhar(){

	static float cor[]={1,1,1,1};


	glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,cor);
	glMaterialfv(GL_FRONT,GL_SPECULAR,cor);
	glMateriali(GL_FRONT,GL_SHININESS,128);

	glPushMatrix();

	glScalef(size,size,size);

	glScalef(1,along,1);

	glTranslatef(0,raio+hpe,0);

	glBindBuffer(GL_ARRAY_BUFFER,copa->buffers[0]);
	glVertexPointer(3,GL_FLOAT,0,0);
	glBindBuffer(GL_ARRAY_BUFFER,copa->buffers[1]);
	glNormalPointer(GL_FLOAT,0,0);
	glBindBuffer(GL_ARRAY_BUFFER,copa->buffers[2]);
	glTexCoordPointer(2,GL_FLOAT,0,0);
	

	glDrawElements(GL_TRIANGLES, copa->count-DIVH*33*6 ,GL_UNSIGNED_INT, copa->indices+DIVH*33*6);
	
	
	
	glBindBuffer(GL_ARRAY_BUFFER,interior->buffers[0]);
	glVertexPointer(3,GL_FLOAT,0,0);
	glBindBuffer(GL_ARRAY_BUFFER,interior->buffers[1]);
	glNormalPointer(GL_FLOAT,0,0);
	glBindBuffer(GL_ARRAY_BUFFER,interior->buffers[2]);
	glTexCoordPointer(2,GL_FLOAT,0,0);

	glDrawElements(GL_TRIANGLES, interior->count-DIVH*32*6 ,GL_UNSIGNED_INT, interior->indices);
	
	
	
	glBindBuffer(GL_ARRAY_BUFFER,buffers[0]);
	glVertexPointer(3,GL_FLOAT,0,0);
	glBindBuffer(GL_ARRAY_BUFFER,buffers[1]);
	glNormalPointer(GL_FLOAT,0,0);
	glBindBuffer(GL_ARRAY_BUFFER,buffers[2]);
	glTexCoordPointer(2,GL_FLOAT,0,0);

	glDrawElements(GL_TRIANGLES, count ,GL_UNSIGNED_INT, indices);



	glTranslatef(0,-raio-hpe+(hpe+0.05*raio)/2,0);
	
	pe->desenhar();
	
	glTranslatef(0,-(hpe+0.05*raio)/2+hbase/2,0);

	base->desenhar();
	
	glPopMatrix();
}




Copo* copo_vinho(float size){

	Copo *c=new Copo(size,1.3,1.4,1,1,0.05);
	return c;

}

Copo* flute(float size){

	Copo *c=new Copo(size,0.7,2.3,0.3,0.6,0.02);
	return c;
}

Copo* copo_largo(float size){

	Copo *c=new Copo(size,3,0.6,5,2,0.1);
	return c;
}