#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <time.h>
#define pi 3.14159
float sec,min,hrs;
char nam[50];
float m=0,n=0,o=0;
void minutes();
void hours();
void timer();
float digit(char name[],int,int);

void circles()
{
   int a,x,y;
   circle(300,280,125);
   for(a=0;a<=360;a=a+30)
   {
      x = 300 + 115 * sin(pi*a/180);
      y= 280 + 115 * cos(pi*a/180);
      circle(x,y,5);
      outtextxy(230,420,"Press n to exit");
      outtextxy(230,430,"Press m to return to the main menu");
   }
}

void clocks()
{
  int c = 0,r=100,x,y,angle,i;
  angle = sec * 6;
  cleardevice();
    while(c != 'n')             // until correct key is pressed
    {
      do
      {
	 i=90-angle;
	 x = 300 + r * cos(i*3.14159/180);
	 y = 280 - r * sin(i*3.14159/180);
	 circles();
	 line(300,280,x,y);
	 minutes();
	 hours();
	 delay(1000) ;
	 cleardevice();
	 angle=angle+6;
      }
      while(!kbhit());      // until a key press detected
      c = getch();	    // fetch that key press
      if(c=='m')
      main();
    }
}

int main()
{
     int t;
     time_t current_time;
     char name[30],c;
     char* c_time_string;
     int gd=DETECT,gm,i,j;
     initgraph(&gd,&gm,"C:/TURBOC3/BGI");
     while (c!='x'&&c!='c'&&c!='t')
     {
     do
     {
	current_time = time(NULL);
	c_time_string=ctime(&current_time);
       gotoxy(1,1);	printf("\n\t\t\t\t   MINI PROJECT");
	printf("\n\t\t\t\tAnalog clock in C");
	printf("\nCurrent time is %s",c_time_string);
	printf("\nPress C for clock");
	printf("\nPress T for timer");
	printf("\nPress X to exit");
	gotoxy(60,23); printf("Submitted By:");
	gotoxy(60,24);  printf("Tilak Chad");
	gotoxy(60,25); printf("Subodh Baral");
	delay (1000);
	cleardevice();
	}
	while(!kbhit());
	c = getch();
	}
	strcpy(name,c_time_string);
	strcpy(nam,c_time_string);
       hrs = digit(name,11,12);
     min = digit(name,14,15);
     sec = digit(name,17,18);
     if (hrs>12)
	hrs = hrs -12;
     hrs = hrs + min/60+sec/3600;
     min = min + sec/60;
     j:
     if(c=='c')
	clocks();
     else if(c=='x')
       {
	 closegraph();
       }
     else if(c=='t')
       timer();
     else
	goto j;
    cleardevice();
    closegraph();
    return 0;
  }


  void minutes()
  {
     int x,y,r,a;
     m=min*(6)+0.1+m;
     r = 90 - m;
     x=300+90*cos(3.14159*r/180);
     y=280-90*sin(3.14159*r/180);
     line(300,280,x,y);
     min=0;
  }


  void hours()
  {
     int x,y,r;
     n = hrs*30 + 1/60 + n;
     r = 90 - n  ;
     x = 300 + 60*cos(r*pi/180);
     y = 280-60*sin(r*pi/180);
     line(300,280,x,y);
     hrs=0;
  }

  float digit(char name[],int x,int y)
  {
     int a,b;
     if(name[x]>=48 && name[x]<=57)
	a = name[x]-48;
     if (name[y]>=48 && name[y]<=57)
	b = name[y]-48;
     return a*10+b;
  }


 void timer()
 {
  int hr,mn,se,tim,t,j,x1,y1,x2,y2;
  char c,start;
  float i,angle,r;
  cleardevice();
 gotoxy(1,1); printf("Enter time :");
  printf("\n\t\tEnter Hour : ");
  scanf("%d",&hr);
  printf("\n\t\tEnter Minute : ");
  scanf("%d",&mn);
  printf("\n\t\tEnter Second : ");
  scanf("%d",&se);
  t=(hr*3600)+(mn*60)+se;
  r = t * 2.777777;
  tim = r;
  cleardevice();
  setcolor(15);
  outtextxy(200,75,"Press S to start" );
  cleardevice();
  for(j=0;j<360;j++)
    {
     x1= 300+100*sin((pi*j)/180);
     y1= 200-100*cos((pi*j)/180);
     line(300,200,x1,y1);
    }
  start=getch();
  if(start==13)
  {
    for(i=0;i<360;i++)
    {
      angle = i - 90;
      x2= 300-100*cos((pi*angle)/180);
      y2= 200+100*sin((pi*angle)/180);
      setcolor(0);
      line(300,200,x2,y2);
      delay(tim);
     }
     cleardevice();
     setcolor(15);
     outtextxy(300,200,"Finished");
   }
   outtextxy(230,420,"Press x to exit");
   outtextxy(230,430,"Press m to return to the main menu");
   j:
   c= getch();
   if(c=='m')
      main();
   else if(c=='x')
      closegraph();
   else
   goto j;
 }
