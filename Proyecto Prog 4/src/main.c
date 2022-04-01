#include <stdio.h>
#include <stdlib.h>

#include "zapato.h"
#include "usuario.h"
#include "fecha.h"
#include "admin.h"

void crearInforme(Usuario u, char *fichero){
	FILE *pf;
	int i;

	pf = fopen(fichero,"w");
	if (pf != (FILE*)NULL){
		fprintf(pf,"ZAPATOS COMPRADOS POR %s\n", fichero);
		fprintf(pf,"----------------\n");
		for(i=0;i< u.numZapatos;i++){
			imprimirZapato(u.zapatos[i]);
		}
	}
}

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
