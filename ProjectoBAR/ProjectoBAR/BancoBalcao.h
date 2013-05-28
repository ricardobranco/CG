#pragma once
#include "Cilindro.h"
class BancoBalcao
{
public:
	BancoBalcao(float size );
	~BancoBalcao(void);
	void desenhar(int texture);
private:
	float raio;
	float altura;
	Cilindro *c1;
	Cilindro *c2;
	Cilindro *c3;

};

