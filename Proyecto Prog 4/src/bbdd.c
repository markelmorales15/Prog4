#include "bbdd.h"
#include <stdio.h>
#include <string.h>
//int crearTablas(sqlite3 *db){
void crearTablas(sqlite3 *db){
	sqlite3_stmt *stmt1;
	sqlite3_stmt *stmt2;
	sqlite3_stmt *stmt3;
	sqlite3_stmt *stmt4;

	char sql1[] = "create table usuario(nombre varchar(20), contra varchar(20), monedero float, numZapatos int)";
	char sql2[] = "create table admin(nombre varchar(20), contra varchar(20), priv int)";
	char sql3[] = "create table zapato(cod_zap varchar(20), nom_zap varchar(30), precio float, stock int, talla int)";
	char sql4[] = "create table venta(dia int, mes varchar(15), anyo int, usu varchar(20), codarti varchar(20))";


	sqlite3_prepare_v2(db, sql1, -1, &stmt1, NULL) ;
	sqlite3_step(stmt1);
	sqlite3_finalize(stmt1);

	sqlite3_prepare_v2(db, sql2, -1, &stmt2, NULL) ;
	sqlite3_step(stmt2);
	sqlite3_finalize(stmt2);

	sqlite3_prepare_v2(db, sql3, -1, &stmt3, NULL) ;
	sqlite3_step(stmt3);
	sqlite3_finalize(stmt3);

	sqlite3_prepare_v2(db, sql4, -1, &stmt4, NULL) ;
	sqlite3_step(stmt4);
	sqlite3_finalize(stmt4);


}

void registrarUsuario(sqlite3 *db, char *nombre, char *contra, float monedero, int numZapatos){
	sqlite3_stmt *stmt;
	char sql[100];

	sprintf(sql, "insert into usuario values(%s, %s, %2.f, %i)",nombre,contra, monedero, numZapatos);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);

}

void aumentarZapUsuario(sqlite3 *db, char *nombre, int numZapatos){
	sqlite3_stmt *stmt;
	char sql[100];
	sprintf(sql, "update usuario set numzapatos='%i' where nombre=%s", numZapatos, nombre);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);

}

void registrarAdmin(sqlite3 *db, char *nombre, char *contra, int priv){
	sqlite3_stmt *stmt;
	char sql[100];

	sprintf(sql, "insert into admin values(%s, %s, %i)",nombre,contra, priv);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}

/*void iniciarSesionUsuario(sqlite3 *db,char *nombre){

}

void iniciarSesionAdmin(sqlite3 *db, char *nombre){

}*/

void verListaZapatos(sqlite3 *db){
	int resul;
	sqlite3_stmt *stmt;
	Zapato z;
	char sql[100];

	sprintf(sql,"select * from zapato");
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;

	do{
		resul = sqlite3_step(stmt);

		strcpy(z.cod_zap, (char*)sqlite3_column_text(stmt, 0));
		strcpy(z.nom_zap, (char*)sqlite3_column_text(stmt, 1));
		z.precio = sqlite3_column_double(stmt, 2);
		z.stock = sqlite3_column_int(stmt, 3);
		z.talla = sqlite3_column_int(stmt, 4);
		imprimirZapato(z);
	}while(resul == SQLITE_ROW);

	sqlite3_finalize(stmt);
}

void verVentasUsuario(sqlite3 *db, char *nombre){
	int resul;
	sqlite3_stmt *stmt;
	Venta v;
	char sql[100];

	sprintf(sql,"select * from venta where usu = %s", nombre);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;

	do{
		resul = sqlite3_step(stmt);
		v.f_venta.dia = sqlite3_column_int(stmt, 0);
		strcpy(v.f_venta.mes, (char*)sqlite3_column_text(stmt, 1));
		v.f_venta.anyo = sqlite3_column_int(stmt, 2);
		strcpy(v.usu.nombre, (char*)sqlite3_column_text(stmt, 3));
		strcpy(v.zap.cod_zap, (char*)sqlite3_column_text(stmt, 3));

		verVenta(v);
	}while(resul == SQLITE_ROW);

	sqlite3_finalize(stmt);
}

void cambiarContrasenaUsuario(sqlite3 *db, char *nombre, char *con){
	sqlite3_stmt *stmt;
	char sql[100];

	sprintf(sql, "update usuario set contra='%s' where nombre=%s", con, nombre);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}

void cambiarContrasenaAdmin(sqlite3 *db, char *nombre, char *con){
	sqlite3_stmt *stmt;
	char sql[100];

	sprintf(sql, "update admin set contra='%s' where nombre=%s", con, nombre);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}

void modificarMonedero(sqlite3 *db, char *nombre, float mon){
	sqlite3_stmt *stmt;
	char sql[100];

	sprintf(sql, "update usuario set monedero='%2.f' where nombre=%s", mon, nombre);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}

void eliminarUsuario(sqlite3 *db, char *nombre){
	sqlite3_stmt *stmt;
	char sql[100];
	sprintf(sql, "delete from usuario where nombre = %s", nombre);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}

void verUsuarios(sqlite3 *db){
	int resul;
	sqlite3_stmt *stmt;
	Usuario u;
	char sql[100];

	sprintf(sql,"select * from usuario");
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;

	do{
		resul = sqlite3_step(stmt);

		strcpy(u.nombre, (char*)sqlite3_column_text(stmt, 0));
		strcpy(u.contra, (char*)sqlite3_column_text(stmt, 1));
		u.monedero = sqlite3_column_double(stmt, 2);
		u.numZapatos = sqlite3_column_int(stmt, 3);

		printf("%s %s %2.f %i\n",u.nombre, u.contra, u.monedero, u.numZapatos);
	}while(resul == SQLITE_ROW);

	sqlite3_finalize(stmt);
}

void anadirVenta(sqlite3 *db, int dia, char *mes, int anyo, char *usu, char *codarti){
	sqlite3_stmt *stmt;
	char sql[100];

	sprintf(sql, "insert into venta values(%i, %s, %i, %s, %s)",dia, mes, anyo, usu, codarti);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}

void verVentasTodas(sqlite3 *db){
	int resul;
	sqlite3_stmt *stmt;
	Venta v;
	char sql[100];

	sprintf(sql,"select * from venta");
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;

	do{
		resul = sqlite3_step(stmt);
		v.f_venta.dia = sqlite3_column_int(stmt, 0);
		strcpy(v.f_venta.mes, (char*)sqlite3_column_text(stmt, 1));
		v.f_venta.anyo = sqlite3_column_int(stmt, 2);
		strcpy(v.usu.nombre, (char*)sqlite3_column_text(stmt, 3));
		strcpy(v.zap.cod_zap, (char*)sqlite3_column_text(stmt, 3));

		verVenta(v);
	}while(resul == SQLITE_ROW);

	sqlite3_finalize(stmt);
}

void anyadirZapato(sqlite3 *db, char *cod, char *nom, float precio, int stock, int talla){
	sqlite3_stmt *stmt;
	char sql[100];

	sprintf(sql, "insert into zapato values(%s, %s, %2.f, %i, %i)",cod, nom, precio, stock, talla);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}

void modificarStock(sqlite3 *db, int stock, char *codarti){
	sqlite3_stmt *stmt;
	char sql[100];

	sprintf(sql, "update zapato set stock='%i' where cod_zap=%s", stock, codarti);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}











