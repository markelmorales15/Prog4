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
	char sql4[] = "create table venta(dia int, mes int, anyo int, usu varchar(20), codarti varchar(20))";


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

void insertarPersona(sqlite3 *db, int id, char *nom){
	sqlite3_stmt *stmt;

	char sql[100];

	sprintf(sql, "insert into persona values(%d, %s)",id,nom);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}

void borrarPersona(sqlite3 *db, int id){
	sqlite3_stmt *stmt;
	char sql[100];
	sprintf(sql, "delete from persona where id = %d",id);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}

void mostrarPersonas(sqlite3 *db){
	int resul,id;
	sqlite3_stmt *stmt;
	char sql[100],*nom,*cad;
	char letra;

	sprintf(sql,"select * from persona");
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;

	do{
		resul = sqlite3_step(stmt);
		id = sqlite3_column_int(stmt, 0);
		strcpy(nom, (char*)sqlite3_column_text(stmt, 1));
		/*strcpy(cad, (char*)sqlite3_column_text(stmt, 2));
		letra = cad[0];*/
		printf("%d %s\n",id,nom);
	}while(resul == SQLITE_ROW);

	/*resul = sqlite3_step(stmt);
	while(resul == SQLITE_ROW){
		id = sqlite3_column_int(stmt, 0);
		strcpy(nom, (char*)sqlite3_column_text(stmt, 1));
		printf("%d %s\n",id,nom);
		resul = sqlite3_step(stmt);
	}*/
	sqlite3_finalize(stmt);

}
void modificarNombre(sqlite3 *db, int id, char *nom){
	sqlite3_stmt *stmt;
	char sql[100];

	sprintf(sql, "update persona set nom='%s' where id=%d", nom, id);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}

void borrarTodasLasPersonas(sqlite3 *db){
	sqlite3_stmt *stmt;
	char sql[100];
	sprintf(sql, "delete from persona");
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}












