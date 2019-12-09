#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000
void creating_your_own(char);
void read_the_created(char);
void ask_word_types(char [] ,char [],char [],char [],char [],char [],char []);
void ask_word_to(char [],char [],char [],char [],char [],char [],char []);
void display_story(int);
void display_loading();
void display_introduction();
void replaceAll(char *str,const char *oldWord, const char *newWord);

int main()
{
    display_loading();
    display_introduction();
    getchar();
     system("cls");

     int age,opt1,opt2;
     char name[20];


     printf("     \n  \n  \n \n \n\t \t\t\tEnter your name:  ");
     gets(name);


     printf("     \n  \n  \n \n \n\t \t\t\tEnter your age:  ");
     scanf("%d",&age);

     system("cls");
      label:

     printf("  \n  \n  \n \n \n\t\t\t\t \t\t\tWELCOME!");
     printf("\n\t \t\t\t ____________________________________________________________\n");
     printf("\t \t\t\t ____________________________________________________________\n");
     printf("  \n  \n  \n \n \n\t \t\t\t  Choose how you want to play the game. \n\n\t \t\t\t  1.  PLAY MADLIBS\n\n\t \t\t\t  2.  CREATE AND PLAY \n\n\n\t \t\t\t Your Choice: ");
     scanf("%d",&opt1);
     system("cls");

     if(opt1==1)
     {


         printf(" \n  \n  \n \n \n\t \t\t\t Choose the story:\n\n\t \t\t\t 1. The Letter To Her Parents\n\n\t \t\t\t 2. The Magic Story (F.R.I.E.N.D.S) \n\n\t \t\t\t 3. The Tales Of Bachelor Party\n\n\t \t\t\t 4. The Madness Of Self Intepretation \n\n\t \t\t\t 5. Smelly Cat, Smelly Cat\n\n\t \t\t\t 6. The Night She Had With Nikhil Aringal \n\n\t \t\t\t 7. Old MAC'Donald\n\n\n\t \t\t\t  Your Choice: ");
         scanf("%d",&opt2);
         system("cls");

     switch(opt2)
     {
     case 1:
        {

               FILE * fPtr;
            FILE * fTemp;

    char buffer[MAX];

    char newWord[100];
    char oldWord[100]="name1";
     printf("\n\n Give me a noun :  ");
     scanf("%s",newWord);

     char newWord1[100];
     char oldWord1[100]="name2";
     printf("\n \n Give me another noun:  ");
     scanf("%s",newWord1);

     char newWord2[100];
     char oldWord2[100]="verb1";
     printf("\n\n Give me a verb:  ");
   scanf("%s",newWord2);

   char newWord3[100];
   char oldWord3[100]="thing1";
   printf("\n \n Give me name of a thing: ");
   scanf("%s",newWord3);

   char newWord4[100];
   char oldWord4[100]="noun1";
   printf("\n\n Give me a noun: ");
   scanf("%s",newWord4);

   char newWord5[100];
   char oldWord5[100]="thing2";
   printf("\n\n Give me name of a thing: ");
   scanf("%s",newWord5);

   char newWord6[100];
   char oldWord6[100]="noun2";
   printf("\n\n Give me a noun: ");
   scanf("%s",newWord6);

   char newWord7[100];
   char oldWord7[100]="verb2";
   printf("\n\n Give me a verb: ");
   scanf("%s",newWord7);

   char newWord8[100];
   char oldWord8[100]="noun3";
   printf("\n\n Give me a noun: ");
   scanf("%s",newWord8);

   char newWord9[100];
   char oldWord9[100]="verb3";
   printf("\n\n Give me a verb: ");
   scanf("%s",newWord9);

   char oldWord10[100]="name4";



    fPtr  = fopen("story1.txt", "r");
    fTemp = fopen("replace.tmp", "w");


    while ((fgets(buffer, MAX, fPtr)) != NULL)
    {

        replaceAll(buffer, oldWord, newWord);
        replaceAll(buffer, oldWord1, newWord1);
        replaceAll(buffer, oldWord2, newWord2);
          replaceAll(buffer, oldWord3, newWord3);
        replaceAll(buffer, oldWord4, newWord4);
        replaceAll(buffer, oldWord5, newWord5);
         replaceAll(buffer, oldWord6, newWord6);
        replaceAll(buffer, oldWord7, newWord7);
        replaceAll(buffer, oldWord8, newWord8);
          replaceAll(buffer, oldWord9, newWord9);
        replaceAll(buffer, oldWord10, name);


        fputs(buffer, fTemp);
    }

    fclose(fPtr);
    fclose(fTemp);
     rename("replace.tmp","story11.txt");

     system("cls");
     display_story(1);
     remove("story11.txt");
     break;
            }
 case 2:
        {

               FILE * fPtr;
            FILE * fTemp;

    char buffer[MAX];

    char newWord[100];
    char oldWord[100]="backpacking";
     printf("\n\n Give me a verb(ing) :  ");
     scanf("%s",newWord);

     char newWord1[100];
     char oldWord1[100]="Barcelona";
     printf("\n \n Give me name of a place:  ");
     scanf("%s",newWord1);

     char newWord2[100];
     char oldWord2[100]="lake";
     printf("\n\n Give me a noun :  ");
   scanf("%s",newWord2);

   char newWord3[100];
   char oldWord3[100]="Gorgeous";
   printf("\n \n Give me an adjective: ");
   scanf("%s",newWord3);

   char newWord4[100];
   char oldWord4[100]="beautiful";
   printf("\n\n Give me an adjective: ");
   scanf("%s",newWord4);

   char newWord5[100];
   char oldWord5[100]="stared";
   printf("\n\n Give me a verb in past tense: ");
   scanf("%s",newWord5);

   char newWord6[100];
   char oldWord6[100]="back";
   printf("\n\n Give me name of a body part: ");
   scanf("%s",newWord6);

   char newWord7[100];
   char oldWord7[100]="hair";
   printf("\n\n Give me a part of body: ");
   scanf("%s",newWord7);

   char newWord8[100];
   char oldWord8[100]="tears";
   printf("\n\n Give me a name of body fluid: ");
   scanf("%s",newWord8);

   char newWord9[100];
   char oldWord9[100]="moment";
   printf("\n\n Give me a name of thing: ");
   scanf("%s",newWord9);

   char oldWord10[100]="MADLIBS";



    fPtr  = fopen("story2.txt", "r");
    fTemp = fopen("replace.tmp", "w");


    while ((fgets(buffer, MAX, fPtr)) != NULL)
    {

        replaceAll(buffer, oldWord, newWord);
        replaceAll(buffer, oldWord1, newWord1);
        replaceAll(buffer, oldWord2, newWord2);
          replaceAll(buffer, oldWord3, newWord3);
        replaceAll(buffer, oldWord4, newWord4);
        replaceAll(buffer, oldWord5, newWord5);
         replaceAll(buffer, oldWord6, newWord6);
        replaceAll(buffer, oldWord7, newWord7);
        replaceAll(buffer, oldWord8, newWord8);
          replaceAll(buffer, oldWord9, newWord9);
        replaceAll(buffer, oldWord10, name);


        fputs(buffer, fTemp);
    }

    fclose(fPtr);
    fclose(fTemp);
     rename("replace.tmp", "story21.txt");

     system("cls");
     display_story(2);
     remove("story21.txt");
     break;
            }

            case 3:
        {

               FILE * fPtr;
            FILE * fTemp;

    char buffer[MAX];

    char newWord[100];
    char oldWord[100]="practicing";
     printf("\n\n Give me a verb(ing) :  ");
     scanf("%s",newWord);

     char newWord1[100];
     char oldWord1[100]="wine";
     printf("\n \n Give me name of a drink:  ");
     scanf("%s",newWord1);

     char newWord2[100];
     char oldWord2[100]="Italian";
     printf("\n\n Give me a type of food:  ");
   scanf("%s",newWord2);

   char newWord3[100];
   char oldWord3[100]="jumping";
   printf("\n \n Give me a active verb(ing): ");
   scanf("%s",newWord3);

   char newWord4[100];
   char oldWord4[100]="ask";
   printf("\n\n Give me a verb ");
   scanf("%s",newWord4);

   char newWord5[100];
   char oldWord5[100]="lights";
   printf("\n\n Give me name of things (plural): ");
   scanf("%s",newWord5);

   char newWord6[100];
   char oldWord6[100]="butt";
   printf("\n\n Give me name of a part of body: ");
   scanf("%s",newWord6);

   char newWord7[100];
   char oldWord7[100]="shots";
   printf("\n\n Give me a verb ");
   scanf("%s",newWord7);

   char newWord8[100];
   char oldWord8[100]="beautiful";
   printf("\n\n Give me an adjective: ");
   scanf("%s",newWord8);

   char newWord9[100];
   char oldWord9[100]="talk";
   printf("\n\n Give me a verb in past tense: ");
   scanf("%s",newWord9);

   char oldWord10[100]="Madlibs";



    fPtr  = fopen("story3.txt", "r");
    fTemp = fopen("replace.tmp", "w");


    while ((fgets(buffer, MAX, fPtr)) != NULL)
    {

        replaceAll(buffer, oldWord, newWord);
        replaceAll(buffer, oldWord1, newWord1);
        replaceAll(buffer, oldWord2, newWord2);
          replaceAll(buffer, oldWord3, newWord3);
        replaceAll(buffer, oldWord4, newWord4);
        replaceAll(buffer, oldWord5, newWord5);
         replaceAll(buffer, oldWord6, newWord6);
        replaceAll(buffer, oldWord7, newWord7);
        replaceAll(buffer, oldWord8, newWord8);
          replaceAll(buffer, oldWord9, newWord9);
        replaceAll(buffer, oldWord10, name);


        fputs(buffer, fTemp);
    }

    fclose(fPtr);
    fclose(fTemp);
     rename("replace.tmp", "story31.txt");

     system("cls");
     display_story(3);
     remove("story31.txt");
     break;

            }

            case 4:
                {
                     FILE * fPtr;
            FILE * fTemp;

    char buffer[MAX];

    char newWord[100];
    char oldWord[100]="listening";
     printf("\n\n Give me a verb(ing) :  ");
     scanf("%s",newWord);

     char newWord1[100];
     char oldWord1[100]="alcoholics";
     printf("\n \n Give me a noun:  ");
     scanf("%s",newWord1);

     char newWord2[100];
     char oldWord2[100]="powerful";
     printf("\n\n Give me a adjective:  ");
   scanf("%s",newWord2);

   char newWord3[100];
   char oldWord3[100]="injurious";
   printf("\n \n Give me noun: ");
   scanf("%s",newWord3);

   char newWord4[100];
   char oldWord4[100]="water";
   printf("\n\n Give me liquid: ");
   scanf("%s",newWord4);

   char newWord5[100];
   char oldWord5[100]="beautifully";
   printf("\n\n Give me adverb: ");
   scanf("%s",newWord5);

   char newWord6[100];
   char oldWord6[100]="eyes";
   printf("\n\n Give me body part ");
   scanf("%s",newWord6);

   char newWord7[100];
   char oldWord7[100]="hidden";
   printf("\n\n Give me adjective: ");
   scanf("%s",newWord7);

   char newWord8[100];
   char oldWord8[100]="count";
   printf("\n\n Give me a verb: ");
   scanf("%s",newWord8);

   char newWord9[100];
   char oldWord9[100]="containers";
   printf("\n\n Give me a noun(plural): ");
   scanf("%s",newWord9);

   char oldWord10[100]="Madlibs";


    fPtr  = fopen("story4.txt", "r");
    fTemp = fopen("replace.tmp", "w");


    while ((fgets(buffer, MAX, fPtr)) != NULL)
    {

        replaceAll(buffer, oldWord, newWord);
        replaceAll(buffer, oldWord1, newWord1);
        replaceAll(buffer, oldWord2, newWord2);
          replaceAll(buffer, oldWord3, newWord3);
        replaceAll(buffer, oldWord4, newWord4);
        replaceAll(buffer, oldWord5, newWord5);
         replaceAll(buffer, oldWord6, newWord6);
        replaceAll(buffer, oldWord7, newWord7);
        replaceAll(buffer, oldWord8, newWord8);
          replaceAll(buffer, oldWord9, newWord9);
            replaceAll(buffer, oldWord10, name);



        fputs(buffer, fTemp);
    }

    fclose(fPtr);
    fclose(fTemp);
     rename("replace.tmp", "story41.txt");

     system("cls");
     display_story(4);
     remove("story41.txt");
                break;

        }

        case 5:
        {
              FILE * fPtr;
            FILE * fTemp;

    char buffer[MAX];

    char newWord[100];
    char oldWord[100]="CAT";
     printf("\n\n Give me a noun :  ");
     scanf("%s",newWord);

     char newWord1[100];
     char oldWord1[100]="FEEDING";
     printf("\n \n Give me a verb(ing):  ");
     scanf("%s",newWord1);

     char newWord2[100];
     char oldWord2[100]="TAKE";
     printf("\n\n Give me a verb:  ");
   scanf("%s",newWord2);

   char newWord3[100];
   char oldWord3[100]="VET";
   printf("\n \n Give me name of an OCCUPATION: ");
   scanf("%s",newWord3);

   char newWord4[100];
   char oldWord4[100]="FAVOURITE";
   printf("\n\n Give me an adjective: ");
   scanf("%s",newWord4);

   char newWord5[100];
   char oldWord5[100]="BED";
   printf("\n\n Give me name of a thing: ");
   scanf("%s",newWord5);

   char newWord6[100];
   char oldWord6[100]="ROSES";
   printf("\n\n Give me name of a flower: ");
   scanf("%s",newWord6);

   char newWord7[100];
   char oldWord7[100]="NOSES";
   printf("\n\n Give me part of the body(plural): ");
   scanf("%s",newWord7);

   char newWord8[100];
   char oldWord8[100]="FRIEND";
   printf("\n\n Give me name  of a relationship: ");
   scanf("%s",newWord8);

   char newWord9[100];
   char oldWord9[100]="FAULT";
   printf("\n\n Give me a noun: ");
   scanf("%s",newWord9);

   char oldWord10[100]="Madlibs";



    fPtr  = fopen("story5.txt", "r");
    fTemp = fopen("replace.tmp", "w");


    while ((fgets(buffer, MAX, fPtr)) != NULL)
    {

        replaceAll(buffer, oldWord, newWord);
        replaceAll(buffer, oldWord1, newWord1);
        replaceAll(buffer, oldWord2, newWord2);
          replaceAll(buffer, oldWord3, newWord3);
        replaceAll(buffer, oldWord4, newWord4);
        replaceAll(buffer, oldWord5, newWord5);
         replaceAll(buffer, oldWord6, newWord6);
        replaceAll(buffer, oldWord7, newWord7);
        replaceAll(buffer, oldWord8, newWord8);
          replaceAll(buffer, oldWord9, newWord9);
        replaceAll(buffer, oldWord10, name);


        fputs(buffer, fTemp);
    }

    fclose(fPtr);
    fclose(fTemp);
     rename("replace.tmp", "story51.txt");

     system("cls");
     display_story(5);
     remove("story51.txt");
     break;
     }
      case 6:
                {
                     FILE * fPtr;
            FILE * fTemp;

    char buffer[MAX];

    char newWord[100];
    char oldWord[100]="crack";
     printf("\n\n Give me a verb :  ");
     scanf("%s",newWord);

     char newWord1[100];
     char oldWord1[100]="heart";
     printf("\n \n Give me part of a body:  ");
     scanf("%s",newWord1);

     char newWord2[100];
     char oldWord2[100]="head";
     printf("\n\n Give me another part of the body:  ");
   scanf("%s",newWord2);

   char newWord3[100];
   char oldWord3[100]="tilt";
   printf("\n \n Give me a verb: ");
   scanf("%s",newWord3);

   char newWord4[100];
   char oldWord4[100]="knee";
   printf("\n\n Give me a part of body lower to chest: ");
   scanf("%s",newWord4);

   char newWord5[100];
   char oldWord5[100]="hang";
   printf("\n\n Give me a verb: ");
   scanf("%s",newWord5);

   char newWord6[100];
   char oldWord6[100]="neck";
   printf("\n\n Give me body part ");
   scanf("%s",newWord6);

   char newWord7[100];
   char oldWord7[100]="smiles";
   printf("\n\n Give me a verb: ");
   scanf("%s",newWord7);

   char newWord8[100];
   char oldWord8[100]="signature";
   printf("\n\n Give me a noun: ");
   scanf("%s",newWord8);

   char newWord9[100];
   char oldWord9[100]="wrists";
   printf("\n\n Give me a part of body: ");
   scanf("%s",newWord9);

   char newWord10[100];
   char oldWord10[100]="pen";
   printf("\n\n Give me a noun: ");
   scanf("%s",newWord10);

   char newWord11[100];
   char oldWord11[100]="chest";
   printf("\n\n Give me a part of body: ");
   scanf("%s",newWord11);

   char newWord13[100];
   char oldWord13[100]="talking";
   printf("\n\n Give me a verb(ing): ");
   scanf("%s",newWord11);

   char oldWord12[100]="Madlibs";


    fPtr  = fopen("story6.txt", "r");
    fTemp = fopen("replace.tmp", "w");


    while ((fgets(buffer, MAX, fPtr)) != NULL)
    {

        replaceAll(buffer, oldWord, newWord);
        replaceAll(buffer, oldWord1, newWord1);
        replaceAll(buffer, oldWord2, newWord2);
          replaceAll(buffer, oldWord3, newWord3);
        replaceAll(buffer, oldWord4, newWord4);
        replaceAll(buffer, oldWord5, newWord5);
         replaceAll(buffer, oldWord6, newWord6);
        replaceAll(buffer, oldWord7, newWord7);
        replaceAll(buffer, oldWord8, newWord8);
          replaceAll(buffer, oldWord9, newWord9);
            replaceAll(buffer, oldWord10, newWord10);
             replaceAll(buffer, oldWord11, newWord11);
          replaceAll(buffer, oldWord12, name);
            replaceAll(buffer, oldWord13, newWord13);




        fputs(buffer, fTemp);
    }

    fclose(fPtr);
    fclose(fTemp);
     rename("replace.tmp","story61.txt");

     system("cls");
     display_story(6);
     remove("story61.txt");
                break;

     }
     case 7:
{
     FILE * fPtr;
            FILE * fTemp;

    char buffer[MAX];

    char newWord[100];
    char oldWord[100]="Old";
     printf("\n\n Give me an adjective :  ");
     scanf("%s",newWord);

     char newWord1[100];
     char oldWord1[100]="ducks";
     printf("\n \n Give me name of animals plural:  ");
     scanf("%s",newWord1);

     char newWord2[100];
     char oldWord2[100]="farm";
     printf("\n\n Give me a noun:  ");
   scanf("%s",newWord2);

   char newWord3[100];
   char oldWord3[100]="quack";
   printf("\n \n Give me a sound: ");
   scanf("%s",newWord3);

   char oldWord5[100]="Madlibs";


    fPtr  = fopen("story7.txt","r");
    fTemp = fopen("replace.tmp","w");


    while ((fgets(buffer, MAX, fPtr)) != NULL)
    {

        replaceAll(buffer, oldWord, newWord);
        replaceAll(buffer, oldWord1, newWord1);
        replaceAll(buffer, oldWord2, newWord2);
          replaceAll(buffer, oldWord3, newWord3);
         replaceAll(buffer, oldWord5, name);



        fputs(buffer, fTemp);
    }

    fclose(fPtr);
    fclose(fTemp);
     rename("replace.tmp","story71.txt");

     system("cls");
     display_story(7);
     remove("story71.txt");
                break;


}

     }
     }


     else if(opt1==2)
    {





         char cr,re,wt1[100],wt2[100],wt3[100],wt4[100],wt5[100],wt6[100],wt7[100],w1[100],w2[100],w3[100],w4[100],w5[100],w6[100],w7[100];
           char c;
           char asked;






           Q:
            creating_your_own(cr);
              read_the_created(re);

            printf("\n Do you want to correct the story?y/n : ");
             scanf(" %c",&c);
             if(c=='y')
            {
                  printf("Please type the correct story again \n \n");
                  goto Q;
            }

               printf("STORY SUBMITTED \n\n");

                 ask_word_types(wt1,wt2,wt3,wt4,wt5,wt6,wt7);
                 ask_word_to(w1,w2,w3,w4,w5,w6,w7);

                 printf("..............Your own story created............. \n\n\n");



                printf("\t\t\t   Play the created story?y/n: ");
                scanf(" %c",&asked);
                   if (asked=='y')
                    {

                                                FILE  *fPtr;
                                                FILE  *fTemp;

                                                 char buffer[MAX];

                            char newWord[100];
                              char oldWord[100],oldWord1[100],oldWord2[100],oldWord3[100],oldWord4[100],oldWord5[100],oldWord6[100];
                                strcpy(oldWord,w1);
                                printf("\n\n Give me a %s :  ",wt1);
                                scanf("%s",newWord);

                                       char newWord1[100];
                                            strcpy(oldWord1,w2);
                                            printf("\n \n Give me %s:  ",wt2);
                                            scanf("%s",newWord1);

                                                char newWord2[100];
                                                    strcpy(oldWord2,w3);
                                                    printf("\n\n Give me a %s:  ",wt3);
                                                    scanf("%s",newWord2);

                                                         char newWord3[100];
                                                            strcpy(oldWord3,w4);
                                                            printf("\n \n Give me %s: ",wt4);
                                                            scanf("%s",newWord3);

                                                                    char newWord4[100];
                                                                        strcpy(oldWord4,w5);
                                                                        printf("\n\n Give me a %s: ",wt5);
                                                                        scanf("%s",newWord4);

                                                                    char newWord5[100];
                                                                        strcpy(oldWord5,w6);
                                                                        printf("\n\n Give me a %s: ",wt6);
                                                                        scanf("%s",newWord5);

                                                                        char newWord6[100];
                                                                            strcpy(oldWord6,w7);
                                                                            printf("\n\n Give me a %s: ",wt7);
                                                                            scanf("%s",newWord6);




                                                fPtr  = fopen("create.txt","w");
                                               fTemp = fopen("replace.tmp","w");

    while ((fgets(buffer, MAX, fPtr)) != NULL)
    {

        replaceAll(buffer, oldWord, newWord);
        replaceAll(buffer, oldWord1, newWord1);
        replaceAll(buffer, oldWord2, newWord2);
          replaceAll(buffer, oldWord3, newWord3);
        replaceAll(buffer, oldWord4, newWord4);
        replaceAll(buffer, oldWord5, newWord5);
         replaceAll(buffer, oldWord6, newWord6);




        fputs(buffer,fTemp);
    }

        fclose(fPtr);
    fclose(fTemp);
     system("cls");
     display_story(8);

                      }
                   }






     else
     {
        goto label;
     }



}


void replaceAll(char *str,const char *oldWord,const char *newWord)
{
    char *pos, temp[MAX];
    int index = 0;
    int owlen;

    owlen = strlen(oldWord);


    while ((pos = strstr(str, oldWord)) != NULL)
    {
        strcpy(temp, str);


        index = pos - str;

        str[index] = '\0';

        strcat(str, newWord);


        strcat(str, temp + index + owlen);
    }
}



    void display_loading()
{
 int i,j;
 for(i=0;i<50;i++)
 {
     printf("\n\n\n\n\n\n\t\t\t\t\tINITIALIZING THE PROGRAM:");
     for(j=0;j<10;j++)
     {
         printf("\xB2");
     }
  system("cls");
}
    system("cls");
for(i=0;i<50;i++)
 {
     printf("\n\n\n\n\n\n\t\t\t\t\tLOADING");
     for(j=0;j<10;j++)
     {
         printf("\xB2");
     }
     system("cls");
}
  system("cls");
}

void display_introduction()
{
     FILE *fp;
    char ch;
    fp=fopen("start_introduction.txt","r");
      while((ch=getc(fp))!=EOF)
{
    putchar(ch);
}
}

void display_story(int x)
{
     FILE *fp;
    char ch;
    switch(x)
    {
    case 1:
        {
        fp=fopen("story11.txt","r");
        break;
        }
    case 2:
        {
          fp=fopen("story21.txt","r");
          break;
        }
    case 3:
        {
            fp=fopen("story31.txt","r");
            break;
        }
    case 4:
        {
            fp=fopen("story41.txt","r");
            break;
        }
    case 5:
        {
            fp=fopen("story51.txt","r");
            break;
        }
    case 6:
    {
        fp=fopen("story61.txt","r");
        break;
    }
    case 7:
        {
           fp=fopen("story71.txt","r");
           break;
        }
    case 8:
        {
            fp=fopen("create.txt","r");
            break;
        }


    }

   while((ch=getc(fp))!=EOF)
{
    putchar(ch);
}

fclose(fp);
}








void creating_your_own(char cr)
                           {
    FILE *fptr;
      fptr = fopen("create.txt", "w");

      printf("Enter your story (input # when story is done) \n \n ");


  while( (cr = getchar()) != '#' )
    {
        fputc(cr, fptr);
    }

    fclose(fptr);
                              }


                               void read_the_created(char re)
                              {
     FILE *fptr;
    char str[MAX];
    char* filename = "create.txt";

    fptr = fopen(filename, "r");
    printf("The story you wrote is: \n \n");
    if (fptr == NULL){
        printf("Could not open file %s",filename);

    }
    while (fgets(str, MAX, fptr) != NULL)
    {
       printf("%s ", str);
    }


   fclose(fptr);
                              }


                              void ask_word_types(char wt1[100],char wt2[100],char wt3[100],char wt4[100],char wt5[100],char wt6[100],char wt7[100])
{
   printf("\n\n Word type of first word to be replaced e.g. verb/noun/etc : ");
   scanf("%s",wt1);
       fflush(stdin);

   printf("\n\n Word type of second word to be replaced: ");
   scanf("%s",wt2);
       fflush(stdin);

   printf("\n\n Word type of third word to be replaced: ");
   scanf("%s",wt3);
              fflush(stdin);

   printf("\n\n Word type of fourth word to be replaced: ");
   scanf("%s",wt4);
       fflush(stdin);

   printf("\n\n Word type of fifth word to be replaced: ");
   scanf("%s",wt5);
       fflush(stdin);

   printf("\n\n Word type of sixth word to be replaced: ");
   scanf("%s",wt6);
       fflush(stdin);

   printf("\n\n Word type of seventh word to be replaced:" );
   scanf("%s",wt7);
          fflush(stdin);
}

void ask_word_to(char w1[100],char w2[100],char w3[100],char w4[100],char w5[100],char w6[100],char w7[100])
    {
        printf("\n........ Actual words in the story to be replaced ..........");

       printf("\n\n  First word to be replaced: ");
   scanf("%s",w1);
       fflush(stdin);

   printf("\n\n  Second word to be replaced: ");
   scanf("%s",w2);
       fflush(stdin);

   printf("\n\n Third word to be replaced: ");
   scanf("%s",w3);
        fflush(stdin);

   printf("\n\n Fourth word to be replaced: ");
   scanf("%s",w4);
       fflush(stdin);

   printf("\n\n Fifth word to be replaced: ");
   scanf("%s",w5);
       fflush(stdin);

   printf("\n\n Sixth word to be replaced: ");
   scanf("%s",w6);
       fflush(stdin);

   printf("\n\n Seventh word to be replaced:" );
   scanf("%s",w7);
          fflush(stdin);

    }

