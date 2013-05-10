#pragma once
class Plano
{
public:
	Plano(void){};
	Plano(float ladoX, float ladoZ, int divX, int divZ);
	~Plano(void);
	void desenhar();
protected:
	unsigned int buffers[3];
	int count;
	int *indices;
};

