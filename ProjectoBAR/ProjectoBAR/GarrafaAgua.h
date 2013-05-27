#pragma once
#include "Cilindro.h"
#include"Esfera.h"
class GarrafaAgua
{
public:
	GarrafaAgua(float alt);
	~GarrafaAgua(void);
	void desenhar();
private:
	float raio;
	float altura;
	Cilindro *c1,*c2;
	Esfera *e;
};

