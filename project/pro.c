#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

struct Record{
    char name[20];
    char last[20];
    char user[20];
    char pass[20];
}rec1;

void login();
void regis();
void mainScreen();

int main(){
    system("cls");
    printf("====================================================\n\n");
    printf("Welcome to STD-Program\n");
    printf("This project is part of subject Computer Programming\n\n");
    printf("====================================================\n\n\n");
    printf("          Press any key to continue!");
    getch();
    system("cls");
    mainScreen();
}

void login(){
    char log_id[20], log_pass[20];
    int status = 0;
    system("cls");
    printf("Login To STD-Program!!\n\n");
    printf("Username: ");
    scanf("%s", log_id);
    printf("\nPassword: ");
    scanf("%s", log_pass);

    FILE *fp;
    fp = fopen("record.txt","rb");

    while(fread(&rec1,sizeof(rec1),1,fp) == 1){
        if(strcmp(log_id,rec1.user) == 0 && strcmp(log_pass,rec1.pass) == 0){
            status = 1;
            break;
        }
    }
    if(status == 1){
        printf("Login Successful!!\n\n");
        printf("Welcome back %s !!\n\n", rec1.name);
        fclose(fp);
    }
    else{
        printf("Wrong Username/Password\n");
        printf("Please check your account again or register first!\n\n");
        printf("Press any key to continue!");
        getch();
        system("cls");
        mainScreen();

    }
}

void regis(){
    int yn;
    FILE *fp;
    fp = fopen("record.txt","ab+");
    if(fp == NULL) printf("Error! Check your file! (record.txt)");
    else{
        system("cls");
        printf("Please Enter Your Information Correctly\n");
        /* NAME-LASTNAME*/
        printf("Name: ");
        scanf("%s",&rec1.name);
        printf("LastName: ");
        scanf("%s",&rec1.last);

        /*USERNAME-PASSWORD*/
        printf("Username: ");
        scanf("%s",&rec1.user);
        printf("Password: ");
        scanf("%s",&rec1.pass);

        printf("------------------------------------------\n");
        printf("Name: %s %s\n",rec1.name,rec1.last);
        printf("Username: %s\n",rec1.user);
        printf("Password: ");
        for(int i=0; i<strlen(rec1.pass);i++){
            printf("*");
        }
        printf("\n");
        printf("------------------------------------------\n");
        printf("Do you want to create this account? (1: Yes/2: No): ");
        scanf("%d",& yn);
        switch(yn){
            case 1:
                system("cls");
                fwrite(&rec1, sizeof(rec1), 1, fp);
                fclose(fp);
                printf("Create Account Succesful!!\n\n\n");
                printf("Press any key to Main-Menu\n");
                getch();
                system("cls");
                mainScreen();
                break;
            case 2:
                regis();
                break;
        }

    }
}


void mainScreen(){
    int choice;
    printf("====================================================\n\n");
    printf("Welcome to STD-Program\n");
    printf("This project is part of subject Computer Programming\n\n");
    printf("====================================================\n");

    printf("\n1.| Login\n");
    printf("2.| Register\n\n");
    printf("==============================\n");
    printf("Choose your Choice: ");
    scanf("%d",& choice);


    switch(choice){
        case 1 :
            login();
            break;
        case 2 :
            regis();
            break;
    }
}