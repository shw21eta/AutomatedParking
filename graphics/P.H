typedef struct cnode
{
    char no[15];
    int cnt;
}CNODE;
typedef struct stack
{
    CNODE*data;
    struct stack*next;
}STACK;
CNODE*createCNode(char*s)
{
    CNODE*pNew=(CNODE*)malloc(sizeof(CNODE));
    strcpy(pNew->no,s);
    pNew->cnt=0;
    return pNew;
}
STACK*createNode(CNODE*d)
{
    STACK* pNew=(STACK*)malloc(sizeof(STACK));
    pNew->data=d;
    pNew->next=NULL;
    return pNew;
}
void push(STACK**top,CNODE*data)
{
    STACK*t=createNode(data);
    t->next=*top;
    *top=t;
}
CNODE* pop(STACK**top)
{
    STACK*t=NULL;
    CNODE*s=NULL;
    if((*top)==NULL)
        return s;
    t=*top;
    //(t->data->cnt)++;
    *top=(*top)->next;
    return t->data;
}
int isfull(STACK**top)
{
    int count=0;
    STACK*tmp=*top;
    while(tmp!=NULL)
    {
        count++;
        tmp=tmp->next;
    }
    return (count==10);
}
void insert_car(STACK**top,char*p)
{
    CNODE*pNew=createCNode(p);
    push(top,pNew);
}
CNODE* remove_car(STACK**top1,STACK**top2,char*s,int w,void*ptr)
{
    //STACK*tmp1=*top1,*tmp2=NULL;
    CNODE*tmp1,*tmp2,*tmp3;
    int i,flg=0;
    //printf("\nh\n");
    while((*top1)!=NULL&&strcmp((*top1)->data->no,s)!=0)
    {
	flg=1;
	//printf("\n%s\n",(*top1)->data->no);
	tmp1=pop(top1);
	(tmp1->cnt)++;
	push(top2,tmp1);
	w-=50;
	for(i=0;i<(350-w);i++)
	{
		if(i==0)
		putimage(353,66+w+i,ptr,XOR_PUT);
		putimage(353,66+w+i,ptr,XOR_PUT);
		delay(10);
		//if(i!=350-w)
		putimage(353,66+w+i,ptr,XOR_PUT);
	//printf("\npush\n");
	}
	for(i=0;i<150+w;i++)
	{
		putimage(353+i,410,ptr,XOR_PUT);
		delay(10);
		if(i!=149+w)
		putimage(353+i,410,ptr,XOR_PUT);
	}
    }
    if(flg==0)
    w-=100;
    else
    w-=50;
    for(i=0;i<(400);i++)
	{
		if(i==0)
		putimage(353,66+w+i,ptr,XOR_PUT);
		putimage(353,66+w+i,ptr,XOR_PUT);
		delay(10);
		//if(i!=350-w)
		putimage(353,66+w+i,ptr,XOR_PUT);
	//printf("\npush\n");
	}
    //printf("\nh\n");
    if((*top1)==NULL)
	tmp3=NULL;
    tmp1=pop(top1);
    while((*top2)!=NULL)
    {
	w+=50;
		for(i=0;i<150+w;i++)
	{
		if(i==0)
		putimage(353+149+w-i,410,ptr,XOR_PUT);
		putimage(353+149+w-i,410,ptr,XOR_PUT);
		delay(10);
		//if(i!=149+w)
		putimage(353+149+w-i,410,ptr,XOR_PUT);
	}
	w-=50;
	for(i=0;i<(350-w);i++)
	{
		//if(i==0)
	       //	putimage(353,66+w-i,ptr,XOR_PUT);
		putimage(353,349+66-w-i,ptr,XOR_PUT);
		delay(10);
		if(i!=349-w)
		putimage(353,349+66-w-i,ptr,XOR_PUT);
	//printf("\npush\n");
	}
	tmp2=pop(top2);
	push(top1,tmp2);
    }
    tmp3=tmp1;
    return tmp3;
}
void display_all(STACK*top)
{
    STACK*tmp=top;
    printf("\n\nCar number:  ");
    while(tmp!=NULL)
    {
        printf("%s\t",tmp->data->no);
        tmp=tmp->next;
    }
}
void display_detail(CNODE*t)
{
    printf("\n\nCar number:%s\n\nNumber of times the car was removed:%d\n",t->no,(t->cnt));
}
