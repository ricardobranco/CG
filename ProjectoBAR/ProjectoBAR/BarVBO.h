#pragma once
#include "Plano.h"
class BarVBO
{
public:
	//constructor vazio
	BarVBO(void){};
	BarVBO(float size,float altura,float comp,float larg);
	void desenhar(int chao_tex, int paredes_tex,int tecto_tex);
	~BarVBO(void);

private:
	float size;
	float altura;
	float comp;
	float larg;
	
	//PLANOS PARA O CHAO
	Plano *chaoDIR;
	Plano *chaoESQ;
	Plano *chaoTOP; 

	//PLANOS PARA A PAREDE
	Plano *parESQTOP;
	Plano *parSULDIR;
	Plano *parTOP;
	Plano *parDIR;
	Plano *parDIAG; 

	//PLANOS PARA O TECTO
	Plano *tecDIR;
	Plano *tecESQ;
	Plano *tecTOP; 
	void setSize(float size);


	float cateto;
	float dir;
	float sul;
	float hipotnusa;
	float aux;


};

BarVBO *Bar(float size);