#pragma once
#include "Esfera.h"
#include "Cone.h"
#include "Cilindro.h"
class CandeeiroBilhar
{
public:
	CandeeiroBilhar(float comp,float tam);
	~CandeeiroBilhar(void);
	void desenhar();
private:
	float raio;
	float altura;
	float raioCil;
	float comprimento;
	Esfera *lamp;
	Cone *cone;
	Cilindro *cil,*cil2;
};

