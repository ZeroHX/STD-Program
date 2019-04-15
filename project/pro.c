/*
___________________________________________________________________________________

Project-name: STD-Program

Member: ZeroHX
        AnTznimalz
        Thawornch
        JJINNYNY

This is a project in Computer Programming,
Faculty of Information Technology King Mongkut's Institute of Technology Ladkrabang
(IT KMITL).
___________________________________________________________________________________

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
/*
Structure of all Record profile
[ NOTE: THIS IS A SAMPLE TEMPLATE FOR TESTING!! ]
*/
struct Record{
    char name[20];      // Name
    char last[20];      // Lastname
    char user[20];      // Username
    char pass[20];      // Password
    char career[20];    // [ Student or Teacher ]
}rec1;

//Function Declare here!!
void login();
void regis();
void mainScreen();

//Simple main, for goto mainScreen
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
//Login Screen
void login(){
    char log_id[20], log_pass[20];  //tmp User & Pass input
    int status = 0;     //check User & Pass state (0/1)
    system("cls");      //For Clear screen
    printf("Login To STD-Program!!\n\n");

    /*USERNAME Input*/
    printf("Username: ");
    scanf("%s", log_id);

    /*PASSWORD Input*/
    printf("\nPassword: ");
    int i = 0;
    while(1){
        char ch = getch();  //Get input from Keyboard (KEYCODE)
        if(ch == 13 || ch == 9){    //13 is ENTER & 9 is TAB
            log_pass[i] = '\0';    //Set the end point of String
            break;
        }
        else if(ch == 8){   //8 is BackSpace (for del)
            if(i>0){
                i--;
                printf("\b \b");    //NOTE: Keep space with \b
            }
        }
        else{       //Replace password with star(*)
            log_pass[i++] = ch;
            printf("* \b");
        }
    }

    /* Method to read .txt file (googling plz)*/
    FILE *fp;
    fp = fopen("record.txt","rb"); //rb >>> Open for reading in binary mode

    while(fread(&rec1,sizeof(rec1),1,fp) == 1){
        if(strcmp(log_id,rec1.user) == 0 && strcmp(log_pass,rec1.pass) == 0){
            status = 1;
            break;
        }
    }
    if(status == 1){
        system("cls");
        printf("Login Successful!!\n\n");
        printf("Welcome back %s !!\n\n", rec1.name);
        printf("You are %s !!\n\n", rec1.career);
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
//Register Screen
void regis(){
    int yn;
    /* Method to write(append) .txt file (googling plz)*/
    FILE *fp;
    fp = fopen("record.txt","ab+");
    if(fp == NULL) printf("Error! Check your file! (record.txt)");
    else{
        system("cls");
        printf("Please Enter Your Information Correctly\n");
        /* NAME-LASTNAME */
        printf("Name: ");
        scanf("%s",&rec1.name);
        printf("LastName: ");
        scanf("%s",&rec1.last);

        /* CAREER [teacher or student] */
        int choice;
        printf("Career      1: Teacher\n");
        printf("            2: Student\n\n");
        printf("Choose your choice![num]: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                strcpy(rec1.career, "Teacher");
                break;
            case 2:
                strcpy(rec1.career, "Student");
                break;
        }

        /* USERNAME */
        printf("Username: ");
        scanf("%s",&rec1.user);

        /* PASSWORD */
        printf("Password: ");
        int i = 0;
        while(1){
            char ch = getch();  //Get input from Keyboard (KEYCODE)
            if(ch == 13 || ch == 9){    //13 is ENTER & 9 is TAB
                rec1.pass[i] = '\0';    //Set the end point of String
                break;
            }
            else if(ch == 8){   //8 is BackSpace (for del)
                if(i>0){
                    i--;
                    printf("\b \b");    //NOTE: Keep space with \b
                }
            }
            else{       //Replace password with star(*)
                rec1.pass[i++] = ch;
                printf("* \b");
            }
        }

        printf("\n\n------------------------------------------\n");
        printf("Name: %s %s\n",rec1.name,rec1.last);
        printf("Career: %s\n", rec1.career);
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

//Main Screen (Login & Register)
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