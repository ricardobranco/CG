#pragma once
class BarVBO
{
public:
	//constructor vazio
	BarVBO(void){};
	BarVBO(float size);
	void Parede();
	void Chao();
	void Tecto();
	~BarVBO(void);
protected:
	float size;
	void setSize(float size);
	void Parede_params(float comp,float larg,float altura);
	void Chao_params(float comp,float larg);
	void Tecto_params(float comp,float larg,float altura);
};