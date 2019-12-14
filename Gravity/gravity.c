#include <stdio.h>
#include <conio.h>

struct player{
    char name;
    int pos[6][7];
    int win;
};
int commonPos[6][7];
struct player playerX, playerO;

void check();

void main(){
    //var declarations
    int start;
    int Noofmoves;
    char endprompt;
    
    //game start/stop prompt
    first:
    printf("Choose");
    printf("1. START\n");
    printf("2. STOP\n");
    scanf("%d",&start);
    if(start!=1 || start !=2){
        printf("Please input '1' or '2'");
        goto first;
    }
    
    //game
    game:
    switch(start)
    {
        case(1):
            clrscr();
            //enter players name
            printf("Enter the name of user who will play as 'X': ");
            scanf("%s",&playerX.name);
            printf("Enter the name of user who will play as 'O': ");
            scanf("%s",&playerO.name);

            clrscr();
            do{ 
                int i1=0,j1=0,i2=0,j2=0;
                printf("%s's turn",playerX.name);
                promptX:
                printf("Enter the row(1-6)");
                scanf("%d",&i1);
                printf("Enter the column(1-7");
                scanf("%d",&j1);
                if (commonPos[i1][j1] == 0){
                    commonPos[i1][j1]=1;
                    playerX.pos[i1][j1]=1;
                    Noofmoves= Noofmoves+1;
                }
                else{
                    printf("The position is not empty.\n");
                    printf("Please enter again.");
                    goto promptX; 
                }
                
                printf("%s's turn",playerO.name);
                promptO:
                printf("Enter the row(1-6)");
                scanf("%d",&i2);
                printf("Enter the column(1-7");
                scanf("%d",&j2);
                if (commonPos[i2][j2] == 0){
                    commonPos[i2][j2]=1;
                    playerO.pos[i2][j2]=1;
                    Noofmoves = Noofmoves +1;
                }
                else{
                    printf("The position is not empty.\n");
                    printf("Please enter again.");
                    goto promptO; 
                }
                if(playerX.win==1 || playerO.win==1){
                    if(playerX.win==1)
                        printf("%s won.",&playerX.name);
                    if(playerO.win==1)
                        printf("%s won.",&playerO.name); 
                    printf("Would you like to continue?");
                    printf("Please enter Y/y for Yes and N/n for No.");
                    scanf("%c",&endprompt);
                    if(endprompt=='Y' || endprompt =='y'){
                        goto game;
                    }
                    else{
                        goto end;
                    }
                }
                if(Noofmoves==48){
                    printf("Its a Draw.");
                    printf("Would you like to continue?");
                    printf("Please enter Y/y for Yes and N/n for No.");
                    scanf("%c",&endprompt);
                    if(endprompt=='Y' || endprompt =='y'){
                        goto game;
                    }
                    else{
                        goto end;
                    }
                }

            }while(playerX.win!=1 && playerO.win!=1);
        case(2):
            end:
            printf("Thank you");
    }
}

void check(){
    int i,j;
    for(i=0;i<=5;i++){
        for(j=0;j<=6;j++){
            //downways win
            if(i<=2){
                if(playerX.pos[i][j]==1 && playerX.pos[i+1][j]==1 && playerX.pos[i+2][j]==1 && playerX.pos[i+3][j]==1 ){
                    playerX.win=1;
                }
                if(playerO.pos[i][j]==1 && playerO.pos[i+1][j]==1 && playerO.pos[i+2][j]==1 && playerO.pos[i+3][j]==1 ){
                    playerO.win=1;
                }
            }
            //across win
            if(j<=3){
                if(playerX.pos[i][j]==1 && playerX.pos[i][j+1]==1 && playerX.pos[i][j+2]==1 && playerX.pos[i][j+3]==1 ){
                    playerX.win=1;
                }
                if(playerO.pos[i][j]==1 && playerO.pos[i][j+1]==1 && playerO.pos[i][j+2]==1 && playerO.pos[i][j+3]==1 ){
                    playerO.win=1;
                }
            }
            //diagonal win
            if(j<=4){
                if(playerX.pos[i][j]==1 && playerX.pos[i+1][j+1]==1 && playerX.pos[i+2][j+2]==1 && playerX.pos[i+3][j+3]==1 ){
                    playerX.win=1;
                }
                if(playerO.pos[i][j]==1 && playerO.pos[i+1][j+1]==1 && playerO.pos[i+2][j+2]==1 && playerO.pos[i+3][j+3]==1 ){
                    playerO.win=1;
                }
            }
            if(j>=4){
                if(playerX.pos[i][j]==1 && playerX.pos[i-1][j-1]==1 && playerX.pos[i-2][j-2]==1 && playerX.pos[i-3][j-3]==1 ){
                    playerX.win=1;
                }
                if(playerO.pos[i][j]==1 && playerO.pos[i-1][j-1]==1 && playerO.pos[i-2][j-2]==1 && playerO.pos[i-3][j-3]==1 ){
                    playerO.win=1;
                }
            }
        }
    }
}