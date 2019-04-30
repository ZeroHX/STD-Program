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
#include <float.h>
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
    //float score[5];     // Score Array [English, Mathematics, Science, Computer, History]
    float eng;
    float math;
    float sci;
    float com;
    float his;
}rec1, tmp, sign;

struct Stat{
    float max;
    float min;
    float avg;
}s_eng, s_math, s_sci, s_com, s_his, s_all;

//Function Declare here!!
void login();
void regis();
void mainScreen();
void teacher();
void student();
void searchID();
void confirm();
void viewAll();
void stat();
void viewScore();

int isStu = 0;
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
    fp = fopen("../data/record.txt","r"); //rb >>> Open for reading in binary mode
    while(fscanf(fp,"%s %s %s %s %s %f %f %f %f %f",sign.name,sign.last,sign.user,sign.pass,sign.career,&sign.eng, &sign.math, &sign.sci, &sign.com, &sign.his) != EOF){
        if(!strcmp(log_id, sign.user) && !strcmp(log_pass, sign.pass)){
            printf("\nLogin Successful!!");
            status = 1;
            break;
        }
    }
    if(status == 1){
        system("cls");
        printf("Login Successful!!\n\n");
        if(strcmp(sign.career, "Teacher") == 0){
            teacher();
        }
        else if(strcmp(sign.career, "Student") == 0){
            student();
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
    fp = fopen("../data/record.txt","ab+");

    if(fp == NULL) printf("Error! Check your file! (../data/record.txt)");
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
            default:
                printf("**  Invalid Career  **");
                printf("          Press any key to continue!");
                getch();
                regis();
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
                rec1.eng = 0;
                rec1.math = 0;
                rec1.sci = 0;
                rec1.com = 0;
                rec1.his = 0;
                fprintf(fp,"%s %s %s %s %s %f %f %f %f %f\n",rec1.name,rec1.last,rec1.user,rec1.pass,rec1.career,rec1.eng, rec1.math, rec1.sci, rec1.com, rec1.his);
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
            default:
                printf("**  Invalid Choice  **\n");
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
    printf("Hello %s You are %s\n", sign.name, sign.career);
    printf("------------------------------\n");
    printf("1: Search student by ID\n");
    printf("2: View all student\n");
    printf("3: Statistics\n");
    printf("4: Exit\n\n");
    printf("Choose your choice: ");
    scanf("%d",&choice);

    switch(choice){
        case 1:
            searchID();
            break;
        case 2:
            viewAll(); //viewAll is now available eiei from Jakkawan
            break;
        case 3:
            stat();
            break;
        case 4:
            mainScreen();
            break;
        default:
            printf("\n**  Invalid Choice  **\n\n\n");
            printf("Press any key to continue...\n");
            getch();
            system("cls");
            teacher();
            break;
    }
}

void searchID(){
    char search_id[20];
    system("cls");
    printf("Please enter Student ID: ");
    scanf("%s", search_id);

    int status = 0;
    FILE *fp, *fp1;
    fp = fopen("../data/record.txt","r"); //rb >>> Open for reading in binary mode

    while(fscanf(fp,"%s %s %s %s %s %f %f %f %f %f",rec1.name,rec1.last,rec1.user,rec1.pass,rec1.career,&rec1.eng, &rec1.math, &rec1.sci, &rec1.com, &rec1.his) != EOF){
        if(!strcmp(search_id, rec1.user) && !strcmp(rec1.career, "Student")){
            status = 1;
            break;
        }
    }
    if(status == 1){
        system("cls");
        printf("Student Profile-------------------------------------------\n");
        printf("    Name: %s  %s\n",rec1.name, rec1.last);
        printf("    GPA: English     : %.2f\n", rec1.eng);
        printf("         Mathematics : %.2f\n", rec1.math);
        printf("         Science     : %.2f\n", rec1.sci);
        printf("         Computer    : %.2f\n", rec1.com);
        printf("         History     : %.2f\n", rec1.his);
        printf("----------------------------------------------------------\n\n\n");
        fclose(fp);
        int choice;
        printf("1: Edit score\n");
        printf("2: Exit\n");
        printf("Choose your choice: ");
        scanf("%d",&choice);

        system("cls");
        char score[10];
        switch(choice){
            case 1:
                fp = fopen("../data/record.txt", "r");
                fp1 = fopen("../data/temp.txt", "a");
                while(fscanf(fp,"%s %s %s %s %s %f %f %f %f %f",rec1.name,rec1.last,rec1.user,rec1.pass,rec1.career,&rec1.eng, &rec1.math, &rec1.sci, &rec1.com, &rec1.his) != EOF){
                    if(!strcmp(search_id, rec1.user)){ //if 1
                        printf("Enter Score\n");
                        printf("English: ");
                        scanf("%f", &tmp.eng);
                        printf("Mathematics: ");
                        scanf("%f", &tmp.math);
                        printf("Science: ");
                        scanf("%f", &tmp.sci);
                        printf("Computer: ");
                        scanf("%f", &tmp.com);
                        printf("History: ");
                        scanf("%f", &tmp.his);
                        fprintf(fp1,"%s %s %s %s %s %f %f %f %f %f\n",rec1.name,rec1.last,rec1.user,rec1.pass,rec1.career,tmp.eng, tmp.math, tmp.sci, tmp.com, tmp.his);
                    }                                                                                                                  //tmp because we can found id :)
                    else{
                        fprintf(fp1,"%s %s %s %s %s %f %f %f %f %f\n",rec1.name,rec1.last,rec1.user,rec1.pass,rec1.career,rec1.eng, rec1.math, rec1.sci, rec1.com, rec1.his);
                    }                                                                                                                  //this case means we can't find the id :'(
                }
                fclose(fp);
                fclose(fp1);

                fp = fopen("../data/record.txt", "w");
                fclose(fp);

                fp = fopen("../data/record.txt", "a");
                fp1 = fopen("../data/temp.txt", "r");
                while(fscanf(fp1,"%s %s %s %s %s %f %f %f %f %f",rec1.name,rec1.last,rec1.user,rec1.pass,rec1.career,&rec1.eng, &rec1.math, &rec1.sci, &rec1.com, &rec1.his) != EOF){
                    fprintf(fp,"%s %s %s %s %s %f %f %f %f %f\n",rec1.name,rec1.last,rec1.user,rec1.pass,rec1.career,rec1.eng, rec1.math, rec1.sci, rec1.com, rec1.his);
                }

                fclose(fp);
                fclose(fp1);

                fp1 = fopen("../data/temp.txt", "w");
                fclose(fp1);
                system("cls");
                teacher();
                break;
            case 2:
                fclose(fp);
                teacher();
                break;
            default:
                printf("*** Invalid Choice  ***");
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

//viewAll function
void viewAll(){ //Yeah Now, you can see all the students score
    FILE *fp;
    fp = fopen("../data/record.txt", "r");
    while(fscanf(fp,"%s %s %s %s %s %f %f %f %f %f",rec1.name,rec1.last,rec1.user,rec1.pass,rec1.career,&rec1.eng, &rec1.math, &rec1.sci, &rec1.com, &rec1.his) != EOF){ //It will scan in ../data/record.txt until it can not find the ../data.
        if(!strcmp(rec1.career, "Student")){ //check logic is 1 print the score of that student
            printf("ID: %s   Name: %s %s\nScore:\n \tEnglish: %.2f\n \tMathematics: %.2f\n \tScience: %.2f\n \tComputer: %.2f\n \tHistory: %.2f\n",rec1.user,rec1.name,rec1.last,rec1.eng, rec1.math, rec1.sci, rec1.com, rec1.his);
            printf("------------------------------------------------------------------------\n");
        }
    }
    fclose(fp);
    printf("\n\n                        Press any key to continue!");
    getch();
    system("cls");
    teacher();
}

/* This is Student Part */
void student(){
    int choice;
    printf("Hello %s You are %s\n", sign.name, sign.career);
    printf("------------------------------\n");
    printf("1: View your score\n");
    printf("2: Exit\n");
    printf("Choose your choice: ");
    scanf("%d",&choice);

    switch(choice){
        case 1:
            viewScore();
            break;
        case 2:
            mainScreen();
            break;
        default:
            printf("\n**  Invalid Choice  **\n\n\n");
            printf("Press any key to continue...\n");
            getch();
            system("cls");
            student();
            break;
    }
}

//ViewScore function
void viewScore(){
    int count = 0; 
    s_eng.max= FLT_MIN, s_math.max= FLT_MIN, s_sci.max= FLT_MIN, s_com.max= FLT_MIN, s_his.max= FLT_MIN, s_all.max = FLT_MIN;
    s_eng.min = FLT_MAX, s_math.min = FLT_MAX, s_sci.min = FLT_MAX, s_com.min = FLT_MAX, s_his.min = FLT_MAX, s_all.min = FLT_MAX;
    s_eng.avg = 0, s_math.avg = 0, s_sci.avg = 0, s_com.avg = 0, s_his.avg = 0, s_all.avg = 0;
    
    float total = 0;
    total += sign.eng + sign.math + sign.sci + sign.com + sign.his;
    system("cls");
    printf("============================== My Score ==============================\n\n");
    printf("Name: %s %s\n\n", sign.name, sign.last);
    printf("English     : %.2f\n", sign.eng);
    printf("Mathematics : %.2f\n", sign.math);
    printf("Science     : %.2f\n", sign.sci);
    printf("Computer    : %.2f\n", sign.com);
    printf("History     : %.2f\n\n", sign.his);
    printf("Average       : %.2f\n\n\n", total/5);

    FILE *fp;
    fp = fopen("../data/record.txt", "r");
    while(fscanf(fp,"%s %s %s %s %s %f %f %f %f %f",rec1.name,rec1.last,rec1.user,rec1.pass,rec1.career,&rec1.eng, &rec1.math, &rec1.sci, &rec1.com, &rec1.his) != EOF){ //It will scan in ../data/record.txt until it can not find the ../data.
        if(!strcmp(rec1.career, "Student")){ //check logic is 1 print the score of that student
            float total = 0;
            total = (rec1.eng + rec1.math + rec1.sci + rec1.com + rec1.his)/5;
            if(total > s_all.max) s_all.max = total;
            if(total < s_all.min) s_all.min = total;
            

            if(rec1.eng > s_eng.max) s_eng.max = rec1.eng;
            if(rec1.math > s_math.max) s_math.max = rec1.math;
            if(rec1.sci > s_sci.max) s_sci.max = rec1.sci;
            if(rec1.com > s_com.max) s_com.max = rec1.com;
            if(rec1.his > s_his.max) s_his.max = rec1.his;

            if(rec1.eng < s_eng.min) s_eng.min = rec1.eng;
            if(rec1.math < s_math.min) s_math.min = rec1.math;
            if(rec1.sci < s_sci.min) s_sci.min = rec1.sci;
            if(rec1.com < s_com.min) s_com.min = rec1.com;
            if(rec1.his < s_his.min) s_his.min = rec1.his;

            s_eng.avg += rec1.eng;
            s_math.avg += rec1.math;
            s_sci.avg += rec1.sci;
            s_com.avg += rec1.com;
            s_his.avg += rec1.his;
            s_all.avg += total;


            count++;
        }
    }
    s_eng.avg /= count;
    s_math.avg /= count;
    s_sci.avg /= count;
    s_com.avg /= count;
    s_his.avg /= count;
    s_all.avg /= count;
    
    


    printf("============================== Statistics ==============================\n\n");
    printf(" English: \n");
    printf("\tMAX: %.2f\n\tMIN: %.2f\n\tAVG: %.2f\n\n", s_eng.max, s_eng.min, s_eng.avg);
    printf("------------------------------------------------------------------------\n");
    printf(" Mathematics: \n");
    printf("\tMAX: %.2f\n\tMIN: %.2f\n\tAVG: %.2f\n\n", s_math.max, s_math.min, s_math.avg);
    printf("------------------------------------------------------------------------\n");
    printf(" Science: \n");
    printf("\tMAX: %.2f\n\tMIN: %.2f\n\tAVG: %.2f\n\n", s_sci.max, s_sci.min, s_sci.avg);
    printf("------------------------------------------------------------------------\n");
    printf(" Computer: \n");
    printf("\tMAX: %.2f\n\tMIN: %.2f\n\tAVG: %.2f\n\n", s_com.max, s_com.min, s_com.avg);
    printf("------------------------------------------------------------------------\n");
    printf(" History: \n");
    printf("\tMAX: %.2f\n\tMIN: %.2f\n\tAVG: %.2f\n\n", s_his.max, s_his.min, s_his.avg);
    printf("------------------------------------------------------------------------\n\n");
    printf("[Overall] MAX: %.2f    MIN: %.2f   AVG: %.2f\n", s_all.max, s_all.min, s_all.avg);

    fclose(fp);
    printf("\n\n                        Press any key to continue!");
    getch();
    system("cls");
    student();
    
}

//Statistics Function
//(each subject)Max Min AVG, (all subject)Max Min AVG
void stat(){
    int count = 0; 
    s_eng.max= FLT_MIN, s_math.max= FLT_MIN, s_sci.max= FLT_MIN, s_com.max= FLT_MIN, s_his.max= FLT_MIN, s_all.max = FLT_MIN;
    s_eng.min = FLT_MAX, s_math.min = FLT_MAX, s_sci.min = FLT_MAX, s_com.min = FLT_MAX, s_his.min = FLT_MAX, s_all.min = FLT_MAX;
    s_eng.avg = 0, s_math.avg = 0, s_sci.avg = 0, s_com.avg = 0, s_his.avg = 0, s_all.avg = 0;
    
    FILE *fp;
    fp = fopen("../data/record.txt", "r");
    while(fscanf(fp,"%s %s %s %s %s %f %f %f %f %f",rec1.name,rec1.last,rec1.user,rec1.pass,rec1.career,&rec1.eng, &rec1.math, &rec1.sci, &rec1.com, &rec1.his) != EOF){ //It will scan in ../data/record.txt until it can not find the ../data.
        if(!strcmp(rec1.career, "Student")){ //check logic is 1 print the score of that student
            // printf("StudentName: %s\n", rec1.name);
            isStu = 1;
            float total = 0;
            total = (rec1.eng + rec1.math + rec1.sci + rec1.com + rec1.his)/5;
            if(total > s_all.max) s_all.max = total;
            if(total < s_all.min) s_all.min = total;
            

            if(rec1.eng > s_eng.max) s_eng.max = rec1.eng;
            if(rec1.math > s_math.max) s_math.max = rec1.math;
            if(rec1.sci > s_sci.max) s_sci.max = rec1.sci;
            if(rec1.com > s_com.max) s_com.max = rec1.com;
            if(rec1.his > s_his.max) s_his.max = rec1.his;

            if(rec1.eng < s_eng.min) s_eng.min = rec1.eng;
            if(rec1.math < s_math.min) s_math.min = rec1.math;
            if(rec1.sci < s_sci.min) s_sci.min = rec1.sci;
            if(rec1.com < s_com.min) s_com.min = rec1.com;
            if(rec1.his < s_his.min) s_his.min = rec1.his;

            s_eng.avg += rec1.eng;
            s_math.avg += rec1.math;
            s_sci.avg += rec1.sci;
            s_com.avg += rec1.com;
            s_his.avg += rec1.his;
            s_all.avg += total;


            count++;
        }
    }
    s_eng.avg /= count;
    s_math.avg /= count;
    s_sci.avg /= count;
    s_com.avg /= count;
    s_his.avg /= count;
    s_all.avg /= count;

    printf("============================== Statistics ==============================\n\n");
    printf(" English: \n");
    printf("\tMAX: %.2f\n\tMIN: %.2f\n\tAVG: %.2f\n\n", s_eng.max, s_eng.min, s_eng.avg);
    printf("------------------------------------------------------------------------\n");
    printf(" Mathematics: \n");
    printf("\tMAX: %.2f\n\tMIN: %.2f\n\tAVG: %.2f\n\n", s_math.max, s_math.min, s_math.avg);
    printf("------------------------------------------------------------------------\n");
    printf(" Science: \n");
    printf("\tMAX: %.2f\n\tMIN: %.2f\n\tAVG: %.2f\n\n", s_sci.max, s_sci.min, s_sci.avg);
    printf("------------------------------------------------------------------------\n");
    printf(" Computer: \n");
    printf("\tMAX: %.2f\n\tMIN: %.2f\n\tAVG: %.2f\n\n", s_com.max, s_com.min, s_com.avg);
    printf("------------------------------------------------------------------------\n");
    printf(" History: \n");
    printf("\tMAX: %.2f\n\tMIN: %.2f\n\tAVG: %.2f\n\n", s_his.max, s_his.min, s_his.avg);
    printf("------------------------------------------------------------------------\n\n");
    printf("[Overall] MAX: %.2f    MIN: %.2f   AVG: %.2f\n", s_all.max, s_all.min, s_all.avg);

    fclose(fp);
    printf("\n\n                        Press any key to continue!");
    getch();
    system("cls");
    teacher();
    
}

//View Score Function
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
        default :
            printf("**  Invalid choice please enter again   **\n\n");
            printf("Press any key to continue...");
            getch();
            mainScreen();
    }
}