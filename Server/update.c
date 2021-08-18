#include <stdio.h>
// #include "sqlite-amalgamation-3350500/sqlite3.h"
#include <string.h>
#include "Server.h"

int update(){
    sqlite3 *db;
    sqlite3_stmt *res;
    sqlite3_stmt *res1;
    char *errmsg = 0;
    sqlite3_open("Details.db", &db);

    char array1[100];
    char *name = array1;
    printf("Enter the name of Student whose details are updated: ");
    scanf(" %[^\n]%*c", name);

    char *Validate = "SELECT * FROM StudentDetails WHERE EXISTS(SELECT Name FROM StudentDetails WHERE Name = ?)";
    int rc = sqlite3_prepare_v2(db, Validate, -1, &res, NULL);
    sqlite3_bind_text(res, 1, name, -1, NULL);
    int step = sqlite3_step(res);
    sqlite3_reset(res);
    sqlite3_finalize(res);

    if(step == SQLITE_ROW){

        int number;

        printf("1.     Address \n");
        printf("2.     Date of Admission \n");
        printf("3.     Result \n");
        printf("4.     Roll number \n");
        printf("5.     Section \n");
        printf("6.     Branch code \n");
        printf("7.     Phone number \n");

        printf("\n \n \n");

        scanf("%d", &number);

        switch(number){

            case 1:
            {
                char array[300];
                char *address = array;
                printf("Enter New Address: ");
                scanf("%*c%[^\n]%*c", address);

                char *update = "UPDATE StudentDetails SET Address = ? WHERE Name = ?";
                int rs = sqlite3_prepare_v2(db, update, -1, &res1, NULL);
                sqlite3_bind_text(res1, 1, address, -1, NULL);
                sqlite3_bind_text(res1, 2, name, -1, NULL);
                int step = sqlite3_step(res1);
                sqlite3_reset(res1);
                sqlite3_finalize(res1);
                break;
            }

            case 2:
            {
                char array[300];
                char *DOA = array;
                printf("Enter New Date of Admission: ");
                scanf("%*c%[^\n]%*c", DOA);

                char *update = "UPDATE StudentDetails SET Date_Of_Admission = ? WHERE Name = ?";
                int rs = sqlite3_prepare_v2(db, update, -1, &res1, NULL);
                sqlite3_bind_text(res1, 1, DOA, -1, NULL);
                sqlite3_bind_text(res1, 2, name, -1, NULL);
                int step = sqlite3_step(res1);
                sqlite3_reset(res1);
                sqlite3_finalize(res1);
                break;
            }

            case 3:
            {
                char array[300];
                char *grade = array;
                printf("Enter New Grade: ");
                scanf("%*c%[^\n]%*c", grade);

                char *update = "UPDATE StudentDetails SET Result = ? WHERE Name = ?";
                int rs = sqlite3_prepare_v2(db, update, -1, &res1, NULL);
                sqlite3_bind_text(res1, 1, grade, -1, NULL);
                sqlite3_bind_text(res1, 2, name, -1, NULL);
                int step = sqlite3_step(res1);
                sqlite3_reset(res1);
                sqlite3_finalize(res1);
                break;
            }

            case 4:
            {
                char array[300];
                char *roll_number = array;
                printf("Enter New Roll Number: ");
                scanf("%*c%[^\n]%*c", roll_number);

                char *update = "UPDATE StudentDetails SET Roll_Number = ? WHERE Name = ?";
                int rs = sqlite3_prepare_v2(db, update, -1, &res1, NULL);
                sqlite3_bind_text(res1, 1, roll_number, -1, NULL);
                sqlite3_bind_text(res1, 2, name, -1, NULL);
                int step = sqlite3_step(res1);
                sqlite3_reset(res1);
                sqlite3_finalize(res1);
                break;
            }

            case 5:
            {
                char array[300];
                char *section = array;
                printf("Enter New Section: ");
                scanf("%*c%[^\n]%*c", section);

                char *update = "UPDATE StudentDetails SET Section = ? WHERE Name = ?";
                int rs = sqlite3_prepare_v2(db, update, -1, &res1, NULL);
                sqlite3_bind_text(res1, 1, section, -1, NULL);
                sqlite3_bind_text(res1, 2, name, -1, NULL);
                int step = sqlite3_step(res1);
                sqlite3_reset(res1);
                sqlite3_finalize(res1);
                break;
            }

            case 6:
            {
                char array[300];
                char *branch_code = array;
                printf("Enter New Branch Code: ");
                scanf("%*c%[^\n]%*c", branch_code);

                char *update = "UPDATE StudentDetails SET Branch_Code = ? WHERE Name = ?";
                int rs = sqlite3_prepare_v2(db, update, -1, &res1, NULL);
                sqlite3_bind_text(res1, 1, branch_code, -1, NULL);
                sqlite3_bind_text(res1, 2, name, -1, NULL);
                int step = sqlite3_step(res1);
                sqlite3_reset(res1);
                sqlite3_finalize(res1);
                break;
            }

            case 7:
            {
                char array[300];
                char *phone_number = array;
                printf("Enter New Phone number: ");
                scanf("%*c%[^\n]%*c", phone_number);

                char *update = "UPDATE StudentDetails SET Phone_Number = ? WHERE Name = ?";
                int rs = sqlite3_prepare_v2(db, update, -1, &res1, NULL);
                sqlite3_bind_text(res1, 1, phone_number, -1, NULL);
                sqlite3_bind_text(res1, 2, name, -1, NULL);
                int step = sqlite3_step(res1);
                sqlite3_reset(res1);
                sqlite3_finalize(res1);
                break;
            }
            
            default:
            {
                printf("The Given Choice is Not Valid");
                break;
            }

        }
        sqlite3_close(db);
    }
    else{
        printf("\n \nThe Given Name is not found.\n \n");
    }

    return 0;
}