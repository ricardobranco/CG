#pragma once

class Solido
{
public:
	Solido(void);
	~Solido(void);
	void desenhar();
protected: 
	unsigned int buffers[2];
	int nvertex;
	int *indices;

};

