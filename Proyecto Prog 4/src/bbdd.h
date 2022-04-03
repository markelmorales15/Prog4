
#ifndef BBDD_H_
#define BBDD_H_
#include "sqlite3.h"

void crearTablas(sqlite3 *db);
void insertarPersona(sqlite3 *db, int id, char *nom);
void borrarPersona(sqlite3 *db, int id);
void mostrarPersonas(sqlite3 *db);
void modificarNombre(sqlite3 *db, int id, char *nom);
void borrarTodasLasPersonas(sqlite3 *db);


void registrarUsuario(sqlite3 *db, char *nombre, char *contra, float monedero);
void registrarAdmin(sqlite3 *db, char *nombre, char *contra, int priv);
void iniciarSesionUsuario(sqlite3 *db,char *nombre);
void iniciarSesionAdmin(sqlite3 *db, char *nombre);
void verListaZapatos(sqlite3 *db);
void verVentasUsuario(sqlite3 *db, char *nombre);
void cambiarContrasenaUsuario(sqlite3 *db, char *nombre, char *con);
void cambiarContrasenaAdmin(sqlite3 *db, char *nombre, char *con);
void anadirFondos(sqlite3 *db, char *nombre, float mon);
void eliminarCliente(sqlite3 *db, char *nombre);
void verUsuarios(sqlite3 *db);
void anadirVenta(sqlite3 *db, int dia, int mes, int anyo, char *usu, char *codarti);
void reducirMonedero(sqlite3 *db, char *usu,int mone);
void verVentasTodas(sqlite3 *db);
void anyadirZapato(sqlite3 *db, char *cod, char *nom, float precio, int stock, int talla);
void modificarStock(sqlite3 *db, int stock);








#endif /* BBDD_H_ */
