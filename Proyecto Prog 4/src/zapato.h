/*
 * zapato.h
 *
 *  Created on: 29 mar 2022
 *      Author: mikel
 */

#ifndef ZAPATO_H_
#define ZAPATO_H_

typedef struct{
	char cod_zap[20];
	char nom_zap[30];
	float precio;
	int stock;
	int talla;
}Zapato;

void imprimirZapato(Zapato z);
void imprimirZapatoNombre(Zapato z);
void aumentarStock(Zapato *z, int stock);
void modificarPrecio(Zapato *z, float precio);

#endif /* ZAPATO_H_ */
