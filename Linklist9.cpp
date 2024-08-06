#include<iostream>
using namespace std;
#pragma pack(1)
struct node
{
    int data;
    struct node *next;
    struct node *prev;
        
}; 
 typedef struct node NODE ; 
 typedef struct node * PNODE;   
 typedef struct node ** PPNODE ;

class DoublyLL 
{
    public:
    PNODE  First;
    int icount;

   DoublyLL();
   void InsertFirst(int);
   void InsertLast(int);
   void InsertAtPos(int,int);

   void DeleteFirst();
   void DeleteLast();
   void DeleteAtPos(int);

   void Display();


};
DoublyLL::DoublyLL()
{
    First=NULL;
    icount=0;
}
  void DoublyLL::InsertFirst(int no)
  {
   PNODE newn = new NODE;
   newn->data=no;
   newn->next=NULL;
   newn->prev= NULL;

   if (First==NULL)
   {
       First=newn;
       icount++;
   }
   else
   {
    newn->next=First;
    First->prev=newn;
    First=newn;
    icount++;
   }
   
  }
   void DoublyLL::InsertLast(int no)
   {
   PNODE newn = new NODE;
   newn->data=no;
   newn->next=NULL;
   newn->prev= NULL;

   if (First==NULL)
   {
       First=newn;
       icount++;
   }
   else
   {
    PNODE temp=First;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newn;
    newn->prev=temp;
    icount++;
    
   }
   }
   void DoublyLL::InsertAtPos(int no,int ipos)
   {  
     
     if ((ipos<1)||(ipos>icount+1))
     {
        cout<<"invalid position"<<"\n";
     }
      if (ipos==1)
    {
        InsertFirst(no);
    }
    else if (ipos==icount+1)
    {
        InsertLast(no);
    }
    else
    {
        PNODE newn = new NODE;
        newn->data=no;
        newn->next=NULL;
        newn->prev=NULL;
        PNODE temp=First;
        for (  int icnt = 1; icnt < ipos-1; icnt++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;
        newn->prev=temp;
        icount++;

    }
     
   }

   void DoublyLL::DeleteFirst()
   {
     if (First==NULL)
     {
        return;
     }
     else if (First->next==NULL)
     {
        delete(First);
        First=NULL;
     }
     else
     {
       First=First->next;
       delete(First->prev);
       First->prev=NULL;
       icount--;
     }
     
     
   }
   void DoublyLL::DeleteLast()
   {
     if (First==NULL)
     {
        return;
     }
     else if (First->next==NULL)
     {
        delete(First);
        First=NULL;
     }
     else
     {
        PNODE temp=First;
        while (temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        delete(temp->next);
        temp->next= NULL;
        icount--;
        
     }
   }
   void DoublyLL::DeleteAtPos(int ipos)
   {
       if ((ipos<1)||(ipos>icount+1))
     {
        cout<<"invalid position"<<"\n";
     }
      if (ipos==1)
    {
        DeleteFirst();
    }
    else if (ipos==icount+1)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp1=First;
        PNODE temp2=NULL;
        for (int  icnt = 1; icnt < ipos-1; icnt++)
        {
           temp1=temp1->next;
        }
        temp2=temp1->next;
        temp1->next=temp2->next;
        delete(temp2);
        icount--;
    }
   }

   void DoublyLL::Display()
   {
      cout<<"elements of LL are :"<<"\n";
    PNODE temp=First;
    while (temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp=temp->next;
    }
    cout<<"null"<<"\n";
     
   }

   int main()
 {
 DoublyLL obj1;

 cout<<sizeof(obj1)<<"\n";
 cout<<"first pointer contain:"<<obj1.First<<"\n";
 cout<<"number of  node are:"<<obj1.icount<<"\n"; 

 obj1.InsertFirst(51);
 obj1.InsertFirst(21);
 obj1.InsertFirst(11);

 obj1.Display();
 cout<<" First node are:"<<obj1.icount<<"\n";

 

 obj1.InsertLast(101);
 obj1.InsertLast(111);
 obj1.InsertLast(121);

 obj1.Display();
 cout<<"node are:"<<obj1.icount<<"\n";

 obj1.InsertAtPos(105,4);
 obj1.Display();
 cout<<"node are:"<<obj1.icount<<"\n";

 obj1. DeleteFirst();
 obj1.Display();
 cout<<"node are:"<<obj1.icount<<"\n";

 obj1. DeleteLast();
 obj1.Display();
 cout<<"node are:"<<obj1.icount<<"\n";

 obj1.DeleteAtPos(5);
 obj1.Display();
 cout<<"node are:"<<obj1.icount<<"\n";
 
    return 0;
 }