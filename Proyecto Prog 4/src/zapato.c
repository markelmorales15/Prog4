/*
 * zapato.c
 *
 *  Created on: 29 mar 2022
 *      Author: mikel
 */

#include <stdio.h>
#include "zapato.h"

void imprimirZapato(Zapato z){
	printf("(%s, %s, %.2f, %i, %i)\n", z.cod_zap, z.nom_zap, z.precio, z.stock, z.talla);
}

void imprimirZapatoNombre(Zapato z){
	printf("(%s)\n",z.nom_zap);
}

void aumentarStock(Zapato *z, int stock){
	if(stock < 0){
		printf("ERROR!!! Inserte un nï¿½mero positivo");
	} else {
		z->stock = z->stock + stock;
	}
}
void modificarPrecio(Zapato *z, float precio){
	if(precio < 0){
		printf("ERROR!!! Inserte un nï¿½mero positivo");
	} else {
		z->precio = precio;
	}
}

Zapato pedirZapato() {
	Zapato z;
	printf("Introduce el código del zapato: ");
	fflush(stdout);
	fflush(stdin);
	gets(z.cod_zap);
	printf("Introduce el nombre del zapato: ");
	fflush(stdout);
	fflush(stdin);
	gets(z.nom_zap);
	printf("Introduce el precio del zapato: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%f",&z.precio);
	printf("Introduce el stock inicial: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%i",&z.stock);
	printf("Introduce la talla del producto: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%i",&z.talla);
	return z;
}

