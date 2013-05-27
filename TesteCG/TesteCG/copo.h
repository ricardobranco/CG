#ifndef _COPO
#define _COPO

#include "Cilindro.h"
#include "Esfera.h"


class Copo{
public:
	Copo(){};
	Copo(float size,float r, float along, float hpe, float rbase, float hbase);
	~Copo();
	void desenhar();
private:

	Cilindro *pe;
	Cilindro *base;
	Esfera *copa;
	Esfera *interior;

	float size;
	float raio;
	float along;
	float hpe;
	float hbase;

	unsigned int buffers[3];
	int count;
	int *indices;

};


Copo * copo_vinho(float size);
Copo * flute(float size);
Copo * copo_largo(float size);




#endif


