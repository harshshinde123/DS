#include<stdio.h>
#include<stdlib.h>
#pragma pack(1)
struct node
{
  int data;
  struct node *next;
  struct node *prev;
};
 typedef  struct node NODE;
 typedef  struct node * PNODE;
 typedef  struct node** PPNODE;

void InsertFirst(PPNODE First,PPNODE Last,int no)
{
 PNODE newn=(PNODE)malloc(sizeof(NODE));
 newn->data=no;
 newn->next=NULL;
 newn->prev=NULL;

 if ((*First==NULL)&&(*Last==NULL))
 {
    *First=newn;
    *Last=newn;
 }
 else
 {
   newn->next=*First;
   (*First)->prev=newn;
   *First=newn;

 }
 (*First)->prev=*Last;
 (*Last)->next=*First;
 
}
void InsertLast(PPNODE First,PPNODE Last,int no)
{
 PNODE newn=(PNODE)malloc(sizeof(NODE));
 newn->data=no;
 newn->next=NULL;
 newn->prev=NULL;

 if ((*First==NULL)&&(*Last==NULL))
 {
    *First=newn;
    *Last=newn;
 }
 else
 {
   (*Last)->next=newn;
   newn->prev=*Last;
   *Last=newn;
 }
 (*First)->prev=*Last;
 (*Last)->next=*First;
 
}
void DeleteFirst(PPNODE First,PPNODE Last)
{
    if (*First==NULL && *Last==NULL)
  {
    return;
  }
  else if (*First==*Last)
  {
    free(*First);
    *First=NULL;
    *Last=NULL;

  }
  else
  {
    *First=(*First)->next;
    free((*Last)->next);

    (*First)->prev=*Last;
    (*Last)->next=*First;  //free(*First)->Prev;
  }
  
  
}
void DeleteLast(PPNODE First,PPNODE Last)
{
    if (*First==NULL && *Last==NULL)
  {
    return;
  }
  else if (*First==*Last)
  {
    free(*First);
    *First=NULL;
    *Last=NULL;

  }
  else
  {
    *Last=(*Last)->prev;
    free((*First)->prev);//free(*Last)->next;
    
    (*First)->prev=*Last;
    (*Last)->next=*First;
  }
  
}
void InsertAtpos(PPNODE First,PPNODE Last,int no,int ipos)
{
  int iNodecnt=0;
   iNodecnt = Count(*First,*Last);

  if ((ipos<1)&&(ipos>iNodecnt+1))
  {
    printf("Invalid position\n");
    return;
  }
  if (ipos==1)
  {
    InsertFirst(First,Last,no);
  }
  
  else if (ipos==iNodecnt+1)
  {
    InsertLast(First,Last,no);
  }
  else
  {
   PNODE newn=(PNODE)malloc(sizeof(NODE));
   newn->data=no;
   newn->next=NULL;
   newn->prev=NULL;

   PNODE temp=*First;
    for (int icn = 1; icn < ipos-1; icn++)
    {
      temp=temp->next;
    }
    newn->next=temp->next;
    temp->next->prev=newn;
    
    temp->next=newn;
    newn->prev=temp;
  
  }
  
  
}void DeleteAtpos(PPNODE First,PPNODE Last,int ipos)
{
  int iNodecnt= Count(*First,*Last);
  if ((ipos<1)&&(ipos>iNodecnt+1))
  {
    printf("Invalid position\n");
    return;
  }
  if (ipos==1)
  {
    DeleteFirst(First,Last);
  }
  
  else if (ipos==iNodecnt)
  {
    DeleteLast(First,Last);
  }
  else
  {
    PNODE temp = *First;
    for (int icn = 1; icn < ipos-1; icn++)
    {
      temp=temp->next;
    }
     temp->next=temp->next->next;
     free(temp->next->prev);
     temp->next->prev=temp;
 
  }
 
}

void Display(PNODE First,PNODE Last)
{
  if  (First==NULL && Last==NULL)
  {
    printf("List is Empty\n");
  }
  printf("LinkList are:\n");
  do
  {
    printf("|%d|->",First->data);
           First=First->next;
  } while (First!=Last->next);
  printf("\n");
  
}
int Count(PNODE First,PNODE Last)
{
    int icnt=0;
  if (First==NULL && Last==NULL)
  {
    return icnt;
  }
  do
  {
    icnt++;
    First=First->next;
  } while (First!=Last->next);
  
}
int main()
{
    PNODE Head=NULL;
    PNODE Tail=NULL;
    int iret = 0;
    InsertFirst(&Head,&Tail,51);
    InsertFirst(&Head,&Tail,21);
    InsertFirst(&Head,&Tail,11);

    InsertLast(&Head,&Tail,101);
    InsertLast(&Head,&Tail,111);
    InsertLast(&Head,&Tail,121);

    Display(Head,Tail);
    iret=Count(Head,Tail);
    printf("elements are:%d\n",iret);

    InsertAtpos(&Head,&Tail,105,5);
    Display(Head,Tail);
    iret=Count(Head,Tail);
    printf("elements are:%d\n",iret);

    DeleteAtpos(&Head,&Tail,5);
    Display(Head,Tail);
    iret=Count(Head,Tail);
    printf("elements are:%d\n",iret);

    DeleteFirst(&Head,&Tail);
    DeleteLast(&Head,&Tail);
    Display(Head,Tail);
    iret=Count(Head,Tail);
    printf("elements are:%d\n",iret);


    return 0;
}