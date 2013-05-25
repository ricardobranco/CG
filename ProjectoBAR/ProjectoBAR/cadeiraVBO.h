#pragma once
class CadeiraVBO
{
public:
	//constructor vazio
	CadeiraVBO(void){};
	CadeiraVBO(float size);
	~CadeiraVBO(void);
	void bancoAlto();
	void bancoBalcao();
	void bancoSofa();
	void sofa1Pessoa();
	void sofa2Pessoa();
	void setSize(float size);
protected:
	float size;
	void banco_alto_parametros(float altura, float raio);
	void banco_balcao_parametros(float altura,float raio);
	void banco_sofa_parametros(float altura,float raio);
	void sofa_parametros(float comp, float larg,float alt);


};