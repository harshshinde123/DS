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
int main()
{   //struct node * Head=null;
     int iret=0;
    PNODE Head=NULL;
    InsertFirst(&Head,51);//(60,51)
    InsertFirst(&Head,21);//(60,21)
    InsertFirst(&Head,11);//(60,11)

    InsertLast(&Head,101);
   InsertLast(&Head,102);

    Display(Head);
   iret=Count(Head);
   printf("node is:%d",iret);
   DeleteFirst(Head);
   DeleteLast(Head);



    return 0 ;
}