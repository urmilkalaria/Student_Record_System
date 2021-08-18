#include <stdio.h>
#include <string.h>
#include "internal_header.h"

int name_check(char *s){
    int count=0;

    for (int i = 0; i < strlen(s) ; i++){
        if(s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9'){
            count++;
        }
    }
    if(count>0){
        return 0;
    }
    else{
        return 1;
    }
}

int grade_check(char *s){

    if(strlen(s) == 1 && (s[0] == 'S' || s[0] == 'A' || s[0] == 'B' || s[0] == 'C' || s[0] == 'D' || s[0] == 'F')){
        return 1;
    }
    else{
        return 0;
    }
}

int branch_check(int s){
    if(s == 1 || s == 2 || s == 3 || s == 4 || s == 5 || s == 6 || s == 7 || s == 8 || s == 9){
        return 1;
    }
    else{
        return 0;
    }
}

int phone_check(char *s){
    int count = 0;
    if(strlen(s)==10){
        for(int i = 0; i < 10; i++){
            if(s[i] != '1' && s[i] != '2' && s[i] != '3' && s[i] != '4' && s[i] != '5' && s[i] != '6' && s[i] != '7' && s[i] != '8' && s[i] != '9' && s[i] !='0'){
                count++;
            }
        }
        if(count>0){
            return 0;
        }
        else{
            return 1;
        }
    }
}

int date_check(char *s){
    int count = 0;
    if(strlen(s) == 10){
        if(s[2] == '/' && s[5] == '/'){
            if(((s[0] == '1' || s[0] == '2' || s[0] == '0') && (s[0] == '1' || s[0] == '2' || s[0] == '3' || s[0] == '4' || s[0] == '5' || s[0] == '6' || s[0] == '7' || s[0] == '8' || s[0] == '9' || s[0] == '0')) || (s[0] == '3' && (s[1] == '0' || s[1] == '1'))){
                if((s[3] == '0' && (s[4] == '1'|| s[4] == '2' || s[4] == '3' || s[4] == '4' || s[4] == '5' || s[4] == '6' || s[4] == '7' || s[4] == '8' || s[4] == '9')) || (s[3] == '1' && (s[4] == '0' || s[4] == '1' || s[4] == '2'))){
                    for(int i = 6; i < 10; i++){
                        if(s[i] != '1' && s[i] != '2' && s[i] != '3' && s[i] != '4' && s[i] != '5' && s[i] != '6' && s[i] != '7' && s[i] != '8' && s[i] != '9' && s[i] !='0'){
                            count++;
                        }
                    }
                    if(count > 0){
                        return 0;
                    }
                    else{
                        return 1;
                    }
                }
                else{
                    return 0;
                }
            }
            else{
                return 0;
            }
        }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }
}