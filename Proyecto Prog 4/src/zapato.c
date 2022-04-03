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
		printf("ERROR!!! Inserte un n�mero positivo");
	} else {
		z->stock = z->stock + stock;
	}
}
void modificarPrecio(Zapato *z, float precio){
	if(precio < 0){
		printf("ERROR!!! Inserte un n�mero positivo");
	} else {
		z->precio = precio;
	}
}
