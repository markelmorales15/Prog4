
#ifndef BBDD_H_
#define BBDD_H_
#include "sqlite3.h"

#include "zapato.h"
#include "usuario.h"
#include "fecha.h"
#include "admin.h"
#include "venta.h"

void crearTablas(sqlite3 *db);
void obtenerAdmin(sqlite3 *db, char *nombre, Admin *a);
void obtenerUsuario(sqlite3 *db, char *nombre, Usuario *u);
void obtenerZapato(sqlite3 *db, char *cod, Zapato *z);
void registrarUsuario(sqlite3 *db, char *nombre, char *contra, float monedero, int numZapatos);
void aumentarZapUsuario(sqlite3 *db, char *nombre, int numZapatos);
void registrarAdmin(sqlite3 *db, char *nombre, char *contra, int priv);
//void iniciarSesionUsuario(sqlite3 *db,char *nombre);
//void iniciarSesionAdmin(sqlite3 *db, char *nombre);
void verListaZapatos(sqlite3 *db);
void verVentasUsuario(sqlite3 *db, char *nombre);
void cambiarContrasenaUsuario(sqlite3 *db, char *nombre, char *con);
void cambiarContrasenaAdmin(sqlite3 *db, char *nombre, char *con);
void modificarMonedero(sqlite3 *db, char *nombre, float mon);
void eliminarUsuario(sqlite3 *db, char *nombre);
void verUsuarios(sqlite3 *db);
void anadirVenta(sqlite3 *db, int dia, char *mes, int anyo, char *usu, char *codarti);
void verVentasTodas(sqlite3 *db);
void anyadirZapato(sqlite3 *db, char *cod, char *nom, float precio, int stock, int talla);
void modificarStock(sqlite3 *db, int stock, char *codarti);








#endif /* BBDD_H_ */
