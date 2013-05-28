#pragma once
#include"Esfera.h"
#include"Cone.h"
#include"Cubo.h"
#include"Cilindro.h"

class Bilhar
{
public:
	Bilhar(float s);
	void desenhar(int texPernas, int texMesa);
	~Bilhar(void);
private:
	float size;
	Cone *cone;
	Esfera *bola;
	Cubo *cubo;
};

