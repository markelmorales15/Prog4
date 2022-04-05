#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "zapato.h"
#include "usuario.h"
#include "fecha.h"
#include "admin.h"
#include "menu.h"
#include "sqlite3.h"
#include "bbdd.h"

void crearInforme(Usuario u, char *fichero, char *z){
	FILE *pf;
	//int i;

	pf = fopen(fichero,"a");
	if (pf != (FILE*)NULL){
		fprintf(pf,"ZAPATOS COMPRADOS POR %s\n", fichero);
		fprintf(pf,"----------------\n");
		//imprimirZapatosComprados(u);
		printf("Zapato comprado: %s\n", z);
	} else {
		printf("Zapato comprado: %s\n", z);
	}
}

/*void leerProductos(Producto *productos[], char *fichero){
    FILE *pf;
    int i=0;
    Producto p;
    pf = fopen(fichero,"r");
    if (pf!=(FILE*)NULL){
        while (fscanf(pf,"%d%s%f",&p.referencia,p.nombre,&p.precio)!=EOF){
            productos[i]=&p;
            i++;
        }
        fclose(pf);
    }
}*/

int main(void) {
	/*Zapato z = {"1234", "Zapato 1", 12.23, 5, 20};
	imprimirZapato(z);
	aumentarStock(&z, 2);
	printf("Stock = %i\n", z.stock);

	modificarPrecio(&z, 1);
	printf("Precio = %.2f\n", z.precio);
	fflush(stdout);
*/
	sqlite3 *db;
	char opcion;
	int esAdmin,error;
	Usuario u;
	Admin a;
	Zapato z;
	char nombre[20],contra[20], zapatocomprar[20], fichero[20];
	int result = sqlite3_open("bd.db", &db);
	if(result != SQLITE_OK){
		printf("No se ha podido abrir la BBDD\n");fflush(stdout);
	}else{
		printf("BBDD abierta\n");fflush(stdout);
	}
	//crearTablas(db);
	do{
		error = 0;
		opcion = menuInicial();
		switch(opcion){
			case '1':
				printf("Como vas a iniciar la sesión (u-usuario, a-administrador): ");
				fflush(stdout);
				fflush(stdin);
				scanf("%c",&opcion);
				printf("Introduce tu nombre: ");
				fflush(stdout);fflush(stdin);gets(nombre);
				printf("Introduce tu contraseña: ");
				fflush(stdout);fflush(stdin);gets(contra);
				if(opcion=='u'){
					obtenerUsuario(db, nombre, &u);
					printf("%s %s\n",u.nombre,u.contra);
					if(strcmp(u.contra,contra)==0){
						esAdmin = 0;
					}else{
						error = 1;
						printf("La contraseña no es correcta\n");
					}
				}else{
					obtenerAdmin(db, nombre, &a);
					printf("%s %s\n",a.nombre,a.contra);
					if(strcmp(a.contra,contra)==0){
						esAdmin = 1;
					}else{
						error = 1;
						printf("La contraseña no es correcta\n");fflush(stdout);
					}
				}
				if(!error){
					if(esAdmin){
						do{
							opcion = menuAdmin();
							switch(opcion){
								case '1': break;
								case '2': break;
								case '3': break;
								case '4': break;
								case '5': break;
								case '6': printf("Volviendo al menú principal...\n");fflush(stdout);break;
								default:printf("La opción seleccionada no es correcta\n");fflush(stdout);
							}
						}while(opcion!='6');
					}else{
						do{
							opcion = menuCliente();
							switch(opcion){
								case '1':
									printf("Estos son los zapatos disponibles en nuestra tienda");
									fflush(stdout);
									verListaZapatos(db);
									break;
								case '2':
									verListaZapatos(db);
									printf("Seleccione el código del zapato que desea comprar");
									fflush(stdin);gets(zapatocomprar);
									obtenerZapato(db, zapatocomprar, z);
									strcpy(fichero,"Platanos");
									crearInforme(u, fichero, zapatocomprar);
									fflush(stdout);
									break;
								case '3': break;
								case '4':
									do{
										opcion = menuPerfil();
										switch(opcion){
											case '1': break;
											case '2': break;
											case '3': printf("Volviendo al menú cliente...\n");fflush(stdout);break;
											default:printf("La opción seleccionada no es correcta\n");fflush(stdout);
										}
									}while(opcion!='3');



									break;
								case '5': printf("Volviendo al menú principal...\n");fflush(stdout);break;
								default:printf("La opción seleccionada no es correcta\n");fflush(stdout);
							}
						}while(opcion!='5');
					}
				}
				break;
			case '2': u = pedirUsuario();
					  registrarUsuario(db, u.nombre, u.contra, u.monedero, u.numZapatos);
				break;
			case '3': printf("Saliendo de la aplicación...");fflush(stdout);break;
			default: printf("La opción seleccionada no es correcta\n");fflush(stdout);
		}
	}while(opcion!='3');
	return EXIT_SUCCESS;
}
