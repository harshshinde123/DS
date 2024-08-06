#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};


typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;


void InsertLast(PPNODE First, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));      
    PNODE temp = *First;
    newn->data = no;
    newn->next = NULL;

    if(*First == NULL)  
    {
        *First = newn;
    }
    else                
    {
        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
}

void InsertFirst(PPNODE First, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));      

    newn->data = no;
    newn->next = NULL;

    if(*First == NULL) 
    {
        *First = newn;
    }
    else                
    {
        newn->next = *First;
        *First = newn;
    }
}

void Display(PNODE First)
{
    printf("Elements from the Linked List are : \n");

    while(First != NULL)
    {
        printf("| %d |-> ",First->data);
        First = First -> next;
    }
    printf("NULL \n");
}

int Count(PNODE First)
{
    int iCnt = 0;

    while(First != NULL)
    {
        iCnt++;
        First = First -> next;
    }
    return iCnt;
}

void DeleteFirst(PPNODE First)
{
    PNODE temp = *First;

    if(*First == NULL)  // A
    {
        return;
    }
    else if((*First) -> next == NULL) //B
    {
        free(*First);
        *First = NULL;
    }
    else // C
    {
        (*First) = (*First) -> next;
        free(temp);
    }
}

void DeleteLast(PPNODE First)
{
    PNODE temp = *First;

    if(*First == NULL)  // Empty LL
    {
        return;
    }
    else if((*First) -> next == NULL) // 1 node in LL
    {
        free(*First);
        *First = NULL;
    }
    else // More than 1 node in LL
    {
        while(temp ->next -> next != NULL)
        {
            temp = temp -> next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void InsertAt(PPNODE First, int no, int ipos)
{
    int NodeCnt = 0, iCnt = 0;
    PNODE newn = NULL;
    PNODE temp = NULL;

    NodeCnt = Count(*First);

    if((ipos < 1) || (ipos > (NodeCnt + 1)))
    {
        printf("Invalid position\n");
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(First,no);
    }
    else if(ipos == NodeCnt+1)
    {
        InsertLast(First,no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = no;
        newn->next = NULL;

        temp = *First;

        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp->next = newn;
    }
}

void DeleteAt(PPNODE First, int ipos)
{
    PNODE temp1 = NULL;
    PNODE temp2 = NULL;
    int iCnt = 0, NodeCnt = 0;
    NodeCnt = Count(*First);

    if((ipos < 1) || (ipos > NodeCnt))
    {
        printf("Invalid position\n");
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst(First);
    }
    else if(ipos == NodeCnt)
    {
        DeleteLast(First);
    }
    else
    {
        temp1 = *First;
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;  // temp1->next = temp1->next->next;
        free(temp2);
    }
}

int main()
{   //struct node * Head=null;
     int iret=0,ichoice=0,ipos=0,ino=0;
    PNODE Head=NULL;
    printf("welcome to data structure Application written by Harshawardhan\n");
    while (1)
    {
        printf("____________________________________\n");
        printf("Please   slect option:\n");
        printf("1 Insert Node at First position\n");
        printf("2 Insert Node at Last position\n");
        printf("3 Insert Node at Given position\n");
        printf("4 Delete Node at First position\n");
        printf("5 Delete Node at Last position\n");
        printf("6 Delete Node at Given position\n");
        printf("7 Display position at LinkList\n");
        printf("8 Count Node from Linklist\n");

                scanf("%d",&ichoice);
                switch (ichoice)
                {
                case 1:
                printf("Enter Data\n");
                scanf("%d",&ino);
                InsertFirst(&Head,ino);
                    
                    break;
                 case 2:
                 printf("Enter Data\n");
                scanf("%d",&ino);
                InsertLast(&Head,ino);
                    
                    
                    break;
                     case 3:
                     printf("Enter Data\n");
                    scanf("%d",&ino);
                    printf("Enter position\n");
                    scanf("%d",&ipos);
                    InsertAt(&Head,ino,ipos);
                    
                     break;
                     case 4:
                    DeleteFirst(&Head);
                    break;
                     case 5:
                    DeleteLast(&Head);
                    break;
                     case 6:
                    printf("Enter position\n");
                    scanf("%d",&ipos);
                    DeleteAt(&Head,ipos);
                    break;
                     case 7:
                    Display(Head);
                    break;
                     case 8:
                    iret=Count(Head);
                    printf("no of element are:%d\n",iret);
                    break;
                     case 9:
                    printf("thanku for using application\n");
                    return 0;
                        
                
                default:
                printf("invalid option\n");
                    break;
                }
       
        printf("____________________________________\n");

    }
    
    

    return 0 ;
}