/*
 * usuario.h
 *
 *  Created on: 29 mar 2022
 *      Author: mikel
 */

#ifndef USUARIO_H_
#define USUARIO_H_

#include "zapato.h"

typedef struct{
	char nombre[20];
	char contra[20];
	int monedero;
	Zapato *zapatos;
	int numZapatos;
	int max;
} Usuario;

//void cambiarContrasenia(Usuario *u, char contra[20]);
void anyadirFondos(Usuario *u, int m);
void imprimirUsuario(Usuario u);
Usuario reservaMemoria(Usuario u, int tam);
void liberaMemoria(Zapato *zapatos);


#endif /* USUARIO_H_ */
