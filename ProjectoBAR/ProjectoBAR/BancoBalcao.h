#pragma once
#include "Cilindro.h"
class BancoBalcao
{
public:
	BancoBalcao(float r, float alt);
	~BancoBalcao(void);
	void desenhar();
private:
	float raio;
	float altura;
	Cilindro *c1;
	Cilindro *c2;
	Cilindro *c3;

};

