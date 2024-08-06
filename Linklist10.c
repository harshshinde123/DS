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

int main()
{   //struct node * Head=null;
     
    PNODE Head=NULL;
   

    InsertLast(&Head,11);
    InsertLast(&Head,21);
    InsertLast(&Head,51);
    InsertLast(&Head,101);
    InsertLast(&Head,121);
    InsertLast(&Head,151);
        Display(Head);
   

    return 0 ;
}