#pragma once
class Cilindro
{
public:
	Cilindro(void){};
	Cilindro(float raio, float altura, int div, int fat,int divr);
	~Cilindro(void);
	void desenhar();
protected:
	unsigned int buffers[3];
	int count;
	int *indices;
};