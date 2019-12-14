#include <stdio.h>
#include <stdlib.h>

/*  This function takes in any English Year and returns a digit from 0 to 6,
    indicating the week day for the January 1st of that year..
    e.g. 0 for Sunday and 6 for Saturday...
*/
int get_first_weekDay(int year)
{
    int day;
    day = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
    return day;
}

//This is the function that takes in year and print outs the entire calendar..
void print_calendar(int year)
{
    int day=0,dayInMonth,weekDay=0,startingDay,month;

    //Storing the names and no of days in each months in different arrays..
    char *months[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    int monthDays[]={31,28,31,30,31,30,31,31,30,31,30,31};

    //We need to check whether an english year is leap year or not.
    //Any leap year has 29 days in February instead of 28.
    if((year%4==0&&year%100!=0)||year%400==0)
    {
        monthDays[1]=29;
    }
    startingDay=get_first_weekDay(year);

    for(month=0;month<12;month++)
    {
        dayInMonth=monthDays[month]+1;
        printf("\n\n------------------%s----------------",months[month]);
        printf("\n  Sun   Mon  Tue  Wed  Thurs Fri  Sat\n");

        //Here I am printing the 5-width spaces for balancing the calendar in display.
        //StartingDay gives the week-day for the first of any month.
        //weekDay increases from the current week no of any date up to 6 and then again starts at 0.
        for(weekDay=0;weekDay<startingDay;weekDay++)
        {
           printf("     ");
        }
        for(day=1;day<dayInMonth;day++)
        {
            printf("%5d",day); //Here width for every date is 5 equal to that of 5 chars.
            if(++weekDay>6)
            {
                printf("\n");
                weekDay=0; //Updating weekDay to 0 as it becomes six as it ranges from 0 to 6.
            }
            startingDay=weekDay; //startingDay for next month is weekDay of last month's last date + 1.
        }
    }
}

//This is the function that can either take in any memo or view any memos kept in 'memos.txt' file.
//It uses file handling.
void memo_view() {
    int choice;
    printf("THIS THE MEMO VIEW: ENTER '1' TO SAVE A MEMO AND '2' TO VIEW A MEMO \n");
    scanf("%d", &choice);
    if (choice == 1) {
        char sentence[1000];
        FILE *edit;
        edit = fopen("memo.txt", "a");
        printf("Enter the no of memos you would like to add:\n");
        int memos;
        scanf("%d", &memos);
        while(memos--) {
            printf("Enter a sentence:\n");
            fflush(stdin);
            fgets(sentence, 1000, stdin);

            fprintf(edit,"%s", sentence);
        }

        fclose(edit);
        }
    else {
        FILE *view;
        view = fopen("memo.txt", "r");
        char sentence[1000];
        do
        {
            fgets(sentence, 1000, view);
            printf("%s", sentence);


        }
        while(!feof(view));

        fclose(view);

    }
}


int main()
{
    system("color 3F");

    int year;
    printf("Enter your desired year:  \n");
    scanf("%d",&year);
    printf("       A CALENDAR OF THE YEAR %d", year);
    print_calendar(year);
    printf("\n\n");
    RESET:
    memo_view();

    printf("\n");
    goto RESET;

    return 0;
}


/* Submitted by:
    -Nishan Poudel, 075BCT057
    -Priya Thakur , 075BCT062

*/
