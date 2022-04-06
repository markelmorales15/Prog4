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
	printf("Usuario: %s, Zapato: %s, %i de %s de %i\n",v.usu.nombre, v.zap.cod_zap, v.f_venta.dia, v.f_venta.mes, v.f_venta.anyo);
	/*infoCliente(v);
	infoZapato(v);
	imprimirFecha(v.f_venta);*/
}
