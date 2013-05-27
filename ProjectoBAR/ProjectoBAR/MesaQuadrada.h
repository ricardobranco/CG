#pragma once
#include "Cubo.h"
class MesaQuadrada
{
public:
	MesaQuadrada(float ms, float alt);
	~MesaQuadrada(void);
	void desenhar();
private:
	float mesa;
	float altura;
//Extra
	float meiaMesa;
	
//Figuras
	Cubo *cPernas; 
	Cubo *cTampo
		;
};

