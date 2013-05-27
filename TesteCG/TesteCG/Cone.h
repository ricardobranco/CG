#pragma once
class Cone
{
public:
	Cone(void){};
	Cone(float raio, float altura, int divh, int divc,int divr);
	~Cone(void);
	void desenhar();
protected:
	unsigned int buffers[3];
	int count;
	int *indices;
};