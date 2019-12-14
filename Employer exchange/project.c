#include <stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<windows.h>
#include<dos.h>
#include<time.h>

void employee();
void employer();
void help();
void complain();
void t();
void password();
void exits();
void creators();

struct info
{
    char name[100],qual[300],exp[300],cont[12],email[100],field[100],job[100],salary[50];
    int id, age;
};

struct info emp1,emp2;

FILE *f1,*f2,*f3;

COORD coord={0,0};
void gotoxy(int x, int y)
{
    coord.X = x; coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void main()
{
    system("cls");
    gotoxy(20,3);
    printf("*********************************** LAND A JOB ***********************************");
    gotoxy(56,5);
    printf("MAIN MENU");
    gotoxy(20,6);
    printf("===================================================================================\n");
    gotoxy(20,8);
    printf("1.Information of Employee");
    gotoxy(20,10);
    printf("2.Information of Employer");
    gotoxy(20,12);
    printf("3.Help and Support");
    gotoxy(20,14);
    printf("4.Complaints and Suggestions");
    gotoxy(20,16);
    printf("5.Exit");
    gotoxy(20,17);
    printf("===================================================================================\n");
    t();
    abc:
    gotoxy(20,21);
    printf("Enter your choice: ");
    switch(getch())
    {
        case '1':
        employee();
        break;
        case '2':
        employer();
        break;
        case '3':
        help();
        break;
        case '4':
        complain();
        break;
        case '5':
        creators();
        break;
        default:
        {

            gotoxy(20,22);
            printf("Wrong Entry!!Please re-enter correct option");
            if(getch())
            goto abc;
        }
    }
}

void employee()
{
    system("cls");
    int c;
    char ch;
    gotoxy(40,3);
    printf("Employee's Block");
    gotoxy(20,4);
    printf("================================================================");
    gotoxy(20,6);
    printf("1. Existing Records");
    gotoxy(20,8);
    printf("2. Add New Records");
    gotoxy(20,10);
    printf("3. Check Your Status");
    gotoxy(20,12);
    printf("Enter your choice: ");
    scanf("%d",&c);
    if(c==2)
    {
        system("cls");
        struct info emp1;
            f1=fopen("compe.txt","a");
            if(f1==NULL)
            {
                gotoxy(40,10);
                printf("\n Error Opening File");
                exits();
            }
            gotoxy(40,3);
            printf("FILL UP THE DETAILS");
            gotoxy(20,4);
            printf("================================================================");
            gotoxy(20,6);
            printf("ID NUMBER :: ");
            scanf("%d",&emp1.id);
            gotoxy(20,8);
            printf("NAME :: ");
            fflush(stdin);
            gets(emp1.name);
            gotoxy(20,10);
            printf("AGE :: ");
            scanf("%d",&emp1.age);
            gotoxy(20,12);
            printf("ACADEMIC QUALIFICATION :: ");
            fflush(stdin);
            gets(emp1.qual);
            gotoxy(20,14);
            printf("EXPECTED JOB :: ");
            fflush(stdin);
            gets(emp1.job);
            gotoxy(20,16);
            printf("EXPERIENCE :: ");
            fflush(stdin);
            gets(emp1.exp);
            gotoxy(20,18);
            printf("EXPECTED SALARY :: ");
            fflush(stdin);
            gets(emp1.salary);
            gotoxy(20,20);
            printf("CONTACT NUMBER :: ");
            fflush(stdin);
            gets(emp1.cont);
            gotoxy(20,22);
            printf("EMAIL :: ");
            fflush(stdin);
            gets(emp1.email);
            gotoxy(20,24);
            printf("---------------------Your record has been stored-------------------\n");
            fprintf(f1,"\n ID :: %d\n NAME :: %s\n AGE :: %d\n ACADEMIC QUALIFICATION :: %s\n EXPERIENCE :: %s\n CONTACT NUMBER :: %s\n EMAIL :: %s\n\n*************************************\n",emp1.id,emp1.name,emp1.age,emp1.qual,emp1.exp,emp1.cont,emp1.email);
            exits();
            fclose(f1);
    }
    if(c==1)
    {
        password();
        system("cls");
        f1=fopen("compe.txt","r");
        if(f1==NULL)
        {
            gotoxy(40,8);
            printf(" Error Opening File\n");
            exits();
        }
        char ch;
        printf("\n RESUME OF JOB SEEKERS\n");
        printf("==========================");
         while( ch != EOF)
        {
            ch = fgetc(f1);
            printf("%c",ch);
        }
        fclose(f1);
        exits();
    }
    if(c==3)
    {
        system("cls");
        f3=fopen("comadd.txt","r");
        if(f3==NULL)
        {
            gotoxy(40,10);
            printf(" Error Opening File\n");
            exits();
        }
        printf("\n  The details of the shortlisted candidates by different companies are given below.");
        printf("\n  Search for your ID\n");
        char ch2;
        printf(" \n\n DETAILS OF SHORTLISTED CANDIDATES\n");
        printf("============================================\n");
        while( ch2 != EOF)
        {
            ch2 = fgetc(f3);
            printf("%c",ch2);
        }
        fclose(f3);
        int b;
        printf("\n\nDo you find your ID(1/0)?? ");
        scanf("%d",&b);
        if(b==1)
        {
            system("cls");
            gotoxy(40,8);
            printf("*********Congratulations***********");
            gotoxy(45,9);
            printf("Best of Luck for Interview\n\n\n");
        }
        if(b==0)
        {
            system("cls");
            gotoxy(40,8);
            printf("----------Sorry----------");
            gotoxy(42,9);
            printf("Check sometime later\n\n");
        }
        exits();
    }
}

void employer()
{
    system("cls");
    int c,idn;
    gotoxy(40,3);
    printf("Employer's Block");
    gotoxy(20,4);
    printf("=========================================================");
    gotoxy(20,6);
    printf("1. Existing Records");
    gotoxy(20,8);
    printf("2. Add New Records");
    gotoxy(20,10);
    printf("3. Call for an interview");
    gotoxy(20,12);
    printf("4. View shortlisted candidates");
    gotoxy(20,14);
    printf("Enter your choice: ");
    scanf("%d",&c);
    if(c==2)
    {
        password();
        system("cls");
        struct info emp2;
            f2=fopen("compa.txt","a");
            if(f2==NULL)
            {
                gotoxy(40,10);
                printf(" Error Opening File");
                exits();
            }
            gotoxy(40,3);
            printf("FILL UP THE DETAILS");
            gotoxy(20,4);
            printf("================================================================");
            gotoxy(20,6);
            printf("NAME OF THE COMPANY :: ");
            fflush(stdin);
            gets(emp2.name);
            gotoxy(20,8);
            printf("RELATED FIELD :: ");
            fflush(stdin);
            gets(emp2.field);
            gotoxy(20,10);
            printf("VACANT POST :: ");
            fflush(stdin);
            gets(emp2.job);
            gotoxy(20,12);
            printf("REQUIRED ACADEMIC QUALIFICATION :: ");
            fflush(stdin);
            gets(emp2.qual);
            gotoxy(20,14);
            printf("REQUIRED EXPERIENCE :: ");
            fflush(stdin);
            gets(emp2.exp);
            gotoxy(20,16);
            printf("SALARY :: ");
            fflush(stdin);
            gets(emp2.salary);
            gotoxy(20,18);
            printf("---------------------Your record has been stored-------------------\n");
            fprintf(f2,"\n NAME OF THE COMPANY :: %s\n RELATED FIELD :: %s\n VACANT POST :: %s\n REQUIRED ACADEMIC QUALIFICATION :: %s\n REQUIRED EXPERIENCE :: %s\n SALARY :: Rs.%s\n********************************************\n",emp2.name,emp2.field,emp2.job,emp2.qual,emp2.exp,emp2.salary);
            fclose(f2);
            exits();
    }
    if(c==1)
    {
        system("cls");
        FILE *f2;
        f2=fopen("compa.txt","rb");
        if(f2==NULL)
        {
            gotoxy(40,10);
            printf(" Error Opening File");
            exits();
        }
        char ch;
        printf("\n DETAILS OF COMPANIES\n");
        printf("===================================");
         while( ch != EOF)
        {
            ch = fgetc(f2);
            printf("%c",ch);
        }
        fclose(f2);
        exits();
    }
    if(c==3)
    {
        password();
        system("cls");
        f1=fopen("compe.txt","r");
        if(f1==NULL)
        {
            gotoxy(40,8);
            printf(" Error Opening File");
            exits();
        }
        char ch;
        printf("\n\n Information of the candidates:\n");
        printf("====================================\n");
        while( ch != EOF)
        {
            ch = fgetc(f1);
            printf("%c",ch);
        }
        fclose(f1);
        char company[100],idn[15],ans;
        printf("\n Enter the Name of your Company :: ");
        fflush(stdin);
        gets(company);
        re:
        printf("\n Enter the id of the candidate you like :: ");
        fflush(stdin);
        gets(idn);
        f3=fopen("comadd.txt", "a");
        fprintf(f3,"\n The %s has invited the applicant of ID %s for the interview.\n",company,idn);
        printf("\n You have successfully shortlisted a candidate. \n");
        printf(" Do you want to shortlist one more candidate(y/n)?? ");
        scanf("%c",&ans);
        if(tolower(ans)=='y')
        {
            goto re;
        }
        fclose(f3);
    exits();
    }
    if(c==4)
    {
        system("cls");
        f3=fopen("comadd.txt","r");
        if(f3==NULL)
        {
            gotoxy(40,8);
            printf("\n Error Opening File\n");
            exits();
        }
        char ch2;
        printf("\n\n DETAILS OF SHORTLISTED CANDIDATES\n");
        printf(" ========================================\n");
        while( ch2 != EOF)
        {
            ch2 = fgetc(f3);
            printf("%c",ch2);
        }
        fclose(f2);
    }
    exits();
}

void complain()
{
    system("cls");
    char com[500];
    FILE *f;
    f=fopen("suggest.txt","a");
    gotoxy(35,3);
    printf("ANY SUGGESTIONS OR COMPLAINS ");
    gotoxy(25,4);
    printf("================================================\n");
    fflush(stdin);
    gotoxy(10,6);
    gets(com);
    fprintf(f,"%s\n\n",com);
    gotoxy(10,15);
    printf("Your complains have been submitted. We will try our best to resolve the problems.\n\n");
    fclose(f);
    exits();
}

void help()
{
    system("cls");
    gotoxy(38,3);
    printf("HELP AND SUPPORT");
    gotoxy(28,4);
    printf("================================================\n");
    gotoxy(10,5);
    printf("This program is designed to aid in the process of getting job and hiring employees.");
    gotoxy(5,6);
    printf("You can enter your credentials and can check your status to know if you have been shortlisted or not. ");
    gotoxy(15,7);
    printf("The details about the candidates can only accessed by the companies.\n\n");
    exits();
}

void t()
{
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char s[50];
    strftime(s, sizeof(s), "%c", tm);
    gotoxy(70,18);
    printf("Date and Time: %s", s);
    size_t last;
    last = strftime(s, 10, "%A", tm);
    s[last] = '\0';
    gotoxy(70,19);
    printf("Day: %s", s);
}

char passw[10]={"welcome"};
void password()
{
    system("cls");
    char d[25]=" Password Protected";
    char ch,pass[10];
    int i=0,j;
    gotoxy(20,10);
    for(j=0;j<20;j++)
    {
        Sleep(50);
        printf("*");
    }
    for(j=0;j<20;j++)
    {
        Sleep(50);
        printf("%c",d[j]);
    }
    for(j=0;j<20;j++)
    {
        Sleep(50);
        printf("*");
    }
    gotoxy(22,12);
    printf("Enter Password: ");
    while(ch!=13)
    {
        ch=getch();
        if(ch!=13 && ch!=8)
        {
            putch('*');
            pass[i] = ch;
            i++;
        }
        if(ch==8)
        {
            printf(" \b\b");
        }
    }
    pass[i] = '\0';
    if(strcmp(pass,passw)==0)
    {
        gotoxy(22,15);
        printf(" You're in.");
        gotoxy(22,16);
        printf(" Press any key to continue ");
        getch();
    }
    else
    {
        gotoxy(22,15);
        printf(" Incorrect Password");
        getch();
        password();
    }
}
void exits()
{
    char ans;
    printf("\n\n Do you want to exit(y/n)?? ");
    fflush(stdin);
    scanf("%c",&ans);
    if(tolower(ans)=='n')
    {
        main();
    }
    else
    {
        creators();
    }
}

void creators()
{
    system("cls");
    gotoxy(40,10);
    printf("Created by");
    gotoxy(40,11);
    printf("==========================");
    gotoxy(40,12);
    printf("Ranju GC");
    gotoxy(40,13);
    printf("Supriya Khadka");
    gotoxy(40,15);
    exit(0);
}
