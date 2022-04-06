#include "menu.h"
#include <stdio.h>
char menuInicial(){
	char opcion;

	printf("1) Iniciar sesión\n");
	printf("2) Registrarse\n");
	printf("3) Salir\n");
	printf("Opción: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%c",&opcion);
	return opcion;
}
char menuCliente(){
	char opcion;
	printf("1) Ver zapatos disponibles\n");
	printf("2) Comprar zapatos\n");
	printf("3) Ventas\n");
	printf("4) Perfil\n");
	printf("5) Cerrar sesión\n");
	printf("Opción: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%c",&opcion);
	return opcion;
}
char menuPerfil(){
	char opcion;
	printf("(1) Cambiar contraseña\n");
	printf("(2) Añadir fondos\n");
	printf("(3) Salir\n");
	printf("Opción: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%c",&opcion);
	return opcion;
}
char menuAdmin(){
	char opcion;
	printf("1) Ventas\n");
	printf("2) Ver clientes\n");
	printf("3) Reponer Stock\n");
	printf("4) Registrar admin\n");
	printf("5) Añadir nuevo zapato\n");
	printf("6) Eliminar cliente\n");
	printf("7) Cerrar sesión\n");
	printf("Opción: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%c",&opcion);
	return opcion;
}


