#pragma once
#include "solido.h"
class Esfera :
	public Solido
{
public:
	Esfera(){Esfera(1,45,90);};
	Esfera(float raio, int divv, int divh);
	~Esfera(void);
};

