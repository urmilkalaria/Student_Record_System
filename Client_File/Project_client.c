#include <stdio.h>
#include "Server.h"
// #include "sqlite3.h"

int count;
int main()
{   
    count = 0;
    int n;
    student_i Stud[100];
    sign_in();
    int qop;
    do
    {
    int op;
    printf("\n     =============================================   %s   =============================================","Student Record system");
    printf("\n\n     *********************************************************************************************************************");
    printf("\n     *********************************************************************************************************************");
    printf("\n\n                                                    1. Create/Open the databasse");
    printf("\n\n                                                    2. Add Student details");
    printf("\n\n                                                    3. Display list of students");
    printf("\n\n                                                    4. Display Student details");
    printf("\n\n                                                    5. Modify Student details");
    printf("\n\n                                                    6. Delete student record");
    printf("\n\n     **********************************************************************************************************************");
    printf("\n\n                                                   Enter your choice: ");
        scanf(" %d",&op);
        switch (op)
        {
            case 1:
                create();
                break;
            case 2:
                add();
                break;
            case 3:
                totalStudents();
                break;
            case 4:
                display();
                break;
            case 5:
                update();
                break;
            case 6:
                delete_record();
                break;

            default:
                printf("                                                  Invalid option, please re-enter");
                break;
    }
    printf("                                         Enter 0 to exit the student record system\n");
    printf("                                         Enter 1 to go back to main menu ");
    scanf("%d",&qop);
    }while(qop);
    return 0;
}
