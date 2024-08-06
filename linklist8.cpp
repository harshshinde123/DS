#include<iostream>
using namespace std;
#pragma pack(1)
struct node
{
    int data;
    struct node *next;
    
};
 typedef struct node NODE;
 typedef struct node* PNODE;
 typedef struct node** PPNODE;
 class SinglyLL
 {
   public:
   PNODE First;
   int icount;

   SinglyLL();
   void InsertFirst(int);
   void InsertLast(int);
   void InsertAtPos(int,int);

   void DeleteFirst();
   void DeleteLast();
   void DeleteAtPos(int);

   void Display();
   
 };
 SinglyLL::SinglyLL()
 {
    First=NULL;
    icount=0;

 }
 void SinglyLL:: InsertFirst(int no)
 {
    PNODE newn=new NODE;
    newn->data=no;
    newn->next=NULL;
    if (First==NULL)
    {
        First=newn;
        icount++;
    }
    else
    {
      newn->next=First;
      First=newn;
      icount++;
    }
    
 }
 void SinglyLL:: InsertLast(int no)
  {
     PNODE newn=new NODE;
    newn->data=no;
    newn->next=NULL;
    if (First==NULL)
    {
        First=newn;
        icount++;
    }
    else
    {
       PNODE temp= First;
      while( temp->next!=NULL )
      {
       temp=temp->next;
      }
      temp->next=newn;
      icount++;
    }
    
  }

 void SinglyLL:: InsertAtPos(int no,int ipos)
 {
    if ((ipos<1)||(ipos>icount+1))
    {
        cout<<"invalod position"<<"\n";
    }
    if (ipos==1)
    {
        InsertFirst(no);
    }
    else if (ipos==icount+1)
    {
        InsertLast(no);
    }
    else{
        PNODE newn=new NODE;
        newn->data=no;
        newn->next=NULL;    
        PNODE temp=First;
        for (int icnt = 1; icnt < ipos-1; icnt++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;
        icount++;
     }   
 }

 void SinglyLL:: DeleteFirst()
 {
    if (First==NULL)
    {
        return;
    }
    else if (First->next==NULL)
    {
        delete First;
        First=NULL;
        icount--;

    }
    else
    {
      PNODE temp= First;
      First=First->next;
      delete temp;
      icount--;
    }
    
    
 }

 void SinglyLL:: DeleteLast()
 {
     if (First==NULL)
    {
        return;
    }
    else if (First->next==NULL)
    {
        delete First;
        First=NULL;
        icount--;

    }
    else
    {
        PNODE temp=First;
        while (temp->next->next!=0)
        {
        temp=temp->next;
        }
        delete temp->next;
        temp->next= NULL;
        icount--;
    }
 }

 void SinglyLL:: DeleteAtPos(int ipos)
 {
    if ((ipos<1)||(ipos>icount+1))
    {
        cout<<"invalod pos"<<"\n";
    }
    if (ipos==1)
    {
        DeleteFirst();
    }
    else if (ipos==icount)
    {
        DeleteLast();
    }
    else{
        PNODE temp1=First;
        for (int icnt = 1; icnt < ipos-1; icnt++)
        {
         temp1=temp1->next;
        }
        PNODE temp2=temp1->next;
        temp1->next=temp2->next;
        delete temp2;
        icount--;
    }
        
 }

  void SinglyLL:: Display()
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
 SinglyLL obj1;
 SinglyLL obj2;
 cout<<sizeof(obj1)<<"\n";
 cout<<"first pointer contain:"<<obj1.First<<"\n";
 cout<<"number of  node are:"<<obj1.icount<<"\n"; 

 obj1.InsertFirst(51);
 obj1.InsertFirst(21);
 obj1.InsertFirst(11);

 obj1.Display();
 cout<<" First node are:"<<obj1.icount<<"\n";

 obj2.InsertFirst(510);
 obj2.InsertFirst(210);
 obj2.InsertFirst(110);

 obj2.Display();
 cout<<"Second node are:"<<obj2.icount<<"\n";

 obj1.InsertLast(101);
 obj1.InsertLast(111);
 obj1.InsertLast(121);

 obj1.Display();
 cout<<"node are:"<<obj1.icount<<"\n";

 obj1.InsertAtPos(105,5);
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