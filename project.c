#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10
#include"project.h"
int main()
{
    STACK*top1=NULL,*top2=NULL;
    CNODE*tmp=NULL;
    FILE*fs;
    char choice,ch;
    int opt,n;
    char t[20];
    fromfile(&top1);
    printf("\n\n");             //read previous data
    display_all(top1);
    getch();
    fs=fopen("cars.txt","r");    //open file contains events in read mode
    if(fs==NULL)
        return;
    while(1)
    {
        system("cls");
        printf("\nMenu:\n\n1.Read from file\n2.Give input\n3.Exit\nOption:");
        fflush(stdin);
        scanf("%d",&opt);
        if(opt>2)
            break;
        if(opt==1)
        {
            if(feof(fs))
            {
                printf("\nNo more data in file");
                continue;
            }
        fscanf(fs,"%c %s\n",&choice,t);
        printf("\n\nCar number:%s\nEvent:%c\n\n",t,choice);
        }
        else
        {
            while(1)
            {
            printf("\nCar number:");
            fflush(stdin);
            gets(t);
            if((t[0]>=65&&t[0]<=90)||(t[0]>=97&&t[0]<=122))
                break;
            printf("\nInvalid number\n");
            }
            printf("\nEvent\nArrival-A\nDeparture-D:");
            scanf("%c",&choice);
        }
        switch(choice)
        {
        case 'A':
        case 'a':
            if(search(&top1,t))
            {
                printf("\nCar already in garage\n\n");
                break;
            }
            if(isfull(&top1))         //check whether there is space  for car or not
            {
                printf("\nNo space for car\n");
                break;
            }
            insert_car(&top1,t);    //call function to arrive car in garage
            break;
        case 'D':
        case 'd':
            tmp=remove_car(&top1,&top2,t);  //call function to depart car from garage
            if(tmp==NULL)
                printf("\nNo such car in garage\n");
            else
                {
                    printf("\nCar details:");
                    display_detail(tmp);    //function to display details of departed car
                    free(tmp);
                }
            break;
        }
        printf("\n\nCars in garage:\n");
            display_all(top1);      //display all cars present in garage according to their arrival
        getch();
    }
    fclose(fs);
    if(top1==NULL)
        remove("file.txt");
    else
    tofile(&top1,&top2);
    return 0;
}

