#include <stdio.h>
#include <string.h>
#include "Server.h"
// #include "Project_Server.h"
// #include "sqlite3.h"


void sign_in()
{
	int a1;
	do
    {
    printf("     =============================================   Student Record System Login   =============================================\n\n");
    printf("                                                     1. Create a new account \n");
    printf("                                                     2. Login to an existing one\n");
    printf("                                                        Enter your choice:     ");
    int a;
    scanf("%d",&a);
    if(a==1)
    {
	    new_acc();
    }
    else if(a==2)
    {
	    int ans=login();
	    if(ans==1)
	{
		printf("                                                    Logged in successfully!\n");
        break;
	}
	else
	{
		printf("                                                    Login unsuccessful!\n");
	}
}
else
{          
	printf("                                                        Not a valid number\n");
}
printf("                                                        Enter 1 to go back to login page, else enter 0\n");
scanf("%d",&a1);
}while(a1);
}

void new_acc()
{
FILE *fp1 = fopen("Account.txt","a");
printf("Enter username for new acc:\n");
char username[100];
scanf("%s",username);
printf("Enter password for new acc:\n");
char password[100];
scanf("%s",password);
fprintf(fp1,"%s %s",username,password);
fprintf(fp1,"\n");
fclose(fp1);
}

int login()
{
int i=0;
FILE *fp2 = fopen("Account.txt","r");
if(fp2==NULL)
{
	printf("Create an account first!\n");
}
else
{
	printf("Enter username:\n");
	char username[100];
	scanf("%s",username);
	printf("Enter password:\n");
	char password[100];
	scanf("%s",password);
	char ch1[100];
	char ch2[100];
	while(fscanf(fp2,"%s %s",ch1,ch2)!=EOF)
	{
		if(!strcmp(username,ch1) && !strcmp(password,ch2))
		{
			i=1;
			break;
		}
	}
	fclose(fp2);
	return i;
}
}
