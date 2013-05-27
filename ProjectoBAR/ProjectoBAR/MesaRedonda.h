#pragma once
#include "Cone.h"
#include "Cilindro.h"
class MesaRedonda
{
public:
	MesaRedonda(float alt);
	~MesaRedonda(void);
	void desenhar();
private:
	float altura;
//Extras
	
//figuras
	Cone *con;
	Cilindro *cilAlt;
	Cilindro *cilTampo;
};

