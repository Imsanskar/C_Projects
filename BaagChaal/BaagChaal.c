#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int goat_eaten=0;
void print_board(char board[5][5]);
void put_goat(char board[5][5]);
void move_tiger(char board[5][5]);
void move_goat(char board[5][5]);
char board[5][5];
void main()
{
    printf("The game is over when either, the tigers capture five goats, or the tigers fail to capture 5 goats in 60 moves.\n");
    int rem_goat=20,rem_moves=60;
    char board[5][5],confirm;
    int x,y;
    for(x=0;x<5;x++)
    {
        for(y=0;y<5;y++)
        {
            board[x][y]='_';
            if( ((y==0)||(y==4))&&((x==0)||(x==4)) )
            {
                board[x][y]='T';
            }
        }
    }
    while(rem_goat!=0)
    {
        printf("Goat's turn:\n");
        print_board(board);
        put_goat(board);
        rem_goat--;
        system("cls");
        printf("Tiger's turn:\n");
        print_board(board);
        printf("Remaining goat in hand is %d\n",rem_goat);
        printf("Goat eaten=%d\n",goat_eaten);
        printf("Remaining moves=%d\n",rem_moves);
        move_tiger(board);
        rem_moves--;
        if(goat_eaten==5)
        {
            system("cls");
            printf("Game over.");
            printf("Tiger wins.");
            goto label4;
        }
        print_board(board);
        system("cls");
        print_board(board);
        printf("Remaining goat in hand is %d\n",rem_goat);
        printf("Goat eaten=%d\n",goat_eaten);
        system("cls");
    }
    while(rem_moves!=0)
    {
        printf("Is moves possible for tiger,y/n:");
        scanf("%c",&confirm);
        if(confirm=='n')
        {
            break;
        }
        if(goat_eaten==5)
        {
            system("cls");
            printf("Game over.");
            printf("Tiger wins.");
            goto label4;
        }
        move_goat(board);
        system("cls");
        print_board(board);
        move_tiger(board);
        rem_moves--;
        system("cls");
        print_board(board);
        printf("Remaining goat in hand is %d\n",rem_goat);
        printf("Goat eaten=%d\n",goat_eaten);
        printf("Remaining moves=%d\n",rem_moves);
    }
    system("cls");
    printf("Game over.");
    printf("Goat wins.");
    label4:
        printf("Thanks for playing");
}
void print_board(char board[5][5])
{
    int x,y;
    for(x=0;x<5;x++)
    {
        if(x==0)
        {
            printf("  0 1 2 3 4\n");
        }
        printf("%d ",x);
        for(y=0;y<5;y++)
        {
            printf("%c ",board[x][y]);

        }
        printf("\n");
    }

}
void put_goat(char board[5][5])
{
    int x,y;
    label1:
    printf("Enter the row to put the goat:");
    scanf("%d",&x);
    printf("Enter the column to put the goat:");
    scanf("%d",&y);
    if (board[x][y]=='_')
    {
        board[x][y]='G';
    }
    else
    {
        printf("Enter a valid position\n");
        goto label1;
    }
    print_board(board);
}
void move_goat(char board[5][5])
{
    int x,y,dx,dy,modx,mody;
    label5:
    printf("Please select the goat position\n");
    scanf("%d %d",&x,&y);
    if(board[x][y]=='G')
    {
        modx=x%2;
        mody=y%2;
        board[x][y]='_';
        printf("Enter the row to put the goat:");
        scanf("%d",&dx);
        printf("Enter the column to put the goat:");
        scanf("%d",&dy);
        if((board[dx][dy]=='_')&&modx==mody)
        {
            if((((dx-x)==1)||((x-dx)==1)||((y-dy)==1)||((dy-y)==1)))
            {
                board[dx][dy]='G';
            }
            else
            {
                printf("Enter the valid direction\n");
                board[x][y]='G';
                goto label5;
            }
        }
        else if((board[dx][dy]=='_')&&modx!=mody)
        {
                if((((x-dx)==1)||(dx-x)==1)&&((y-dy)==0))
               {
                   board[dx][dy]='G';
               }
               else if(((((y-dy)==1)||(dy-y)==1)&&((y-dy)==0)))
               {
                   board[dx][dy]='G';
               }
                else
                {
                    printf("Enter the valid direction\n");
                    board[x][y]='G';
                    goto label5;
                }
        }
        else
        {
            printf("Enter the valid position\n");
            board[x][y]='T';
            goto label5;
        }

    }
    else
    {
        printf("Enter a valid position\n");
        goto label5;
    }
}
void move_tiger(char board[5][5])
{
    int x,y,dx,dy,modx,mody;
    label2:
    printf("Please select the tiger position\n");
    scanf("%d %d",&x,&y);
    if(board[x][y]=='T')
    {
        modx=x%2;
        mody=y%2;
        board[x][y]='_';
        printf("Enter the row to put the tiger:");
        scanf("%d",&dx);
        printf("Enter the column to put the tiger:");
        scanf("%d",&dy);
        if ((board[dx][dy]=='_')&&(modx==mody))
        {
            if((((x-dx)==1)||(dx-x)==1)&&((y-dy)==0))
            {
                board[dx][dy]='T';
            }
            else if(((((y-dy)==1)||(dy-y)==1)&&((x-dx)==0)))
            {
                   board[dx][dy]='T';
            }
            else if(((((y-dy)==1)||(dy-y)==1)&&((x-dx)==1)||((dx-x)==1)))
            {
                    board[dx][dy]='T';
            }
            else if((((dx-x)==2||((x-dx)==2)||((y-dy)==2)||((dy-y)==2))))
            {
                if(((dx-x)==2)&&((y-dy)==0)&&(board[x+1][y]=='G'))
                {
                    board[(dx+1)][y]='_';
                    board[dx][y]='T';
                    goat_eaten=goat_eaten+1;
                }
                else if(((x-dx)==2)&&((y-dy)==0)&&(board[x-1][y]=='G'))
                {
                    board[(dx+1)][y]='_';
                    board[dx][y]='T';
                    goat_eaten=goat_eaten+1;
                }
                else if(((dy-y)==2)&&((x-dx)==0)&&(board[x][y+1]=='G'))
                {
                    board[x][y+1]='_';
                    board[x][dy]='T';
                    goat_eaten=goat_eaten+1;
                }
                else if(((y-dy)==2)&&((x-dx)==0)&&(board[x][y-1]=='G'))
                {
                    board[x][y-1]='_';
                    board[x][dy]='T';
                    goat_eaten=goat_eaten+1;
                }
                else if(((y-dy)==2)&&((x-dx)==2)&&(board[x-1][y-1]=='G'))
                {
                    board[x-1][y-1]='_';
                    board[dx][dy]='T';
                    goat_eaten=goat_eaten+1;
                }
                else if(((y-dy)==2)&&((dx-x)==2)&&(board[x+1][y-1]=='G'))
                {
                    board[x+1][y-1]='_';
                    board[dx][dy]='T';
                    goat_eaten=goat_eaten+1;
                }
                else if(((x-dx)==2)&&((dy-y)==2)&&(board[x-1][y+1]=='G'))
                {
                    board[x-1][y+1]='_';
                    board[dx][dy]='T';
                    goat_eaten=goat_eaten+1;
                }
                else if(((dx-x)==2)&&((dy-y)==2)&&(board[x+1][y+1]=='G'))
                {
                    board[x+1][y+1]='_';
                    board[dx][dy]='T';
                    goat_eaten=goat_eaten+1;
                }
                else
                {
                    goto label3;
                }
            }
            else
            {
                label3:
                printf("Enter the valid direction\n");
                board[x][y]='T';
                goto label2;
            }
        }
        else if((board[dx][dy]=='_')&&(modx!=mody))
        {
               if((((x-dx)==1)||(dx-x)==1)&&((y-dy)==0))
               {
                   board[dx][dy]='T';
               }
               else if(((((y-dy)==1)||(dy-y)==1)&&((y-dy)==0)))
               {
                   board[dx][dy]='T';
               }
                else if(((dx-x)==2)&&((y-dy)==0)&&(board[x+1][y]=='G'))
                {
                    board[(dx+1)][y]='_';
                    board[dx][y]='T';
                    goat_eaten=goat_eaten+1;
                }
                else if(((x-dx)==2)&&((y-dy)==0)&&(board[x-1][y]=='G'))
                {
                    board[(dx+1)][y]='_';
                    board[dx][y]='T';
                    goat_eaten=goat_eaten+1;
                }
                else if(((dy-y)==2)&&((x-dx)==0)&&(board[x][y+1]=='G'))
                {
                    board[x][y+1]='_';
                    board[x][dy]='T';
                    goat_eaten=goat_eaten+1;
                }
               else
                {
                    printf("Enter the valid direction\n");
                    board[x][y]='T';
                    goto label2;
                }

        }
        else
        {
            printf("Enter the valid position\n");
            board[x][y]='T';
            goto label2;
        }
    }
    else
    {
        printf("Enter a valid position\n");
        goto label2;
    }
}
