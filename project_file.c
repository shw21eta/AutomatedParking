#include<stdio.h>
#include<string.h>
int main()
{
    FILE*fs;
    char s[15];
    char choice;
    int opt;
    fs=fopen("cars.txt","w");
    if(fs==NULL)
        return;
    while(1)
    {
        printf("\nMenu\n\n1.Arrival\n2.Deperture\n3.Exit\nOption:");
        scanf("%d",&opt);
        if(opt>2)
            break;
        else if(opt==1)
            choice='A';
        else
            choice='D';
        fflush(stdin);
        printf("\nEnter car number:");
        gets(s);
        fprintf(fs,"%c %s\n",choice,s);
    }
    return 0;
}
