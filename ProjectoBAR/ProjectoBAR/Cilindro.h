#pragma once
class Cilindro
{
public:
	Cilindro(void){};
	Cilindro(float raio, float altura, int divh, int divc);
	~Cilindro(void);
	void desenhar();
protected:
	unsigned int buffers[2];
	int count;
	int *indices;
};