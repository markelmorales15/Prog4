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

/*void crearInforme(char *fichero, char *z){
	FILE *pf;
	//int i;

	pf = fopen(fichero,"a");
	if (pf != (FILE*)NULL){
		fprintf(pf,"ZAPATOS COMPRADOS POR %s\n", fichero);
		fprintf(pf,"----------------\n");
		//imprimirZapatosComprados(u);
		fprintf(pf, "Zapato comprado: ");
		fputs(z, fichero);
		fprintf(pf, "\n");
	} else {
		/*fprintf("Zapato comprado: %s\n", z);
		fputs(z, fichero);
		fprintf(pf, "Zapato comprado: ");
		fputs(z, fichero);
		fprintf(pf, "\n");
	}
	fclose(fichero);
}*/

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
	int esAdmin,error, dia, anyo;
	Usuario u;
	Admin a;
	Zapato z;
	FILE* fi;
	char nombre[20],contra[20], zapatocomprar[20], fichero[20], mes[20];
	char nuevacontra[20];
	float masfondos;
	int result = sqlite3_open("bd.db", &db);
	if(result != SQLITE_OK){
		printf("No se ha podido abrir la BBDD\n");fflush(stdout);
	}else{
		printf("BBDD abierta\n");fflush(stdout);
	}
	//crearTablas(db);
	printf("BIENVENIDO A USHOE\n");
	printf("Antes de nada introduzca la fecha\n");
	printf("Dia: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%i",&dia);
	printf("Mes: ");
	fflush(stdout);
	fflush(stdin);
	gets(mes);
	printf("Anyo: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%i",&anyo);
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
								case '1':
									verVentasTodas(db);
									break;
								case '2':
									verUsuarios(db);
									break;
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
									printf("Estos son los zapatos disponibles en nuestra tienda\n");
									fflush(stdout);
									fflush(stdin);
									verListaZapatos(db);
									break;
								case '2':
									/*printf("Seleccione el código del zapato que desea comprar\n");
									fflush(stdout);
									fflush(stdin);*/
									verListaZapatos(db);
									printf("Seleccione el código del zapato que desea comprar");
									fflush(stdout);
									fflush(stdin);
									gets(zapatocomprar);
									obtenerZapato(db, zapatocomprar, &z);

									if(strcmp(z.cod_zap, zapatocomprar) == 0){
										if(z.stock>0){

											if(u.monedero > z.precio){


												/*strcpy(fichero,strcat(u.nombre, ".txt"));
												fi = fopen(fichero, "a");
												fputs(z.nom_zap, fi);
												fputs("\n", fi);
												fclose(fi);*/
												anadirVenta(db, dia, mes, anyo, u.nombre, z.cod_zap);
												z.stock--;
												modificarStock(db, z.stock, z.cod_zap);
												u.monedero = u.monedero - z.precio;
												modificarMonedero(db, u.nombre, u.monedero);
												u.numZapatos++;
												aumentarZapUsuario(db, u.nombre, u.numZapatos);
												printf("Gracias por su compra!!!\n");
											} else {
												printf("No dispone del saldo suficiente para realizar esta compra\n");
											}
									}
									} else {
										printf("Ese código no está en la lista\n");
										fflush(stdout);
									}

									/*strcpy(fichero, strcat(u.nombre, ".txt"));
									crearInforme(fichero,z.nom_zap);*/

									break;
								case '3':
									verVentasUsuario(db, u.nombre);
									break;
								case '4':
									do{
										opcion = menuPerfil();
										switch(opcion){
											case '1':
												printf("Introduzca la nueva contrasenya:  ");
												fflush(stdout);
												fflush(stdin);
												gets(nuevacontra);
												cambiarContrasenaUsuario(db, u.nombre, nuevacontra);
												break;
											case '2':
												printf("Introduce los fondos que quieras añadir: ");
												fflush(stdout);
												fflush(stdin);
												scanf("%f", masfondos);
												if(masfondos > 0){
													u.monedero = u.monedero + masfondos;
													modificarMonedero(db, u.nombre, masfondos);
												} else {
													printf("ERROR!!! Introduzca un número válido\n");
												}
												break;
											case '3': printf("Volviendo al menú usuario...\n");fflush(stdout);break;
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
