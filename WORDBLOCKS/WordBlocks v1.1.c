#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>


//functions for permuting files------------------------------
void swap(char *x, char*y);
void permute(char *string,int l,int r);
FILE *fp7;
//--------------------------------------------------------

void main()
{
    //RANDOM WORD GENERATION.

   FILE *fpranword;
    char ran_word[15];
   fpranword = fopen("LongWords.txt","r");

    srand(time(NULL));
    int r1 = rand()%5848;
    fseek(fpranword,r1,SEEK_SET);

   fseek(fpranword,-1,SEEK_CUR);
    char tst;
            do
           {
            fseek(fpranword,-1,SEEK_CUR);
                       if(ftell(fpranword)==0)
                       {
                           break;
                       }

             tst=fgetc(fpranword);
             if(tst=='\n')
             {
                 break;
             }

             fseek(fpranword,-1,SEEK_CUR);
           }while(tst!='\n');
  fgets(ran_word,30,fpranword);
    fclose(fpranword);

    ran_word [ strcspn(ran_word, "\r\n") ] = '\0';
    printf("\n");

    //---------------------------------------------------------



    //Permutation-----------------------------------------------

    fp7 = fopen("finalpermute.txt","w");
    fclose(fp7);
    int i,r,total=0;
    int n = strlen(ran_word);
    printf("                                          Loading WORDBLOCKS please wait.......");
    permute(ran_word,0,n-1);
    //---------------------------------------------------------------------


    //-------------------------------COMPARING FILES FROM finalpermute.txt WITH 7words.txt AND STORING IN anagrams.txt---------------------

     printf("\n\n\n                                          Generating answers.......");


         FILE *fpc1,*fpc2,*fpc3;
    fpc1=fopen("finalpermute.txt","r");
    fpc2=fopen("7words.txt","r");
    fpc3=fopen("anagram.txt","w+");

    int found=0;
    char word[9];
    char line[10];
    n=0;
    int chk=0;
    int upper_limit=21880;
    int lower_limit=0;
    int result=-1;
    while(!feof(fpc1))
    {
        fgets(word,8,fpc1);
        word [ strcspn(word, "\r\n") ] = '\0';
       // printf("%s",word);

   n=0,chk=0;
   upper_limit=21880;
   lower_limit=0;
   result=-1;

        while(result!=0)
        {
            chk=n;
        n=(upper_limit+lower_limit)/2;
        if(chk==n)
        {
           // printf("Word not found.\n");
            break;
        }
         // printf("Value of n:%d ",n);
            fseek(fpc2,n,SEEK_SET);

    //---------------------------------setting the file pointer to the beginning of the word.---------------------------------------------------
        fseek(fpc2,-1,SEEK_CUR);
        char tst;
            do
           {
            fseek(fpc2,-1,SEEK_CUR);
                       if(ftell(fpc2)==0)
                       {
                           break;
                       }

             tst=fgetc(fpc2);
             if(tst=='\n')
             {
                 break;
             }

             fseek(fpc2,-1,SEEK_CUR);
           }while(tst!='\n');
    //-------------------------------------------------------------------------------------------------------------------------------------


         fgets(line,30,fpc2);
        line [ strcspn(line, "\r\n") ] = '\0';      // truncate any newline
       result=strcmp(line,word);
     //  printf(" Result:%d ",result);

         if(result>0)
    {
        upper_limit=n;
      //  printf("Required 'word' is above the line of text.\n");

    }

    else if(result<0)
    {
        lower_limit=n;
      //  printf("Required 'word' is below the line of text.\n");
    }

    else
    {
        found++;
        fputs(line,fpc3);
        fprintf(fpc3,"\n");

      // printf("Word found");
    }

  }


    }




    //-------------------------ASKING USER FOR ANSWERS----------------------------------------------------------------------------------



            fclose(fpc1);
            fclose(fpc2);

                system("cls");

            printf("\n\n             Your word is '%s'. List as many anagrams of the word you can (at least 3 lettered) and press enter.",ran_word);
            Sleep(1000);
            printf("\n\n              When done, type 'meme' and press enter.");




            FILE *fpu;
            fpu=fopen("User_words.txt","w+");
            char inp[8],t;
            printf("\n");
            do
            {
                printf("\n    Enter word : ");
                scanf("%s",&inp);
                if(strcmp(inp,"meme")!=0)
                {
                fputs(inp,fpu);
                fprintf(fpu,"\n");
                }


            }while(strcmp(inp,"meme")!=0);

            //----------------------------------------------REMOVING DUPLICATES FROM 'anagram.txt' ----------------

               fseek(fpc3,0,SEEK_SET);
               int i1=0,j=0,rows=0;
                    char c;

    while ((c=fgetc(fpc3))!=EOF){
        if (c=='\n'){
            rows++;
        }
    }

    char store[rows][8];
    fseek(fpc3,0,SEEK_SET);

    //initialize all elements to null value
    for (i1=0;i1<rows;i1++){
        for (j=0;j<8;j++){
            store[i1][j] = '\0';
        }
    }

    while (!feof(fpc3)){
        for (i1=0;i1<rows;i1++){
            fscanf(fpc3,"%s",store[i1]);
        }
    }

    //yo algorithm bheteko bela bujhamla ma
    int k = rows,m=0;
    for (i1=0;i1<=k;i1++){
        for(j=i1+1;j<=k;){
            if (strcmp(store[i1],store[j])==0){
                for (m=j;m<k;m++){
                    strcpy(store[m],store[m+1]);
                }
                k--;
            }
            else {
                j++;
            }
        }
    }

    fclose(fpc3);
    fpc3 = fopen("anagram.txt","w");
     for (i1=0;i1<k;i1++){
        fprintf(fpc3,"%s",store[i1]);  //use fprintf function if you want to store final output in another file
        fprintf(fpc3,"\n");
    }
        fclose(fpc3);







//------------------------------------CHECKING THE USER ENTERED WORDS AND DISPLAYING THE FINAL RESULT-----------------------------
        fpc3 = fopen("anagram.txt","r");

      //  FILE *fp1,*fp2;
      fseek(fpu,0,SEEK_SET);

     //   fp1=fopen("User_words.txt","r");
      //fp2=fopen("anagram.txt","r");
        char uswrd[10],ana[10];
      int correct=0,no_of_ana=0;

       while(!feof(fpu))
      {
          fgets(uswrd,10,fpu);
                  uswrd [ strcspn(uswrd, "\r\n") ] = '\0';
            fseek(fpc3,0,SEEK_SET);
            no_of_ana=0;

          while(!feof(fpc3))
          {
              fgets(ana,10,fpc3);
            ana[ strcspn(ana, "\r\n") ] = '\0';
             no_of_ana++;

              if(strcmp(ana,uswrd)==0)
              {
                  correct++;
              }
          }
      }


      printf("\n\n          Your result in : 3");
      Sleep(500);
      printf("..2");
      Sleep(500);
      printf("..1");
      Sleep(500);





        printf("\n\n           You entered %d out of the %d possible anagrams correctly.",correct-1,no_of_ana);
        fseek(fpc3,0,SEEK_SET);
        printf("\n\n");


          for(i=1;i<no_of_ana;i++)
          {
              Sleep(50);
              fgets(ana,10,fpc3);
            ana[ strcspn(ana, "\r\n") ] = '\0';
            printf("\n    %s",ana);
          }

        getch();

}



    //--------------------------------------------------------FUNCTIONS--------------------------------------------------------------------------------

   void swap(char *x, char *y){
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

    void permute(char *string,int l,int r){
    int i=0;
    int static count =0;
    if (l==r){
        fp7 = fopen("finalpermute.txt","a");

                for (i=6;i>=0;i--){
                    fprintf(fp7,"%c",string[i]);
                }
                fprintf(fp7,"\n");
                for (i=5;i>=0;i--){
                    fprintf(fp7,"%c",string[i]);
                }
                fprintf(fp7,"\n");
                if (count == 0 || count % 2 == 0){
                    for (i=4;i>=0;i--){
                        fprintf(fp7,"%c",string[i]);
                    }
                    fprintf(fp7,"\n");
                }
                if (count == 0 || count % 6 == 0){
                    for (i=3;i>=0;i--){
                        fprintf(fp7,"%c",string[i]);
                    }
                    fprintf(fp7,"\n");
                }
                if (count == 0 || count % 24 == 0){
                    for (i=2;i>=0;i--){
                        fprintf(fp7,"%c",string[i]);
                    }
                    fprintf(fp7,"\n");
                }
        fclose(fp7);
        count++;
    }
    else {
        for (i=l;i<=r;i++){
            swap(string+l,string+i);
            permute(string,l+1,r);
            swap(string+l,string+i);
        }
    }
}



































































