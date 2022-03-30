/*
 * venta.c
 *
 *  Created on: 29 mar 2022
 *      Author: marke
 */


#include "venta.h"
#include <stdio.h>

void infoCliente(Venta v){
	printf("Cliente: %s", v.user);
}
void infoZapato(Venta v){
	printf("Zapato: %s", v.cod_zap);
}

void verVenta(Venta v){
	infoCliente(v);
	infoZapato(v);
	imprimirFecha(v.f_venta);
}
