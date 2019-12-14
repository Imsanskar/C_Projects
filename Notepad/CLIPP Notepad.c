#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

int password();
void addnote();
void viewnote();
void editnote();
/*void editpassword();*/
void deletenote();

struct note
{
    char name[50];
    char note[500];
} ;

int main()
{
    int ch;
    printf("\n\n\t***********************************\n");
    printf("\t*CLIPP Notepad*\n");
    printf("\t***********************************");

   while(1)

        {
                printf("\n\n\t\tMAIN MENU:");
                printf("\n\n\tADD NOTE\t[1]");
                printf("\n\tVIEW NOTE\t[2]");
                printf("\n\tEDIT NOTE\t[3]");
                printf("\n\tDELETE NOTE\t[4]");
                /*printf("\n\tEDIT PASSWORD\t[5]");*/
                printf("\n\tEXIT\t\t[6]");
                printf("\n\n\tENTER YOUR CHOICE:");
                scanf("%d",&ch);

            switch(ch)
                    {
                            case 1:
                            addnote();
                            break;

                            case 2:
                            viewnote();
                            break;

                            case 3:
                            editnote();
                            break;

                            case 4:
                            deletenote();
                            break;

                            /*case 5:
                            editpassword();
                            break;*/

                            case 6:
                            printf("\n\n\t\tTHANK YOU FOR USING THE SOFTWARE BY:\n\n\tRIYA RATHORE...");
                            getch();
                            exit(0);

                            default:
                            printf("\nYOU ENTERED WRONG CHOICE..");
                            printf("\nPRESS ANY KEY TO TRY AGAIN");
                            getch();
                            break;
                    }
                system("cls");
        }
            return 0;
}
void addnote( )
{
                system("cls");
                FILE *fp ;
                char another = 'Y';
                struct note e ;
                char filename[50];
                char *namelist="";
                int choice;
                printf("\n\n\t\t***************************\n");
                printf("\t\t* WELCOME TO THE ADD MENU *");
                printf("\n\t\t***************************\n\n");
                while ( another == 'Y'|| another=='y' )
                {
                choice=0;
                printf("\n\n\tENTER NAME OF YOUR NOTE(MAX 50 CHARACTERS):");
                fflush(stdin);
                gets(filename);
                strcpy(e.name,filename);
                fp = fopen (filename, "ab+" ) ;
                if ( fp == NULL )
                {
                fp=fopen(filename,"wb+");
                if(fp==NULL)
                {
                    printf("\nSYSTEM ERROR...");
                    printf("\nPRESS ANY KEY TO EXIT");
                    getch();
                    return ;
                }
                }
                while(fread(&e,sizeof(e),1,fp)==1)
                {
                    if(strcmp(e.name,filename)==0)
                    {
                        printf("\n\tTHE NOTE ALREADY EXISTS.\n");
                        choice=1;
                    }
                }
                    if(choice==0)
                    {
                        fflush(stdin);
                        printf("\tNOTE:");
                        fflush(stdin);
                        gets(e.note);
                        fwrite ( &e, sizeof ( e ), 1, fp ) ;
                        printf("\nYOUR note IS ADDED...\n");
                    }
                        printf ( "\n\tADD ANOTHER note...(Y/N) " ) ;
                        fflush ( stdin ) ;
                        another = getchar( ) ;
                }

                fclose ( fp ) ;
                printf("\n\n\tPRESS ANY KEY TO EXIT...");
                getch();
    }

void viewnote( )
{
        FILE *fpte ;
        system("cls");
        struct note customer ;
        char choice,filename[50];
        printf("\n\n\t\t*******************************\n");
        printf("\t\t* HERE IS THE VIEWING MENU *");
        printf("\n\t\t*******************************\n\n");
        //choice=password();
        if(choice!=0)
            {
                return ;
            }
        do
            {
                    printf("\n\tENTER THE NOTE TO BE VIEWED:");
                    fflush(stdin);
                    gets(filename);

                    fpte = fopen ( filename, "rb" ) ;
                    if ( fpte == NULL )
                            {
                                puts ( "\nTHE NOTE DOES NOT EXIST...\n" ) ;
                                printf("PRESS ANY KEY TO EXIT...");
                                getch();
                                return ;
                            }
                            system("cls");
                            while ( fread ( &customer, sizeof ( customer ), 1, fpte ) == 1 )
                            {
                                if(strcmp(customer.name,filename)==0)
                                {
                                    printf("\nYOUR NOTE IS:\n%s",customer.note);
                                }
                        }

               printf("\n\nWOULD YOU LIKE TO CONTINUE VIEWING...(Y/N):");
               fflush(stdin);
            scanf("%c",&choice);
        }while(choice=='Y'||choice=='y');
            fclose ( fpte ) ;
            return ;
}
void editnote()
{
        system("cls");
        FILE *fpte ;
        struct note customer ;
        char choice,filename[50];
        int num,count=0;
        printf("\n\n\t\t*******************************\n");
        printf("\t\t* WELCOME TO THE EDITING MENU *");
        printf("\n\t\t*******************************\n\n");
        //choice=password();
        if(choice!=0)
            {
                return ;
            }
        do
            {
                    printf("\n\tENTER THE NAME OF NOTE TO BE EDITED:");
                    fflush(stdin);
                    gets(filename);
                    fpte = fopen ( filename, "rb+" ) ;
                    if ( fpte == NULL )
                            {
                                printf( "\nNOTE DOES NOT EXISTS:" ) ;
                                printf("\nPRESS ANY KEY TO GO BACK");
                                getch();
                                return;
                            }
                    while ( fread ( &customer, sizeof ( customer ), 1, fpte ) == 1 )
                    {
                        if(strcmp(customer.name,filename)==0)
                        {
                            printf("\nYOUR OLD NOTE WAS AS:");
                            printf("\nNOTE: %s",customer.note);

                            printf("\n\n\t\t1.WANT TO EDIT..");
                            printf("\n\t\t2.GO BACK TO MAIN MENU.\n");
                                do
                                {
                                        printf("\n\tENTER YOUR CHOICE:");
                                        fflush(stdin);
                                        scanf("%d",&num);
                                        fflush(stdin);
                                        switch(num)
                                        {
                                            case 1: printf("ENTER THE NEW NOTE:");
                                                    printf("\nNOTE:");
                                                    gets(customer.note);
                                                    break;

                                            case 2: printf("\nPRESS ANY KEY TO GO BACK...\n");
                                                    getch();
                                                    return ;
                                                    break;

                                            default: printf("\nYOU TYPED SOMETHING ELSE...TRY AGAIN\n");
                                                     break;
                                        }

                                }while(num<1||num>2);
                            fseek(fpte,-sizeof(customer),SEEK_CUR);
                            fwrite(&customer,sizeof(customer),1,fpte);
                            fseek(fpte,-sizeof(customer),SEEK_CUR);
                            fread(&customer,sizeof(customer),1,fpte);
                            choice=5;
                            break;
                        }
                    }
                    if(choice==5)
                    {
                    system("cls");
                    printf("\n\t\tEDITING COMPLETED...\n");
                    printf("--------------------\n");
                    printf("THE NEW NOTE IS:\n");
                    printf("--------------------\n");
                    printf("\nNOTE: %s",customer.note);
                    fclose(fpte);
                    printf("\n\n\tWOULD YOU LIKE TO EDIT ANOTHER NOTE.(Y/N)");
                    scanf("%c",&choice);
                    count++;
                    }
                    else
                    {
                        printf("\nTHE NOTE DOES NOT EXIST::\n");
                        printf("\nWOULD YOU LIKE TO TRY AGAIN...(Y/N)");
                        scanf("%c",&choice);
                    }

            }while(choice=='Y'||choice=='y');
            fclose ( fpte ) ;

            if(count==1)
            printf("\n%d NOTE IS EDITED...\n",count);
            else if(count>1)
            printf("\n%d NOTES ARE EDITED..\n",count);
            else
            printf("\nNO NOTES EDITED...\n");
            printf("\tPRESS ENTER TO EXIT EDITING MENU.");
            getch();
}
/*int password()
{
        char pass[15]={0},check[15]={0},ch;
        FILE *fpp;
        int i=0,j;
        printf("::FOR SECURITY PURPOSE::");
        printf("::ONLY THREE TRIALS ARE ALLOWED::");
        for(j=0;j<3;j++)
        {
                        i=0;
                        printf("\n\n\tENTER THE PASSWORD:");
                        pass[0]=getch();
                        while(pass[i]!='\r')
                        {
                            if(pass[i]=='\b')
                            {
                                i--;
                                printf("\b");
                                printf(" ");
                                printf("\b");
                                pass[i]=getch();
                            }
                            else
                            {
                                printf("*");
                                i++;
                                pass[i]=getch();
                            }
                        }
                        pass[i]='\0';
                        fpp=fopen("SE","r");
                        if (fpp==NULL)
                        {
                            printf("\nPlease edit your password before doing anything else.\n");
                            getch();
                            return 1;
                        }
                        else
                        i=0;
                        while(1)
                        {
                            ch=fgetc(fpp);
                            if(ch==EOF)
                            {
                                check[i]='\0';
                                break;
                            }
                            check[i]=ch-5;
                            i++;
                        }
                        if(strcmp(pass,check)==0)
                        {
                            printf("\n\n\tACCESS GRANTED...\n");
                            return 0;
                        }
                        else
                        {
                            printf("\n\n\tWRONG PASSWORD..\n\n\tACCESS DENIED...\n");
                        }
        }
        printf("\n\n\t::YOU ENTERED WRONG PASSWORD::YOU ARE NOT ALLOWED TO ACCESS ANY FILE::\n\n\tPRESS ANY KEY TO GO BACK...");
        getch();
        return 1;
}
void editpassword()
{
    system("cls");
    printf("\n");
    char pass[15]={0},confirm[15]={0},ch;
    int choice,i,check;
    FILE *fp;
    fp=fopen("SE","rb");
    if(fp==NULL)
    {
        fp=fopen("SE","wb");
        if(fp==NULL)
        {
            printf("SYSTEM ERROR...");
            getch();
            return ;
        }
        fclose(fp);
        printf("\nSYSTEM RESTORED...\nYOUR PASSWORD IS 'ENTER'\n PRESS ENTER TO CHANGE PASSWORD\n\n");
        getch();
    }
        fclose(fp);
        check=password();
    if(check==1)
    {
        return ;
    }
    do
    {
        if(check==0)
                    {
                        i=0;
                        choice=0;
                        printf("\n\n\tENTER THE NEW PASSWORD:");
                        fflush(stdin);
                        pass[0]=getch();
                        while(pass[i]!='\r')
                        {
                            if(pass[i]=='\b')
                            {
                                i--;
                                printf("\b");
                                printf(" ");
                                printf("\b");
                                pass[i]=getch();
                            }
                            else
                            {
                                printf("*");
                                i++;
                                pass[i]=getch();
                            }
                        }
                        pass[i]='\0';
                        i=0;
                        printf("\n\tCONFIRM PASSWORD:");
                        confirm[0]=getch();
                        while(confirm[i]!='\r')
                        {
                            if(confirm[i]=='\b')
                            {
                                i--;
                                printf("\b");
                                printf(" ");
                                printf("\b");
                                confirm[i]=getch();
                            }
                            else
                            {
                                printf("*");
                                i++;
                                confirm[i]=getch();
                            }
                        }
                        confirm[i]='\0';
                        if(strcmp(pass,confirm)==0)
                        {
                            fp=fopen("SE","wb");
                            if(fp==NULL)
                            {
                                printf("\n\t\tSYSTEM ERROR");
                                getch();
                                return ;
                            }
                            i=0;
                            while(pass[i]!='\0')
                            {
                                ch=pass[i];
                                putc(ch+5,fp);
                                i++;
                            }
                            putc(EOF,fp);
                            fclose(fp);
                        }
                        else
                        {
                            printf("\n\tTHE NEW PASSWORD DOES NOT MATCH.");
                            choice=1;

                        }

                    }
}while(choice==1);

    printf("\n\n\tPASSWORD CHANGED...\n\n\tPRESS ANY KEY TO GO BACK...");
    getch();
}*/

void deletenote( )
{
                system("cls");
                FILE *fp,*fptr ;
                struct note file ;
                char filename[50],another = 'Y';
                int choice,check;
                printf("\n\n\t\t*************************\n");
                printf("\t\t* WELCOME TO DELETE MENU*");
                printf("\n\t\t*************************\n\n");
                //check = password();
                    if(check==1)
                    {
                        return ;
                    }

                while ( another == 'Y' )
                {
                            printf("\n\tENTER THE NAME OF NOTE TO BE DELETED:");
                            fflush(stdin);
                            gets(filename);
                            fp = fopen (filename, "wb" ) ;
                            if ( fp == NULL )
                            {
                                printf("\nTHE FILE DOES NOT EXISTS");
                                printf("\nPRESS ANY KEY TO GO BACK.");
                                getch();
                                return ;
                            }
                            fclose(fp);
                            remove(filename);
                            printf("\nDELETED SUCCESFULLY...");
                    printf("\n\tDO YOU LIKE TO DELETE ANOTHER note.(Y/N):");
                    fflush(stdin);
                    scanf("%c",&another);
                }
                printf("\n\n\tPRESS ANY KEY TO EXIT...");
                getch();
}
