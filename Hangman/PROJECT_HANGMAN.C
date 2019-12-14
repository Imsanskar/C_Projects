
#include<stdio.h>

//#include <stdlib.h>

#include<string.h>

#include<windows.h>

#include <time.h>

#include <conio.h>


float cpu_time;
char ch[50];
char name[15];



void hangman(int);

void display()
{
    int c;
    FILE *file;
    file=fopen("record.txt","r");
    while((c=getc(file)) != EOF)
    putchar(c);
    fclose(file);
}

void store()
{
    FILE *fp;
    fp=fopen("record.txt","a");
    fflush(stdin);
    fputs("\t",fp);
    fputs(name,fp);
    fputs("\t\t\t",fp);
    fputs(ch,fp);
    fputs("\n",fp);
    fclose(fp);
}


void hangman(int n)
 {
     char c;

     switch(n)
     {

     case 0:
         while(c!=13)
    {

         do{

    system("color 4");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||    | ");
	printf("\n\t||   / %c",'\\');
	printf("\n\t||      ");
	system("color 7");
	//break;
    Sleep(500);
system("cls");


}
while(!kbhit());
  c=getch();


}
	break;

/*system("color 4");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||    | ");
	printf("\n\t||   / %c",'\\');
	printf("\n\t||      ");
	system("color 7");
	break; */
     case 1:

	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||    | ");
	printf("\n\t||     %c",'\\');
	printf("\n\t||      ");
	break;
     case 2:


	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||    | ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	break;
     case 3:

	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	break;
     case 4:

	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO ",'\\');
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	break;
     case 5:

	printf("\n\t                                                                                               == ||| ");
	printf("\n\t                                                                                               |  |||     ");
	printf("\n\t                                                                                               O  |||    ");
	printf("\n\t                                                                                                  |||    ");
	printf("\n\t                                                                                                  |||      ");
	printf("\n\t                                                                                                  |||     ");
	break;
      }
      return;
 }






 int main()
{
    clock_t start,end;
    char givenword[20], compare[20],guessedword,output[20];

    int wrongTry = 6 , matchFound = 0;
    int j = 0 , type= 0, finished, length , i;
     char c,d;
     printf("Enter space to view the stats  :\n");
     d=getch();
     if (d==32)
     {
         display();
     }
     printf("\n Enter your good name :)  ");
     scanf("%s",name);


     start=clock();

    system("cls");
    printf("\n\n Enter any word in small  letter   \n");

    scanf("%s",givenword);


    getchar();
    length = strlen(givenword);

    system("cls");
    while(c!=13)
    {


do{



    printf("\n\                                             ****Welcome to the Hangman****      \n \n\n\n\n\n\n  \n \n\n\n\n\n\n  \n \n\n\n\n\n\n  \n \n\n\n\n\n\n Press 'ENTER' to contunue ");

    Sleep(500);
system("cls");
Sleep(500);
}
while(!kbhit());
  c=getch();

    }


printf("\n You will get 5 chances to guess the right word");

    getchar();

    system("cls");

        printf("\n\t                                                                                            =======|||");
	    printf("\n\t                                                                                                   |||     ");
        printf("\n\t                                                                                                   |||      ");
        printf("\n\t                                                                                                   |||      ");
        printf("\n\t                                                                                                   |||      ");
        printf("\n\t                                                                                                   |||      ");

    printf("\n\n     The word has %d alphabets \n\n",length);
    for( i = 0; i < length ; i++)
    {
        output[i] = '_';
        output[length] = '\0';
    }

    for(i = 0 ; i < length ; i++)
    {
        printf(" ");
        printf("%c",output[i]);

    }
    while(wrongTry != 0)
    {
        matchFound = 0;
        printf("\n\n   enter any alphabet from a to z    \n\n");


	    fflush(stdin);

	    scanf("%c",&guessedword);
    if(guessedword < 'a' || guessedword > 'z')
    {
        system("cls");
        printf("\n\n\  plesae input again \n\n");
        matchFound = 2;
    }
    fflush(stdin);
    if (matchFound != 2)
    {
        for(j=0;j<length;j++)
	    {
		    if(guessedword==givenword[j])
		     {
		       matchFound = 1;
                     }
            }

	   if(matchFound == 0)
	    {
	        printf("\n Wrong guess \n ");
     	      printf("\n\t You have  %d tries left    ",--wrongTry);

              hangman(wrongTry);
              getchar();
              system("cls");
	    }
	   else
	   {
	     for(j = 0; j < length; j++)
             {
     	         matchFound = 0;
                 if(guessedword == givenword[j])
	          {
     		     type= j ;
     		     matchFound = 1;
	          }
    	      if(matchFound == 1)
	          {
                 for(i = 0 ; i < length ; i++)
                 {
                      if( i == type)
                  	  {
                          output[i] = guessedword;
                      }

                    else if( output[i] >= 'a' && output[i] <= 'z' )


                      {
                          continue;
                  	  }

                      else
                      {
                          output[i] = '_';
                      }
                }
                compare[type] = guessedword;
                compare[length] = '\0';
                finished = strcmp(compare,givenword);

                if(finished == 0)
                {
                    printf("\n\n\t  Congratulation !!!!  You won ");
                    printf("\n\n\t The Word is  %s ",givenword);
                    printf("\n\n\t\Thank you for playing \n");
                     end=clock();
                    cpu_time=((float)(end-start))/CLOCKS_PER_SEC;
                    printf("You took %f to complete the game",cpu_time);
                    gcvt(cpu_time,6,ch);
                    store();
                    return 0;


                    getchar();
                }
	       }
	    }
      }
     }

    printf("\n\n\t");
    for(i = 0 ; i < length ; i++)
      {
          printf(" ");
          printf("%c",output[i]);
      }

    getchar();
    }

      if(wrongTry <= 0)
      {
          printf("sorry you couldn't guess it right");
          printf("\n\n\t The Word was %s ",givenword);

	      printf("\n\n\t Better luck next time ");

      }

getchar();
      end=clock();
      cpu_time=((float)(end-start))/CLOCKS_PER_SEC;
      printf("You took %f seconds to complete the game",cpu_time);
      gcvt(cpu_time,6,ch);
      store();

                    getchar();
                    return 0;
}




