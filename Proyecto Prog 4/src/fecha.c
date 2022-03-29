/*
 * fecha.c
 *
 *  Created on: 29 mar 2022
 *      Author: mikel
 */

#include "fecha.h"
#include <stdio.h>

void imprimirFecha(Fecha f){
	printf("día %i del mes %s de %i", f.dia, f.mes, f.anyo);
}

