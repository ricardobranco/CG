#pragma once
#include "Cilindro.h"
#include "Esfera.h"
class BancoSofa
{
public:
	BancoSofa(float size);
	~BancoSofa(void);
	void desenhar();
private:
	float altura, raio;
	Cilindro *c1,*c2,*c3;
	Esfera*e;
};

