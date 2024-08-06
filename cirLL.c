#include<stdio.h>
#include<stdlib.h>
#pragma pack(1)
struct node
{
    int data; 
    struct node *next;
};
 typedef  struct node NODE;
 typedef  struct node * PNODE;
 typedef  struct node** PPNODE;

void InsertFitst(PPNODE First,PPNODE Last,int no)
{
    PNODE newn=(PNODE)malloc(sizeof(NODE));


        
}
 int main()
 {
    PNODE Head=NULL;
    PNODE Tail=NULL;

    return 0;
 }