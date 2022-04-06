/*
 * admin.c
 *
 *  Created on: 30 mar 2022
 *      Author: mikel
 */

#include "admin.h"
#include <stdio.h>

void imprimirAdmin(Admin a){
	printf("%s", a.nombre);
}

Admin pedirAdmin(){
	Admin a;

	printf("Introduce el nombre: ");
	fflush(stdout);
	fflush(stdin);
	gets(a.nombre);
	printf("Introduce la contraseña: ");
	fflush(stdout);
	fflush(stdin);
	gets(a.contra);
	printf("Introduce el privilegio (0/1): ");
	fflush(stdout);
	fflush(stdin);
	scanf("%i",&a.priv);
	return a;
}
