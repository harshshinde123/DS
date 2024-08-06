#include<iostream>
using namespace std;

class Arrayx
{
    public:
    int *Arr;
    int isize;

    Arrayx(int i)
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
   Arrayx obj (5);//static& hardcoded
   obj.Accept();
   obj.Display();


   return 0;
}