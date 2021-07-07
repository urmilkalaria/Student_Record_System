#include <stdio.h>
#include "sqlite3.h"
#include <string.h>

int printrowValue(sqlite3_stmt *stmt, int col, int count){
    int colType = sqlite3_column_type(stmt, col);

    printf("%d \t %s \n",count+1,sqlite3_column_text(stmt, col));

    count++;

    return count;
    // printf("\n");
}

int totalStudents(){
    sqlite3 *db;
    sqlite3_stmt *res;
    char *errmsg = 0;
    sqlite3_open("Details.db", &db);
    int c = 0;

    char *show = "SELECT Name FROM StudentDetails ORDER BY Name ASC;";

    int rc = sqlite3_prepare_v2(db, show, -1, &res, NULL);

    while(sqlite3_step(res)!=SQLITE_DONE){
        c = printrowValue(res, 0,c);
    }

    sqlite3_finalize(res);

    sqlite3_close(db);
}