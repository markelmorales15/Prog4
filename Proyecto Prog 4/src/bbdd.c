#include "bbdd.h"
#include <stdio.h>
#include <string.h>
//int crearTablas(sqlite3 *db){
void crearTablas(sqlite3 *db){
	sqlite3_stmt *stmt1;
	sqlite3_stmt *stmt2;
	sqlite3_stmt *stmt3;
	sqlite3_stmt *stmt4;

	char sql1[] = "create table usuario(id int, nom varchar2(20))";
	char sql2[] = "create table admin(id int, nom varchar2(20))";
	char sql3[] = "create table zapato(id int, nom varchar2(20))";
	char sql4[] = "create table venta(id int, nom varchar2(20))";


	sqlite3_prepare_v2(db, sql1, -1, &stmt1, NULL) ;
	sqlite3_step(stmt1);
	sqlite3_finalize(stmt1);

	sqlite3_prepare_v2(db, sql2, -1, &stmt1, NULL) ;
	sqlite3_step(stmt1);
	sqlite3_finalize(stmt1);

	sqlite3_prepare_v2(db, sql3, -1, &stmt1, NULL) ;
	sqlite3_step(stmt1);
	sqlite3_finalize(stmt1);

	sqlite3_prepare_v2(db, sql4, -1, &stmt1, NULL) ;
	sqlite3_step(stmt1);
	sqlite3_finalize(stmt1);


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












