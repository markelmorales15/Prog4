#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "zapato.h"
#include "usuario.h"
#include "fecha.h"
#include "admin.h"

void crearInforme(Usuario u, char *fichero){
	FILE *pf;
	int i;

	pf = fopen(fichero,"a");
	if (pf != (FILE*)NULL){
		fprintf(pf,"ZAPATOS COMPRADOS POR %s\n", fichero);
		fprintf(pf,"----------------\n");
		imprimirZapatosComprados(u);
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
	Zapato z = {"1234", "Zapato 1", 12.23, 5, 20};
	imprimirZapato(z);
	aumentarStock(&z, 2);
	printf("Stock = %i\n", z.stock);

	modificarPrecio(&z, 1);
	printf("Precio = %.2f\n", z.precio);
	fflush(stdout);

	return EXIT_SUCCESS;
}
