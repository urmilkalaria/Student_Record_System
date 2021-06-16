#include <stdio.h>
#include <sqlite3.h>


int main(){
    char *errmsg=0;
    sqlite3 *db;
    sqlite3_open("Details.db", &db);

    char *det = "DROP TABLE IF EXISTS StudentDetails;"
                "CREATE TABLE StudentDetails(Name TEXT, Address TEXT, DOB TEXT, Date_Of_Admission TEXT, Result TEXT, Roll_Number INT, Section TEXT, Branch_Code INT, Phone_number TEXT);";
    sqlite3_exec(db, det, 0, 0, &errmsg);

    sqlite3_close(db);

    return 0;
}