#define _USE_MATH_DEFINES

#include "primitivas.h"
#include <GL/glut.h>
#include <math.h>


/// <summary>
/// Desenha uma esfera solida centrada na origem.
/// </summary>
/// <param name="raio">O raio da esfera a criar.</param>
/// <param name="divv">Quantas divisões verticais tem a esfera (numero de paralelos do globo).</param>
/// <param name="divh">Quantas divisões verricais tem a esfera (numero de meridianos do globo).</param>
void esfera_solid(float raio, int divv, int divh){

	float incv = M_PI /((float) divv);
	float inch = 2*M_PI /((float) divh);
	
	glBegin(GL_TRIANGLES);

	float av=0.0f;

	for(int iv=0; iv<divv; iv++){
		
		float ah=0.0f;

		for(int ih=0; ih<divh; ih++){
			
			
			
			glVertex3f(raio*sin(av)*cos(ah), raio*cos(av), raio*sin(av)*sin(ah));
			glVertex3f(raio*sin(av+incv)*cos(ah), raio*cos(av+incv), raio*sin(av+incv)*sin(ah));
			glVertex3f(raio*sin(av+incv)*cos(ah+inch), raio*cos(av+incv), raio*sin(av+incv)*sin(ah+inch));
			
			glVertex3f(raio*sin(av)*cos(ah), raio*cos(av), raio*sin(av)*sin(ah));
			glVertex3f(raio*sin(av+incv)*cos(ah+inch), raio*cos(av+incv), raio*sin(av+incv)*sin(ah+inch));
			glVertex3f(raio*sin(av)*cos(ah+inch), raio*cos(av), raio*sin(av)*sin(ah+inch));
				
			ah+=inch;
		}
		av+=incv;
	}

	glEnd();
}


/// <summary>
/// Desenha uma esfera em linhas centrada na origem.
/// </summary>
/// <param name="raio">O raio da esfera a criar.</param>
/// <param name="divv">Quantas divisões verticais tem a esfera (numero de paralelos do globo).</param>
/// <param name="divh">Quantas divisões verricais tem a esfera (numero de meridianos do globo).</param>
void esfera_wire(float raio, int divv, int divh){

	float incv = M_PI /((float) divv);
	float inch = 2*M_PI /((float) divh);
	
	glBegin(GL_LINES);
	
	float av=0.0f;
	
	for(int iv=0; iv<divv; iv++){
		
		float ah=0.0f;
		
		for(int ih=0; ih<divh; ih++){
			
			
			
			glVertex3f(raio*sin(av)*cos(ah), raio*cos(av), raio*sin(av)*sin(ah));
			glVertex3f(raio*sin(av+incv)*cos(ah), raio*cos(av+incv), raio*sin(av+incv)*sin(ah));
			glVertex3f(raio*sin(av+incv)*cos(ah), raio*cos(av+incv), raio*sin(av+incv)*sin(ah));
			glVertex3f(raio*sin(av+incv)*cos(ah+inch), raio*cos(av+incv), raio*sin(av+incv)*sin(ah+inch));

			ah+=inch;
		}
		av+=incv;
	}

	glEnd();
}



/// <summary>
/// Desenha um cilindro solido centrado na origem.
/// </summary>
/// <param name="altura">A altura do cilindro.</param>
/// <param name="raio">O raio da base.</param>
/// <param name="div">O numero de subdivisões.</param>
void cilindro_solid(float altura, float raio, int div){

	float ang=0.0f;
	float ang_inc=2*M_PI/((float)div);
	glBegin(GL_TRIANGLES);
	for(int i=0; i<div;i++){

		

			glVertex3f(0.0,altura/2.0f, 0.0);
			glVertex3f(raio*sin(ang),altura/2.0f, raio*cos(ang));
			glVertex3f(raio*sin(ang+ang_inc),altura/2.0f, raio*cos(ang+ang_inc));

			glVertex3f(0.0,-altura/2.0f, 0.0);
			glVertex3f(raio*sin(ang+ang_inc),-altura/2.0f, raio*cos(ang+ang_inc));
			glVertex3f(raio*sin(ang),-altura/2.0f, raio*cos(ang));
			

			
			glVertex3f(raio*sin(ang),altura/2.0f, raio*cos(ang));
			glVertex3f(raio*sin(ang),-altura/2.0f, raio*cos(ang));
			glVertex3f(raio*sin(ang+ang_inc),-altura/2.0f, raio*cos(ang+ang_inc));
			
			glVertex3f(raio*sin(ang),altura/2.0f, raio*cos(ang));
			glVertex3f(raio*sin(ang+ang_inc),-altura/2.0f, raio*cos(ang+ang_inc));
			glVertex3f(raio*sin(ang+ang_inc),altura/2.0f, raio*cos(ang+ang_inc));

		

		ang+=ang_inc;

	}
	glEnd();
}


/// <summary>
/// Desenha um cilindro com linhas centrado na origem.
/// </summary>
/// <param name="altura">A altura do cilindro.</param>
/// <param name="raio">O raio da base.</param>
/// <param name="div">O numero de subdivisões.</param>
void cilindro_wire(float altura, float raio, int div){

	float ang=0.0f;
	float ang_inc=2*M_PI/((float)div);

	glBegin(GL_LINES);

	for(int i=0; i<div;i++){

		

			glVertex3f(0.0,altura/2.0f, 0.0);
			glVertex3f(raio*sin(ang),altura/2.0f, raio*cos(ang));
			
			glVertex3f(raio*sin(ang),altura/2.0f, raio*cos(ang));
			glVertex3f(raio*sin(ang+ang_inc),altura/2.0f, raio*cos(ang+ang_inc));

			glVertex3f(0.0,-altura/2.0f, 0.0);
			glVertex3f(raio*sin(ang),-altura/2.0f, raio*cos(ang));
			
			glVertex3f(raio*sin(ang),-altura/2.0f, raio*cos(ang));
			glVertex3f(raio*sin(ang+ang_inc),-altura/2.0f, raio*cos(ang+ang_inc));
			
			glVertex3f(raio*sin(ang),altura/2.0f, raio*cos(ang));
			glVertex3f(raio*sin(ang),-altura/2.0f, raio*cos(ang));
		
		ang+=ang_inc;

	}

	glEnd();
}


/// <summary>
/// Desenha um cone solido sobre o plano xOz, centrado no eixo dos yy.
/// </summary>
/// <param name="altura">A altura do cone.</param>
/// <param name="raio">O raio da base.</param>
/// <param name="div">O numero de divisões. </param>
void cone_solid(float altura, float raio, int div){

	float ang=0.0f;
	float ang_inc=2*M_PI/((float) div);
	
	glBegin(GL_TRIANGLES);
	
	for(int i=0; i<div;i++){

		glVertex3f(0.0f, altura, 0.0f);
		glVertex3f(raio*sin(ang),0.0f,raio*cos(ang));
		glVertex3f(raio*sin(ang+ang_inc),0.0f,raio*cos(ang+ang_inc));

		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(raio*sin(ang+ang_inc),0.0f,raio*cos(ang+ang_inc));
		glVertex3f(raio*sin(ang),0.0f,raio*cos(ang));
		
		ang+=ang_inc;
	}
	glEnd();
}


/// <summary>
/// Desenha um cone em linhas sobre o plano xOz, centrado no eixo dos yy.
/// </summary>
/// <param name="altura">A altura do cone.</param>
/// <param name="raio">O raio da base.</param>
/// <param name="div">O numero de divisões. </param>
void cone_wire(float altura, float raio, int div){

	float ang=0.0f;
	float ang_inc=2*M_PI/((float) div);
	
	glBegin(GL_LINES);
	
	for(int i=0; i<div;i++){

		glVertex3f(0.0f, altura, 0.0f);
		glVertex3f(raio*sin(ang),0.0f,raio*cos(ang));

		glVertex3f(raio*sin(ang),0.0f,raio*cos(ang));
		glVertex3f(raio*sin(ang+ang_inc),0.0f,raio*cos(ang+ang_inc));

		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(raio*sin(ang),0.0f,raio*cos(ang));

		ang+=ang_inc;
	}
	glEnd();

}




/// <summary>
/// Desenha um plano centrado na origem voltado para o eixo dos yy com lados de tamanh especificado em X e Z.
/// </summary>
/// <param name="ladoX">O comprimento do lado segundo X.</param>
/// <param name="ladoZ">O comprimento do lado segundo Z.</param>
void plano(float ladoX, float ladoZ){

	glBegin(GL_TRIANGLES);

		glVertex3f(-ladoX/2,0.0f,-ladoZ/2);
		glVertex3f(-ladoX/2,0.0f,ladoZ/2);
		glVertex3f(ladoX/2,0.0f,ladoZ/2);

		glVertex3f(-ladoX/2,0.0f,-ladoZ/2);
		glVertex3f(ladoX/2,0.0f,ladoZ/2);
		glVertex3f(ladoX/2,0.0f,-ladoZ/2);

	glEnd();

}



/// <summary>
/// Desenha um cubo centrado na origem.
/// </summary>
/// <param name="lado">The lado.</param>
void cubo(float lado){
	float x = lado/2;
	glBegin(GL_TRIANGLES);
	
	//BASE => Y=-x
	
	glColor3ub(255,0,0);
	glVertex3f(x,-x,-x);
	glVertex3f(-x,-x,-x);
	glVertex3f(-x,-x,x);
	glVertex3f(-x,-x,x);
	glVertex3f(x,-x,x);
	glVertex3f(x,-x,-x);
	

		//TOPO => Y=x
	
	glVertex3f(x,x,-x);
	glVertex3f(-x,x,-x);
	glVertex3f(-x,x,x);
	glVertex3f(-x,x,x);
	glVertex3f(x,x,x);
	glVertex3f(x,x,-x);
	
		//LADO ESQUERDO => X=-x
	
	glVertex3f(-x,x,-x);
	glVertex3f(-x,-x,-x);
	glVertex3f(-x,-x,x);
	glVertex3f(-x,-x,x);
	glVertex3f(-x,x,x);
	glVertex3f(-x,x,-x);

		//LADO DIREITO => X=x

	glVertex3f(x,x,-x);
	glVertex3f(x,-x,-x);
	glVertex3f(x,-x,x);
	glVertex3f(x,-x,x);
	glVertex3f(x,x,x);
	glVertex3f(x,x,-x);

		//FRENTE => Z=x

	glVertex3f(-x,x,x);
	glVertex3f(-x,-x,x);
	glVertex3f(x,-x,x);
	glVertex3f(x,-x,x);
	glVertex3f(x,x,x);
	glVertex3f(-x,x,x);

		//TRÁS => Z=-x

	glVertex3f(-x,x,-x);
	glVertex3f(-x,-x,-x);
	glVertex3f(x,-x,-x);
	glVertex3f(x,-x,-x);
	glVertex3f(x,x,-x);
	glVertex3f(-x,x,-x);

	glEnd();

	

}