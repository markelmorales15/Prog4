#include "menu.h"
#include <stdio.h>
char menuInicial(){
	char opcion;

	printf("1) Iniciar sesi�n\n");
	printf("2) Registrarse\n");
	printf("3) Salir\n");
	printf("Opci�n: ");
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
	printf("5) Cerrar sesi�n\n");
	printf("Opci�n: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%c",&opcion);
	return opcion;
}
char menuPerfil(){
	char opcion;
	printf("(1) Cambiar contrase�a\n");
	printf("(2) A�adir fondos\n");
	printf("(3) Salir\n");
	printf("Opci�n: ");
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
	printf("5) A�adir nuevo zapato\n");
	printf("6) Eliminar cliente\n");
	printf("7) Cerrar sesi�n\n");
	printf("Opci�n: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%c",&opcion);
	return opcion;
}


