#pragma once
class Cone
{
public:
	Cone(void){};
	Cone (float raio,float altura,float div,float divh,float divr);
	~Cone(void);
	void desenhar();
protected:
	unsigned int buffers[2];
	int count;
	int *indices;
};