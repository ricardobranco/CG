#pragma once
#include"Cilindro.h"
#include"Cubo.h"
class Sofa
{
public:
	Sofa(float size,int nlugares);
	void desenhar();
	~Sofa(void);
private:
	Cilindro *c1,*c2;
	Cubo *cub1,*cub2;
	float comp,alt,larg;
};

