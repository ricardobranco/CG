#pragma once
#include "Cilindro.h"
#include "Cone.h"
#include "Esfera.h"
class CandeeiroLuz
{
public:
	CandeeiroLuz(float tam);
	~CandeeiroLuz(void);
	void desenhar();
private:
	float raio;
	float raioEsf;
	float altura;
	Cilindro *c1,*c2;
	Cone *cone;
	Esfera *lamp;
};

