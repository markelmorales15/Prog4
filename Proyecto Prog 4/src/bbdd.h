
#ifndef BBDD_H_
#define BBDD_H_
#include "sqlite3.h"

void crearTablas(sqlite3 *db);
void insertarPersona(sqlite3 *db, int id, char *nom);
void borrarPersona(sqlite3 *db, int id);
void mostrarPersonas(sqlite3 *db);
void modificarNombre(sqlite3 *db, int id, char *nom);
void borrarTodasLasPersonas(sqlite3 *db);


/*void registrarUsuario(sqlite3 *db, );
void registrarAdmin(sqlite3 *db,);
void iniciarSesion(sqlite3 *db,);
void listaArticulo(sqlite3 *db,);
void verVentasCliente(sqlite3 *db,);
void cambiarContrasenaUsuario(sqlite3 *db,);
void cambiarContrasenaAdmin(sqlite3 *db,);
void anadirFondos(sqlite3 *db,);
void eliminarCliente(sqlite3 *db,);
void verClientes(sqlite3 *db,);
void InfoCliente(sqlite3 *db,);
void InfoArticulo(sqlite3 *db,);
void anadirVenta(sqlite3 *db,);
void verVentaCliente(sqlite3 *db,);
void reducirMonedero(sqlite3 *db,);
void verVentasTodas(sqlite3 *db,);
void listaArticulos(sqlite3 *db,);
void añadirArticulo(sqlite3 *db,);
void modificarStock(sqlite3 *db,);*/








#endif /* BBDD_H_ */
