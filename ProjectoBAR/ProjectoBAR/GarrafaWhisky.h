#pragma once
#include "Cilindro.h"
#include "Cubo.h"
class GarrafaWhisky
{
public:
	GarrafaWhisky(float tam);
	~GarrafaWhisky(void);
	void desenhar();
private:
	float comprimento;
	float altura;
	float largura;
	float tamanho;
	Cilindro *c1;
	Cubo *cubo;
};

