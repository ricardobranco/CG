#pragma once
#include "Cilindro.h"
#include "Cone.h"

class BancoAlto
{

public:
	BancoAlto(float size);
	~BancoAlto(void);
	void desenhar();
private :
	Cone* cc;
	Cilindro* c1,*c2;
	float altura,raio;

};

