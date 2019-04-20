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
    char con[20];       //Confirm Password
    char career[20];    // [ Student or Teacher ]
    float score[5];     // Score Array [English, Mathematics, Science, Computer, History]
}rec1;

//Function Declare here!!
void login();
void regis();
void mainScreen();
void teacher();
void searchID();
void confirm();

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
            printf("*");
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
        if(strcmp(rec1.career, "Teacher") == 0){
            teacher();
        }
        else if(strcmp(rec1.career, "Student") == 0){
            //student();
        }
        fclose(fp);
    }
    else{
        fclose(fp);
        printf("\n\nWrong Username/Password\n");
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
        printf("%s", rec1.name);
        printf("%s", rec1.last); 
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
        fwrite(&rec1, sizeof(rec1), 1, fp);
        fclose(fp);
        /* USERNAME */
        // --------------------------------------------------------------------------------------------
        char namedes[20];
        printf("Username: ");
        scanf("%s",&namedes);
    int status = 0;
    FILE *fp;
    fp = fopen("record.txt","rb+"); //rb >>> Open for reading in binary mode

    while(fread(&rec1,sizeof(rec1),1,fp) == 1){
        if(strcmp(namedes,rec1.user) == 0){
            status = 1;
            printf("This user name can't use.\n");
            break;
        }
        else{
            printf("This username can use :)))\n");
            fwrite(&rec1, sizeof(rec1), 1, fp);
            break;
        }
    }
    if(status == 1){
        printf("Username: ");
        scanf("%s",&namedes);
        fwrite(&rec1, sizeof(rec1), 1, fp);
    }
    printf("%s", rec1.name);
    printf("%s", rec1.last); 
// fclose(fp);
// ------------------------------------------------------------------------------------------------


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
        //Confirm Password
        printf("\nPlease Confirm Password: ");
        int j = 0;
        while(1){
            char hc = getch();  //Get input from Keyboard (KEYCODE)
            if(hc == 13 || hc == 9){    //13 is ENTER & 9 is TAB
                rec1.con[j] = '\0';    //Set the end point of String
                break;
            }
            else if(hc == 8){   //8 is BackSpace (for del)
                if(j>0){
                    j--;
                    printf("\b \b");    //NOTE: Keep space with \b
                }
            }
            else{       //Replace password with star(*)
                rec1.con[j++] = hc;
                printf("* \b");
            }
        }
    //Check Password & Confirm
    if(strcmp(rec1.pass ,rec1.con) == 0){
        printf("\nConfirm Password Correct\n");
        // system("cls");
    }
    else{
        printf("\nConfirm Failed\n");
        system("cls");
        confirm();
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

void confirm(){
    printf("Please Enter Password Again\n");
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
        //Confirm Password
        printf("\nPlease Confirm Password: ");
        int j = 0;
        while(1){
            char hc = getch();  //Get input from Keyboard (KEYCODE)
            if(hc == 13 || hc == 9){    //13 is ENTER & 9 is TAB
                rec1.con[j] = '\0';    //Set the end point of String
                break;
            }
            else if(hc == 8){   //8 is BackSpace (for del)
                if(j>0){
                    j--;
                    printf("\b \b");    //NOTE: Keep space with \b
                }
            }
            else{       //Replace password with star(*)
                rec1.con[j++] = hc;
                printf("* \b");
            }
        }
    //Check Password & Confirm
    if(strcmp(rec1.pass ,rec1.con) == 0){
        printf("\nConfirm Password Correct\n");
        // system("cls");
    }
    else{
        printf("\nTry Again\n");
        strcpy(rec1.pass, "");
        strcpy(rec1.con, "");
        system("cls");
        confirm();
    }
}

/* -------------- This is Teacher-Part --------------- */
void teacher(){
    int choice;
    printf("------------------------------\n");
    printf("1: Search student by ID\n");
    printf("2: View all student\n");
    printf("3: Exit\n\n");
    printf("Choose your choice: ");
    scanf("%d",&choice);

    switch(choice){
        case 1:
            //printf("searchID(); is COMING SOON!!\n");
            searchID();
            break;
        case 2:
            //viewAll();
            printf("viewAll(); is COMING SOON!!\n");
            break;
        case 3:
            mainScreen();
            break;
    }
}

void searchID(){
    char search_id[20];
    system("cls");
    printf("Please enter Student ID: ");
    scanf("%s", search_id);

    int status = 0;
    FILE *fp;
    fp = fopen("record.txt","rb+"); //rb >>> Open for reading in binary mode

    while(fread(&rec1,sizeof(rec1),1,fp) == 1){
        if(strcmp(search_id,rec1.user) == 0 && strcmp(rec1.career,"Student")==0){
            status = 1;
            break;
        }
    }
    if(status == 1){
        system("cls");
        printf("Student Profile-------------------------------------------\n");
        printf("    Name: %s  %s\n",rec1.name, rec1.last);
        printf("    GPA: English     : %.2f\n", rec1.score[0]);
        printf("         Mathematics : %.2f\n", rec1.score[1]);
        printf("         Science     : %.2f\n", rec1.score[2]);
        printf("         Computer    : %.2f\n", rec1.score[3]);
        printf("         History     : %.2f\n", rec1.score[4]);
        printf("----------------------------------------------------------\n\n\n");

        int choice;
        printf("1: Edit score\n");
        printf("2: Exit\n");
        printf("Choose your choice: ");
        scanf("%d",&choice);

        system("cls");
        float eng, math, sci, com, his;
        switch(choice){
            case 1:
                // editScore();
                // printf("editScore(); is COMING SOON!!\n");
                printf("Enter %s score\n", rec1.name);

                printf("English: ");
                scanf("%f",&rec1.score[0]);

                printf("Mathematics: ");
                scanf("%f",&rec1.score[1]);

                printf("Science: ");
                scanf("%f",&rec1.score[2]);

                printf("Computer: ");
                scanf("%f",&rec1.score[3]);

                printf("History: ");
                scanf("%f",&rec1.score[4]);

                // rec1.score[0] = eng;
                // rec1.score[1] = math;
                // rec1.score[2] = sci;
                // rec1.score[3] = com;
                // rec1.score[4] = his;

                printf("Enter %s Score Successful!!", rec1.name);
                fwrite(&rec1, sizeof(rec1), 1, fp);
                fclose(fp);
                teacher();
                break;


            case 2:
                fclose(fp);
                teacher();
                break;
        }
    }
    else{
        fclose(fp);
        printf("\n\nStudent ID not found!!\n");
        printf("Press any key to continue!");
        getch();
        system("cls");
        teacher();
    }
}

// //Function Edit score
// void editScore(){

// }

//Main Screen (Login & Register)
void mainScreen(){
    int choice;
    system("cls");
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