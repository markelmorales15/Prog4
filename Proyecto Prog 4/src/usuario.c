/*
 * usuario.c
 *
 *  Created on: 29 mar 2022
 *      Author: mikel
 */

#include "usuario.h"
#include <stdio.h>
#include <string.h>

//void cambiarContrasenia(Usuario *u, char contra[20]){
//	u->contra = contra;
//}

void addZapato(Usuario *u, Zapato z){
	u->zapatos[u->numZapatos] = &z;
	u->numZapatos++;
}

void cambiarContrasenia(Usuario *u, char *contra){
	strcpy(u->contra, contra);
}

void anyadirFondos(Usuario *u, float m){
	if(m > 0){
		u->monedero = u->monedero + m;
	}
}
void imprimirUsuario(Usuario u){
	printf("%s", u.nombre);
}

void imprimirZapatosComprados(Usuario u){
	for(int i = 0; i < u.numZapatos; i++){
		imprimirZapato(*u.zapatos[i]);
	}
}
