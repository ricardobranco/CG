#pragma once
class CandeeirosVBO
{
public:
	//constructor vazio
	CandeeirosVBO(void){};
	CandeeirosVBO(float tamanho);
	~CandeeirosVBO(void);
	void Candi1();
	void Candi2();
	void Candi3();
	void Candi4();
	void setSize(float tamanho);
protected:
	float tamanho;
};