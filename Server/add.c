#include <stdio.h>
#include "sqlite-amalgamation-3350500/sqlite3.h"

int main(){

    char *errmsg = 0;
    sqlite3 *db;
    sqlite3_stmt *res;
    sqlite3_open("Details.db", &db);


    char array1[100];
    char *name = array1;
    printf("Enter Name: ");
    scanf("%[^\n]%*c", name);

    char array2[300];
    char *address = array2;
    printf("Enter Address: ");
    scanf("%[^\n]%*c", address);

    char array3[100];
    char *DOB = array3;
    printf("Enter Date of Birth: ");
    scanf("%s", DOB);

    char array4[100];
    char *DOA = array4;
    printf("Enter Date of Admission: ");
    scanf("%s", DOA);

    char array5[100];
    char *grade = array5;
    printf("Enter Grade: ");
    scanf("%s", grade);

    int roll_number;
    printf("Enter the roll number: ");
    scanf("%d", &roll_number);

    char array6[100];
    char *section = array6;
    printf("Enter Section: ");
    scanf("%s", section);

    int branch_code;
    printf("Enter branch code: ");
    scanf("%d", &branch_code);

    char array7[100];
    char *phone_number = array7;
    printf("Enter phone number: ");
    scanf("%s", phone_number);


    char *data;
    data = "INSERT INTO StudentDetails VALUES (?,?,?,?,?,@roll_number,?, @branch_code, ?);";

    int rc = sqlite3_prepare_v2(db, data, -1, &res, NULL);

    int val = sqlite3_bind_parameter_index(res, "@roll_number");
    int val1 = sqlite3_bind_parameter_index(res, "@branch_code");

    sqlite3_bind_int(res, val, roll_number);
    sqlite3_bind_int(res, val1, branch_code);

    sqlite3_bind_text(res, 1,name,-1, NULL);
    sqlite3_bind_text(res, 2,address,-1, NULL);
    sqlite3_bind_text(res, 3,DOB,-1, NULL);
    sqlite3_bind_text(res, 4,DOA,-1, NULL);
    sqlite3_bind_text(res, 5,grade,-1, NULL);
    sqlite3_bind_text(res, 7,section,-1, NULL);
    sqlite3_bind_text(res, 9,phone_number,-1, NULL);

    int step = sqlite3_step(res);

    sqlite3_reset(res);

    sqlite3_finalize(res);

    sqlite3_close(db);

    return 0;
}