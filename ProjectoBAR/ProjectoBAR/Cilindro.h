#pragma once
class Cilindro
{
public:
	Cilindro(void){};
	Cilindro(float raio, float altura, int div, int fat,int divr);
	~Cilindro(void);
	void desenhar();
protected:
	unsigned int buffers[2];
	int count;
	int count2;
	int *indices;
	int *indices2;
	int *indices3;
};