/*
 * fecha.h
 *
 *  Created on: 29 mar 2022
 *      Author: mikel
 */

#ifndef FECHA_H_
#define FECHA_H_

typedef struct{
	int dia;
	char mes[15];
	int anyo;
}Fecha;

void imprimirFecha(Fecha f);
#endif /* FECHA_H_ */
