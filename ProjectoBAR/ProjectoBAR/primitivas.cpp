#define _USE_MATH_DEFINES

#include "primitivas.h"
#include <GL/glut.h>
#include <math.h>


/// <summary>
/// Desenha uma esfera solida centrada na origem.
/// </summary>
/// <param name="raio">O raio da esfera a criar.</param>
/// <param name="divv">Quantas divis�es verticais tem a esfera (numero de paralelos do globo).</param>
/// <param name="divh">Quantas divis�es verricais tem a esfera (numero de meridianos do globo).</param>
void esfera_solid(float raio, int divv, int divh){

	float incv = M_PI /((float) divv);
	float inch = 2*M_PI /((float) divh);
	
	glBegin(GL_TRIANGLES);

	float av=0.0f;

	for(int iv=0; iv<divv; iv++){
		
		float ah=0.0f;

		for(int ih=0; ih<divh; ih++){
			
			
			
			glVertex3f(raio*sin(av)*sin(ah), raio*cos(av), raio*sin(av)*cos(ah));
			glVertex3f(raio*sin(av+incv)*sin(ah), raio*cos(av+incv), raio*sin(av+incv)*cos(ah));
			glVertex3f(raio*sin(av+incv)*sin(ah+inch), raio*cos(av+incv), raio*sin(av+incv)*cos(ah+inch));
			
			glVertex3f(raio*sin(av)*sin(ah), raio*cos(av), raio*sin(av)*cos(ah));
			glVertex3f(raio*sin(av+incv)*sin(ah+inch), raio*cos(av+incv), raio*sin(av+incv)*cos(ah+inch));
			glVertex3f(raio*sin(av)*sin(ah+inch), raio*cos(av), raio*sin(av)*cos(ah+inch));
				
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
/// <param name="divv">Quantas divis�es verticais tem a esfera (numero de paralelos do globo).</param>
/// <param name="divh">Quantas divis�es verricais tem a esfera (numero de meridianos do globo).</param>
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
/// <param name="div">O numero de subdivis�es.</param>
/// <param name="fat">O numero de fatias.</param>
void cilindro_solid(float altura, float raio, int div, int fat){

	float ang=0.0f;
	float ang_inc=2*M_PI/((float)div);
	
	float alt=altura/2;
	float alt_inc=altura/((float) fat);
	
	float r_inc=raio/((float) div);
	
	glBegin(GL_TRIANGLES);
	
	for(int i=0; i<div;i++){

			float r=0.0;
			for(int ri=0;ri<div;ri++){

				glVertex3f(r*sin(ang),altura/2.0f, r*cos(ang));
				glVertex3f((r+r_inc)*sin(ang),altura/2.0f, (r+r_inc)*cos(ang));
				glVertex3f((r+r_inc)*sin(ang+ang_inc),altura/2.0f, (r+r_inc)*cos(ang+ang_inc));

				glVertex3f(r*sin(ang),altura/2.0f, r*cos(ang));
				glVertex3f((r+r_inc)*sin(ang+ang_inc),altura/2.0f, (r+r_inc)*cos(ang+ang_inc));
				glVertex3f(r*sin(ang+ang_inc),altura/2.0f, r*cos(ang+ang_inc));


				glVertex3f(r*sin(ang),-altura/2.0f, r*cos(ang));
				glVertex3f((r+r_inc)*sin(ang+ang_inc),-altura/2.0f, (r+r_inc)*cos(ang+ang_inc));
				glVertex3f((r+r_inc)*sin(ang),-altura/2.0f, (r+r_inc)*cos(ang));

				glVertex3f(r*sin(ang),-altura/2.0f, r*cos(ang));
				glVertex3f(r*sin(ang+ang_inc),-altura/2.0f, r*cos(ang+ang_inc));
				glVertex3f((r+r_inc)*sin(ang+ang_inc),-altura/2.0f, (r+r_inc)*cos(ang+ang_inc));

				r+=r_inc;
			}

			
			
			alt=altura/2;

			for(int f=0;f<fat;f++){
				
				glVertex3f(raio*sin(ang),alt, raio*cos(ang));
				glVertex3f(raio*sin(ang),alt-alt_inc, raio*cos(ang));
				glVertex3f(raio*sin(ang+ang_inc),alt-alt_inc, raio*cos(ang+ang_inc));
			
				glVertex3f(raio*sin(ang),alt, raio*cos(ang));
				glVertex3f(raio*sin(ang+ang_inc),alt-alt_inc, raio*cos(ang+ang_inc));
				glVertex3f(raio*sin(ang+ang_inc),alt, raio*cos(ang+ang_inc));

				alt -=alt_inc;
			}
		

		ang+=ang_inc;

	}
	glEnd();
}


/// <summary>
/// Desenha um cilindro com linhas centrado na origem.
/// </summary>
/// <param name="altura">A altura do cilindro.</param>
/// <param name="raio">O raio da base.</param>
/// <param name="div">O numero de subdivis�es.</param>
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
/// <param name="div">O numero de divis�es. </param>
/// <param name="fat">O numero de fatias.</param>
void cone_solid(float altura, float raio, int div,int fat){

	float ang=0.0f;
	float ang_inc=2*M_PI/((float) div);

	float r_inc=raio/((float)div);
	
	float fr_inc=raio/((float)fat);
	float alt_dec=altura/((float)fat);

	glBegin(GL_TRIANGLES);
	
	for(int i=0; i<div;i++){


		float fr=0.0;
		float alt=altura;
		for(int f=0; f<fat;f++){
			
			glVertex3f(fr*sin(ang), alt, fr*cos(ang));
			glVertex3f((fr+fr_inc)*sin(ang),alt-alt_dec,(fr+fr_inc)*cos(ang));
			glVertex3f((fr+fr_inc)*sin(ang+ang_inc),alt-alt_dec,(fr+fr_inc)*cos(ang+ang_inc));

			glVertex3f(fr*sin(ang), alt, fr*cos(ang));
			glVertex3f((fr+fr_inc)*sin(ang+ang_inc),alt-alt_dec,(fr+fr_inc)*cos(ang+ang_inc));
			glVertex3f(fr*sin(ang+ang_inc), alt, fr*cos(ang+ang_inc));


			fr+=fr_inc;
			alt-=alt_dec;

		}

		float r=0;
		for(int ri=0;ri<div;ri++){
			glVertex3f(r*sin(ang),0.0f, r*cos(ang));
			glVertex3f((r+r_inc)*sin(ang+ang_inc),0.0f, (r+r_inc)*cos(ang+ang_inc));
			glVertex3f((r+r_inc)*sin(ang),0.0f, (r+r_inc)*cos(ang));

			glVertex3f(r*sin(ang),0.0f, r*cos(ang));
			glVertex3f(r*sin(ang+ang_inc),0.0f, r*cos(ang+ang_inc));
			glVertex3f((r+r_inc)*sin(ang+ang_inc),0.0f, (r+r_inc)*cos(ang+ang_inc));

			r+=r_inc;

		}
		
		ang+=ang_inc;
	}
	glEnd();
}


/// <summary>
/// Desenha um cone em linhas sobre o plano xOz, centrado no eixo dos yy.
/// </summary>
/// <param name="altura">A altura do cone.</param>
/// <param name="raio">O raio da base.</param>
/// <param name="div">O numero de divis�es. </param>
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
void plano(float ladoX, float ladoZ, int divX, int divZ){

	float incX = ladoX/((float) divX);
	float incZ = ladoZ/((float) divZ);


	glBegin(GL_TRIANGLES);

	float Z= -ladoZ/2;
	
	for(int iz=0; iz<divZ; iz++){
		
		float X= -ladoX/2;
		
		for(int ix=0; ix<divX; ix++){

			glVertex3f(X,0.0f,Z);
			glVertex3f(X,0.0f,Z+incZ);
			glVertex3f(X+incX,0.0f,Z+incZ);

			glVertex3f(X,0.0f,Z);
			glVertex3f(X+incX,0.0f,Z+incZ);
			glVertex3f(X+incX,0.0f,Z);

			X+=incX;

		}
		Z+=incZ;
	}

	glEnd();

}



/// <summary>
/// Desenha um cubo centrado na origem.
/// </summary>
/// <param name="lado">O comprimento do lado.</param>
void cubo(float lado){
	
	
	float x = lado/2;
	glBegin(GL_TRIANGLES);
	
	//BASE => Y=-x
	
	//glColor3ub(255,0,0); para que caralho � isto???
	glVertex3f(x,-x,-x);
	glVertex3f(-x,-x,x);
	glVertex3f(-x,-x,-x);
	glVertex3f(-x,-x,x);
	glVertex3f(x,-x,-x);
	glVertex3f(x,-x,x);
	

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
	glVertex3f(x,-x,x);
	glVertex3f(x,-x,-x);
	glVertex3f(x,-x,x);
	glVertex3f(x,x,-x);
	glVertex3f(x,x,x);

		//FRENTE => Z=x

	glVertex3f(-x,x,x);
	glVertex3f(-x,-x,x);
	glVertex3f(x,-x,x);
	glVertex3f(x,-x,x);
	glVertex3f(x,x,x);
	glVertex3f(-x,x,x);

		//TR�S => Z=-x

	glVertex3f(-x,x,-x);
	glVertex3f(x,-x,-x);
	glVertex3f(-x,-x,-x);
	glVertex3f(x,-x,-x);
	glVertex3f(-x,x,-x);
	glVertex3f(x,x,-x);

	glEnd();

	

	
	

}

void cuboSOLID(float lado, int nc){
	
	
	float y = lado/2;
	float x= -lado/2;
	float z= lado/2;
	float lad =lado/nc;
	while(y>-lado/2){

		while(z>-lado/2){

			while(x<lado/2){
				
				glBegin(GL_TRIANGLES);
	
	//Frente
	
	//glColor3ub(255,0,0); para que caralho � isto???
				glVertex3f(x+lad,y-lad,z);
				glVertex3f(x+lad,y,z);
				glVertex3f(x,y,z);
				glVertex3f(x,y,z);
				glVertex3f(x,y-lad,z);
				glVertex3f(x+lad,y-lad,z);
	

		//TOPO => Y=x
	
				glVertex3f(x,y,z-lad);
				glVertex3f(x,y,z);
				glVertex3f(x+lad,y,z);
				glVertex3f(x+lad,y,z);
				glVertex3f(x+lad,y,z-lad);
				glVertex3f(x,y,z-lad);
	
		//LADO ESQUERDO => X=-x
	
				glVertex3f(x,y,z-lad);
				glVertex3f(x,y-lad,z-lad);
				glVertex3f(x,y-lad,z);
				glVertex3f(x,y-lad,z);
				glVertex3f(x,y,z);
				glVertex3f(x,y,z-lad);

		//LADO DIREITO => X=x

				glVertex3f(x+lad,y,z-lad);
				glVertex3f(x+lad,y,z);
				glVertex3f(x+lad,y-lad,z);
				glVertex3f(x+lad,y-lad,z);
				glVertex3f(x+lad,y-lad,z-lad);
				glVertex3f(x+lad,y,z-lad);

		//BASE

				glVertex3f(x,y-lad,z);
				glVertex3f(x,y-lad,z-lad);
				glVertex3f(x+lad,y-lad,z-lad);
				glVertex3f(x+lad,y-lad,z-lad);
				glVertex3f(x+lad,y-lad,z);
				glVertex3f(x,y-lad,z);

		//TR�S => Z=-x

				glVertex3f(x,y-lad,z-lad);
				glVertex3f(x,y,z-lad);
				glVertex3f(x+lad,y,z-lad);
				glVertex3f(x+lad,y,z-lad);
				glVertex3f(x+lad,y-lad,z-lad);
				glVertex3f(x,y-lad,z-lad);

				glEnd();

			x=x+lad;

			}
			x=-lado/2;
		z=z-lad;
		}
		x=-lado/2;
		z=lado/2;
	y=y-lad;
	}
}

void cuboLINES(float lado, int nc){
	
	
	float y = lado/2;
	float x= -lado/2;
	float z= lado/2;
	float lad =lado/nc;
	while(y>-lado/2){

		while(z>-lado/2){

			while(x<lado/2){
				
				glBegin(GL_LINES);
	
	//Frente
	
	//glColor3ub(255,0,0); para que caralho � isto???
				glVertex3f(x+lad,y-lad,z);
				glVertex3f(x+lad,y,z);
				glVertex3f(x,y,z);
				glVertex3f(x,y,z);
				glVertex3f(x,y-lad,z);
				glVertex3f(x+lad,y-lad,z);
	

		//TOPO => Y=x
	
				glVertex3f(x,y,z-lad);
				glVertex3f(x,y,z);
				glVertex3f(x+lad,y,z);
				glVertex3f(x+lad,y,z);
				glVertex3f(x+lad,y,z-lad);
				glVertex3f(x,y,z-lad);
	
		//LADO ESQUERDO => X=-x
	
				glVertex3f(x,y,z-lad);
				glVertex3f(x,y-lad,z-lad);
				glVertex3f(x,y-lad,z);
				glVertex3f(x,y-lad,z);
				glVertex3f(x,y,z);
				glVertex3f(x,y,z-lad);

		//LADO DIREITO => X=x

				glVertex3f(x+lad,y,z-lad);
				glVertex3f(x+lad,y,z);
				glVertex3f(x+lad,y-lad,z);
				glVertex3f(x+lad,y-lad,z);
				glVertex3f(x+lad,y-lad,z-lad);
				glVertex3f(x+lad,y,z-lad);

		//BASE

				glVertex3f(x,y-lad,z);
				glVertex3f(x,y-lad,z-lad);
				glVertex3f(x+lad,y-lad,z-lad);
				glVertex3f(x+lad,y-lad,z-lad);
				glVertex3f(x+lad,y-lad,z);
				glVertex3f(x,y-lad,z);

		//TR�S => Z=-x

				glVertex3f(x,y-lad,z-lad);
				glVertex3f(x,y,z-lad);
				glVertex3f(x+lad,y,z-lad);
				glVertex3f(x+lad,y,z-lad);
				glVertex3f(x+lad,y-lad,z-lad);
				glVertex3f(x,y-lad,z-lad);

				glEnd();

			x=x+lad;

			}
			x=-lado/2;
		z=z-lad;
		}
		x=-lado/2;
		z=lado/2;
	y=y-lad;
	}
}

void cubo2(float lado, int nc){
	
	
	float y = lado/2;
	float x= -lado/2;
	float z= lado/2;
	float lad =lado/nc;

	while(y>-lado/2){

			while(x<lado/2){
				//Frente
				glColor3f(1,0,0);
				glBegin(GL_TRIANGLES);
				glVertex3f(x+lad,y-lad,z);
				glVertex3f(x+lad,y,z);
				glVertex3f(x,y,z);
				glVertex3f(x,y,z);
				glVertex3f(x,y-lad,z);
				glVertex3f(x+lad,y-lad,z);
				glEnd();
				x=x+lad;
				}
				x=-lado/2;
				y=y-lad;
			}
			x=-lado/2;
			y=lado/2;

		//TOPO => Y=x
			while(z>-lado/2){
				while(x<lado/2){
					glColor3f(0,1,0);
					glBegin(GL_TRIANGLES);
					glVertex3f(x,y,z-lad);
					glVertex3f(x,y,z);
					glVertex3f(x+lad,y,z);
					glVertex3f(x+lad,y,z);
					glVertex3f(x+lad,y,z-lad);
					glVertex3f(x,y,z-lad);
					glEnd();
					x=x+lad;
				}
				x=-lado/2;
				z=z-lad;
			}
			x=-lado/2;
			z=lado/2;
	
		//LADO ESQUERDO => X=-x
				while(y>-lado/2){
					while(z>-lado/2){
						glColor3f(0,0,1);
						glBegin(GL_TRIANGLES);
						glVertex3f(x,y,z);
						glVertex3f(x,y,z-lad);
						glVertex3f(x,y-lad,z-lad);
						glVertex3f(x,y-lad,z-lad);
						glVertex3f(x,y-lad,z);
						glVertex3f(x,y,z);
						glEnd();
						z=z-lad;
					}
					z=lado/2;
					y=y-lad;
				}
				z=lado/2;
				y=lado/2;
				x=lado/2;

		//LADO DIREITO => X=x
				while(y>-lado/2){
					while(z>-lado/2){
						glColor3f(1,1,0);
						glBegin(GL_TRIANGLES);
						glVertex3f(x,y-lad,z-lad);
						glVertex3f(x,y,z-lad);
						glVertex3f(x,y,z);
						glVertex3f(x,y,z);
						glVertex3f(x,y-lad,z);
						glVertex3f(x,y-lad,z-lad);
						glEnd();
						z=z-lad;
						}
					z=lado/2;
					y=y-lad;
					}
				y=-lado/2;
				x=-lado/2;
				z=lado/2;
		//BASE
				while(z>-lado/2){
					while(x<lado/2){
						glColor3f(1,0,1);
						glBegin(GL_TRIANGLES);
						glVertex3f(x,y,z);
						glVertex3f(x,y,z-lad);
						glVertex3f(x+lad,y,z-lad);
						glVertex3f(x+lad,y,z-lad);
						glVertex3f(x+lad,y,z);
						glVertex3f(x,y,z);
						glEnd();
						x=x+lad;
						}
					x=-lado/2;
					z=z-lad;
					}
				y=lado/2;
				x=-lado/2;
				z=-lado/2;
					
		//TR�S => Z=-x
				while(y>-lado/2){
					while(x<lado/2){
						glColor3f(1,1,1);
						glBegin(GL_TRIANGLES);
						glVertex3f(x,y-lad,z);
						glVertex3f(x,y,z);
						glVertex3f(x+lad,y,z);
						glVertex3f(x+lad,y,z);
						glVertex3f(x+lad,y-lad,z);
						glVertex3f(x,y-lad,z);
						glEnd();
						x=x+lad;
						}
					x=-lado/2;
					y=y-lad;
					}

}