#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<graphics.h>
#include<c:\turboc3\bin\p.h>
int main()
{
    int gd,gm;
    STACK*top1=NULL,*top2=NULL;
    CNODE*tmp=NULL;
    FILE*fs;
    char choice,ch;
    int opt;
    char t[15];
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"c:\\turbo c++\\Disk\\turboc3\\bgi");
    fs=fopen("cars.txt","r");
    if(fs==NULL)
	return;
    //setbkcolor(RED);
   // outtextxy(10,10,"HELLO");
   // gotoxy(10,20);
   // scanf("%d",&opt);
    while(1)
    {
	clrscr();
	outtextxy(10,10,"Menu:");
	outtextxy(10,20,"1.Read from file");
	outtextxy(10,30,"2.Give input");
	outtextxy(10,40,"3.Exit");
	outtextxy(10,50,"Option:");
	fflush(stdin);
	gotoxy(10,60);
	scanf("%d",&opt);
	cleardevice();
	line(350,50,400,50);
	line(350,50,350,350);
	line(400,50,400,350);
	if(opt>2)
	    break;
	if(opt==1)
	{
	    if(feof(fs))
	    {
		printf("\nNo more data in file");
		//break;
		getch();
		continue;
	    }
	//system("cls");
	fscanf(fs,"%c %s\n",&choice,t);
	//fflush(stdin);
	//printf("\nTake input?(Y/N):");
	//scanf("%c",&ch);
	//if(ch=='N'||ch=='n')
	  //  break;
	printf("\n\nCar number:%s\nEvent:%c\n\n",t,choice);
	}
	else
	{
	    printf("\nCar number:");
	    fflush(stdin);
	    gets(t);
	    printf("\nEvent:");
	    scanf("%c",&choice);
	}
	switch(choice)
	{
	case 'A':
	case 'a':
	    if(isfull(&top1))
	    {
		printf("\nNo space for car\n");
		break;
	    }
	    insert_car(&top1,t);
	    break;
	case 'D':
	case 'd':
	    tmp=remove_car(&top1,&top2,t);
	    if(tmp==NULL)
		printf("\nNo such car in garage\n");
	    else
		{
		    printf("\nCar details:");
		    display_detail(tmp);
		    free(tmp);
		}
	    break;
	}
       // printf("\n\nCars in garage:\n");
	 //   display_all(top1);
     getch();

    }
getch();
    return 0;
}

