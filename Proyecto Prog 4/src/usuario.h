/*
 * usuario.h
 *
 *  Created on: 29 mar 2022
 *      Author: mikel
 */

#ifndef USUARIO_H_
#define USUARIO_H_

typedef struct{
	char nombre[20];
	char contra[20];
	int monedero;
} Usuario;

//void cambiarContrasenia(Usuario *u, char contra[20]);
void anyadirFondos(Usuario *u, int m);
void imprimirUsuario(Usuario u);


#endif /* USUARIO_H_ */
