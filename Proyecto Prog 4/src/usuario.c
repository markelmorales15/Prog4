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

Usuario pedirUsuario(){
	Usuario u;

	printf("Introduce el nombre: ");
	fflush(stdout);
	fflush(stdin);
	gets(u.nombre);
	printf("Introduce la contrase�a: ");
	fflush(stdout);
	fflush(stdin);
	gets(u.contra);
	printf("Introduce el monedero: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%f",&u.monedero);
	u.numZapatos = 0;
	return u;
}
