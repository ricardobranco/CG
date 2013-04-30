#pragma once

#include "Plano.h"

class Cubo
{
public:
	Cubo(void){};
	Cubo(float lado, int div);
	~Cubo(void);
	void desenhar();
protected:
	Plano *p;
	float lado;
};

