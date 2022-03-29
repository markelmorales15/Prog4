/*
 * venta.h
 *
 *  Created on: 29 mar 2022
 *      Author: marke
 */

#ifndef VENTA_H_
#define VENTA_H_
#include "fecha.h"
#include "usuario.h"
#include "zapato.h"


typedef struct{
	char cod_art[20];
	Fecha f_venta;
	Usuario user;
	Zapato cod_zap;

}Venta;
void InfoCliente(Usuario user);
void InfoArticulo(Zapato z);
void verVentaCliente(Usuario user, Fecha f , Zapato z);
void verVentas(Venta *v);


#endif /* VENTA_H_ */
