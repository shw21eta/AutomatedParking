typedef struct cnode
{
    char no[20];     //car's plate no.
    int cnt;        //to maintain count of how many times car removed from garage
}CNODE;
typedef struct stack
{
    void*data;          //generic pointer
    struct stack*next;
}STACK;
CNODE*createCNode(char*s)       //create node with plate no. and count
{
    CNODE*pNew=(CNODE*)malloc(sizeof(CNODE));
    strcpy(pNew->no,s);
    pNew->cnt=0;
    return pNew;
}
STACK*createNode(void*d)        //create node with provided data and maintain link to next node also
{
    STACK* pNew=(STACK*)malloc(sizeof(STACK));
    pNew->data=d;
    pNew->next=NULL;
    return pNew;
}
void push(STACK**top,void*data)     //function to push node into the stack
{
    STACK*t=createNode(data);
    t->next=*top;
    *top=t;
}
void* pop(STACK**top)       //function to pop out node from stack
{
    STACK*t=NULL;
    void*s=NULL;
    if((*top)==NULL)
        return s;
    t=*top;
    *top=(*top)->next;
    return t->data;
}
void* stacktop(STACK*top)
{
    if(top==NULL)
        return NULL;
    else
        return top->data;
}
int search(STACK**top,char*s)
{
    STACK*tmp=*top;
    while(tmp!=NULL)
    {
        if(strcmp(((CNODE*)tmp->data)->no,s)==0)
            break;
        tmp=tmp->next;
    }
    return tmp!=NULL;
}
int isfull(STACK**top)      //function to check capacity of lane of garage
{
    int count=0;
    STACK*tmp=*top;
    while(tmp!=NULL)
    {
        count++;
        tmp=tmp->next;
    }
    return (count==N);
}
void insert_car(STACK**top,char*p)  //function to arrive car into the garage
{
    CNODE*pNew=createCNode(p);
    push(top,pNew);
}
void* remove_car(STACK**top1,STACK**top2,char*s)    //function to depart car from garage
{
    void*tmp1,*tmp2;
    while((*top1)!=NULL&&strcmp((((CNODE*)(*top1)->data))->no,s)!=0)
    {
        tmp1=pop(top1);        //depart from garage
        ((CNODE*)tmp1)->cnt++;
        push(top2,tmp1);        //push into temporary stack
    }
    if((*top1)==NULL)
        tmp1=NULL;
    else
        tmp1=pop(top1);     //depart desired car permanently
    while((*top2)!=NULL)
    {
        tmp2=pop(top2);   //depart from temporary stack
        push(top1,tmp2);    //push into garage
    }
    return tmp1;
}
void display_all(STACK*top) //function to display cars present in garage according to their arrival
{
    STACK*tmp=top;
    printf("                     **Bashemin Parking Garage**                               ");
    printf("\nEntry/\nExit\n");
    printf("   -----------------------------------------------------------------------------\n\n");
    printf("   ");
    while(tmp!=NULL)
    {
        printf("%s | ",((CNODE*)tmp->data)->no);
        tmp=tmp->next;
    }
    printf("\n\n   -----------------------------------------------------------------------------");
}
void display_detail(CNODE*t) //function to display details of single node i.e car
{
    printf("\n\nCar number:%s\n\nNumber of times the car was removed:%d\n",t->no,(t->cnt));
}
void fromfile(STACK**top)
{
    FILE*fs;
    CNODE*c=NULL;
    fs=fopen("file.txt","r");
    if(fs==NULL)
        return;
    while(1)
    {
        if(feof(fs))
            break;
        c=(CNODE*)malloc(sizeof(CNODE));
        fscanf(fs,"%s %d\n",c->no,&c->cnt);
        push(top,c);
    }
    fclose(fs);
}
void tofile(STACK**top1,STACK**top2)
{
    FILE*fs;
    CNODE*c,*tmp;
    fs=fopen("file.txt","w");
    while(*top1!=NULL)
    {
        c=pop(top1);
        push(top2,c);
    }
    while(*top2!=NULL)
    {
        c=tmp=pop(top2);
        fprintf(fs,"%s %d\n",c->no,c->cnt);
        free(tmp);
    }
    fclose(fs);
}

