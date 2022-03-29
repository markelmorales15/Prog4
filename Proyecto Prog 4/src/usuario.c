/*
 * usuario.c
 *
 *  Created on: 29 mar 2022
 *      Author: mikel
 */

#include "usuario.h"
#include <stdio.h>

//void cambiarContrasenia(Usuario *u, char contra[20]){
//	u->contra = contra;
//}
void anyadirFondos(Usuario *u, int m){
	if(m > 0){
		u->monedero = u->monedero + m;
	}
}
void imprimirUsuario(Usuario u){
	printf("%s", u.nombre);
}
