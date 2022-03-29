#include <stdio.h>
#include <stdlib.h>

#include "zapato.h"

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
