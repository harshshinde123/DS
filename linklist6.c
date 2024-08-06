#include<stdio.h>
#include<stdlib.h>//for malloc and free;
#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};
 typedef struct node NODE;
 typedef struct node* PNODE;
 typedef struct node** PPNODE;

void InsertFirst(PPNODE First,int no)
{
  PNODE newn = (PNODE)malloc(sizeof(NODE));
  newn->data=no;
  newn->next=NULL;
  
  if (*First==NULL)
  {
    *First=newn;
  }
  else
  {
    newn->next=*First;
    *First=newn;
  }
}
void InsertLast(PPNODE First,int no)
{
  PNODE newn = (PNODE)malloc(sizeof(NODE));
  PNODE temp=*First;

  newn->data=no;
  newn->next=NULL;

  if (*First==NULL)
  {
    *First=newn;
  }
  else
  {
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
     temp->next=newn;
  }
}


void DeleteFirst(PPNODE First)
{
    PNODE temp =*First;
    if (*First==NULL)
    {
        return;
    }
    else if ((*First)->next==NULL)
    {
        free(*First);
        *First=NULL;
    }
    else
    {
     *First=(*First)->next;
     free(temp);
    }
    
}

void DeleteLast(PPNODE First)
{
    PNODE temp =*First;
    if (*First==NULL)
    {
        return;
    }
    else if ((*First)->next==NULL)
    {
        free(*First);
        *First=NULL;
    }
    else
    {
     while (temp->next->next!=NULL)
     {
        temp=temp->next;
        
     }
     free(temp->next);
     temp->next=NULL;
    }
}
void InsertAt(PPNODE First,int no,int ipos)
{
    int nodecnt=0,icnt=0;
    PNODE newn=NULL;
    PNODE temp=NULL;
    nodecnt = Count(*First);
    if((ipos < 1)||(ipos > (nodecnt+1)))
    {
        printf("invalid position\n");
    }
    if (ipos==1)
    {
        InsertFirst(First,no);
    }
    else if (ipos==nodecnt+1)
    {
       InsertLast(First,no);
    }
    else
    {
        newn=(PNODE)malloc(sizeof(NODE));
        newn->data=no;
        newn->next=NULL;

        temp=*First;
        for ( icnt = 1; icnt < ipos; icnt++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;
    }   
}
  void  DeleteAt(PPNODE First,int ipos)
{
    PNODE temp1=NULL;
    PNODE temp2=NULL;

    int icnt=0,nodecnt=0;
    nodecnt=Count(*First);

    if ((ipos < 1)||(ipos > nodecnt))
    {
        printf("invalid position\n");
    }
    if (ipos==1)
    {
        DeleteFirst(First);
    }
    else if (ipos==nodecnt+1)
    {
        DeleteLast(First);
    }
    else
    {
        temp1=*First;
        for ( icnt = 1; icnt < ipos-1; icnt++)
        {
            temp1=temp1->next;
        }
        temp2=temp1->next;
        temp1->next=temp2->next;
        free(temp2);
    }

}
void Display(PNODE First)
{
    printf("Elements from linklist are: \n");
    while (First!=NULL)
    {
        printf("|%d|->",First->data);
        First=First->next;
    }
    printf("NULL \n");
}
int Count(PNODE First)
{   
   int icnt=0;
    while (First!=NULL)
    {
        First=First->next;
        icnt++;
    }
    return icnt;
}
int main()
{   //struct node * Head=null;
     int iret=0;
    PNODE Head=NULL;
    InsertFirst(&Head,51);//(60,51)
    InsertFirst(&Head,21);//(60,21)
    InsertFirst(&Head,11);//(60,11)
        Display(Head);
   iret=Count(Head);
   printf("node is:%d",iret);


    InsertLast(&Head,101);
    InsertLast(&Head,102);
        Display(Head);
   iret=Count(Head);
   printf("node is:%d",iret);

     DeleteFirst(&Head);
     DeleteLast(&Head);
    Display(Head);
   iret=Count(Head);
   printf("node is:%d",iret);

    InsertAt(&Head,105,5);
        Display(Head);
   iret=Count(Head);
   printf("node is:%d",iret);

    DeleteAt(&Head,5);
        Display(Head);
   iret=Count(Head);
   printf("node is:%d",iret);

    return 0 ;
}