/*
 * venta.c
 *
 *  Created on: 29 mar 2022
 *      Author: marke
 */


#include "venta.h"
#include <stdio.h>

void infoCliente(Venta v){
	imprimirUsuario(v.usu);
}
void infoZapato(Venta v){
	imprimirZapatoNombre(v.zap);
}

void verVenta(Venta v){
	infoCliente(v);
	infoZapato(v);
	imprimirFecha(v.f_venta);
}
