#include <stdio.h>
#include "sqlite3.h"
#include <string.h>
#include "Server.h"

void printColumnValue(sqlite3_stmt *stmt, int col){
    int colType = sqlite3_column_type(stmt, col);

    printf("\n %s : %s \t", sqlite3_column_name(stmt,col),sqlite3_column_text(stmt, col));
}

int display(){
    sqlite3 *db;
    sqlite3_stmt *res;
    char *errmsg = 0;
    sqlite3_open("Details.db", &db);

    char array1[100];
    char *name = array1;
    printf("Enter Name: ");
    scanf(" %[^\n]%*c", name);


    char *show = "SELECT * FROM StudentDetails WHERE Name = ?;";

    int rc = sqlite3_prepare_v2(db, show, -1, &res, NULL);


    sqlite3_bind_text(res, 1, name, -1, NULL);

    while(sqlite3_step(res)!=SQLITE_DONE){
        for(int col = 0; col<=8; col++){
            printColumnValue(res, col);
        }
        printf("\n \n \n");
    }

    sqlite3_finalize(res);

    sqlite3_close(db);
}