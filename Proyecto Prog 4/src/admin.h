/*
 * admin.h
 *
 *  Created on: 30 mar 2022
 *      Author: mikel
 */

#ifndef ADMIN_H_
#define ADMIN_H_

typedef struct{
	char nombre[20];
	char contra[20];
	int priv;
} Admin;

void imprimirAdmin(Admin a);
Admin pedirAdmin();
//void cambiarContra(Admin *a, char contra[20]);

#endif /* ADMIN_H_ */
