#include<iostream>
using namespace std;

class Arrayx
{
    public:
    int *Arr;
    int isize;
   Arrayx(int i)//constructor
    {
        isize=i;
        Arr=new int (isize);
    }
   ~Arrayx()
    {
        delete []Arr;

    }
    void Accept()
    {
            cout<<"Enter no:\n";
            int icnt=0;

            for ( icnt = 0; icnt <isize ; icnt++)
            {
                cin>>Arr[icnt];
            }
    } 
    void Display()
    {
            cout<<"Elements are:\n";
            int icnt=0;

            for ( icnt = 0; icnt <isize ; icnt++)
            {
                cout<<Arr[icnt]<<"\t";
            }
            
           cout<<"\n";
    }    
};
class MrvellousLB: public Arrayx
{
    public:
    MrvellousLB(int i): Arrayx(i)
    { }
int Minimum()
    {    int icnt=0;
        int min =Arr[0];
        for ( icnt = 0; icnt < isize; icnt++)
        {
        if (Arr[icnt]<min)
        {
            min=Arr[icnt];
        }
        
        }
       return min; 
    }
};
int main ()
{   
   int ilength=0;
   int iret=0; 
   cout<<"Enter no of element\n";
   cin>>ilength;
   MarvellousLB * obj = new MarvellousLB(ilength);
   obj->Accept();
   obj->Display();
   iret=obj->Minimum();
   cout<<"no is:"<<iret<<"\n";

   delete obj;

   return 0;
}