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
    Arrayx()
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
int main ()
{   
   int ilength=0; 
   cout<<"Enter no of element\n";
   cin>>ilength;
   Arrayx * obj=new Arrayx(ilength);//dynamic
   obj->Accept();
   obj->Display();
   
   delete obj;

   return 0;
}