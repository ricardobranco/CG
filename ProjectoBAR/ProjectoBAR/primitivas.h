#ifndef _PRIMITIVAS
#define _PRIMITIVAS


void esfera_solid(float raio, int divv, int divh);

void esfera_wire(float raio, int divv, int divh);

void cone_wire(float altura, float raio, int div);

void cone_solid(float altura, float raio,  int div, int fat);

void plano(float ladoX, float ladoZ, int divX, int divZ);

void cuboSOLID(float lado, int nc);

void cilindro_wire(float altura, float raio, int div, int fat);

void cilindro_solid(float altura, float raio, int div, int fat);

#endif