#pragma once
class Esfera
{
public:
	Esfera(void){};
	Esfera(float raio, int divv, int divh);
	~Esfera(void);
	void desenhar();
protected:
	unsigned int buffers[3];
	int count;
	int *indices;
	
	
	friend class Copo;
};

