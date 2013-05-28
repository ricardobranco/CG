#pragma once

#include"Cubo.h"
class Balcao
{
public:
	Balcao(float comp,float alt,float larg);
	~Balcao(void);
	void desenhar(int tampo_tex, int base_tex);
private:
	float comprimento;
	float altura;
	float largura;
	float espComp;
	float espLarg;
	Cubo *cubo;
};

