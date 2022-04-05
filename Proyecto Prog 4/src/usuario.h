/*
 * usuario.h
 *
 *  Created on: 29 mar 2022
 *      Author: mikel
 */

#ifndef USUARIO_H_
#define USUARIO_H_
#define NZAP 25

#include "zapato.h"

typedef struct{
	char nombre[20];
	char contra[20];
	float monedero;
	Zapato *zapatos[NZAP];
	int numZapatos;
	int max;
} Usuario;

void cambiarContrasenia(Usuario *u, char *contra);
void anyadirFondos(Usuario *u, float m);
void imprimirUsuario(Usuario u);
Usuario reservaMemoria(Usuario u, int tam);
Usuario pedirUsuario();
void liberaMemoria(Zapato *zapatos);


#endif /* USUARIO_H_ */
