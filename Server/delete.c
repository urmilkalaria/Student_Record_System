#include <stdio.h>
#include "sqlite-amalgamation-3350500/sqlite3.h"
#include "Server.h"

int delete_record(){

    sqlite3 *db;
    sqlite3_stmt *res;
    sqlite3_stmt *res1;
    char *errmsg = 0;
    sqlite3_open("Details.db", &db);

    char array[100];
    char *name = array;
    printf("Enter the name of student whose record needs to be deleted: ");
    scanf(" %[^\n]%*c", name);

    char *Validate = "SELECT * FROM StudentDetails WHERE EXISTS(SELECT Name FROM StudentDetails WHERE Name = ?)";
    int rc = sqlite3_prepare_v2(db, Validate, -1, &res, NULL);
    sqlite3_bind_text(res, 1, name, -1, NULL);
    int step = sqlite3_step(res);
    sqlite3_reset(res);
    sqlite3_finalize(res);

    if(step ==SQLITE_ROW){

        char *delete = "DELETE FROM StudentDetails WHERE Name = ? LIMIT 1";

        int prep = sqlite3_prepare_v2(db, delete, -1, &res1, NULL);
        sqlite3_bind_text(res1, 1, name, -1, NULL);
        int step = sqlite3_step(res1);
        sqlite3_reset(res1);
        sqlite3_finalize(res1);

    }

    else{
        printf("\n \n Given Name is not found. \n \n");
    }

    return 0;
}
