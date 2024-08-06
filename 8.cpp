#include<iostream>
using namespace std;

class ArrayX
{
public:
  int *Arr;
  int isize;

    ArrayX(int i)//constructor
    {
        isize=i;
        Arr=new int (isize);
    }
    ~ArrayX()// distructor
    {
        delete[]Arr;
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
    int SumEven()
    {
        int isum=0;
        int icnt =0;
        for ( icnt = 0; icnt < isize; icnt++)
        {
            if(Arr[icnt]%2==0)
            {
                isum=isum+Arr[icnt];
            }
        }
          return isum; 
    }
   
};
int main ()
{
 int iret=0;
 int ilength=0;
 cout<<"Enter no of element\n";
 cin>>ilength;
 ArrayX obj (ilength);
 obj.Accept();
 obj.Display();
 iret=obj.SumEven();
 cout<<"sumeven is:"<<iret<<"\n";


   return 0;
}