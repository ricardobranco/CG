#pragma once
class Extras
{
public:
	//constructor vazio
	Extras(void){};
	Extras(float size);
	~Extras(void);
	void bilhar();
	void boB();
	void setSize(float size);
protected:
	float size;
	void bilharPar(float comp, float alt, float larg);


};