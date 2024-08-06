#include<iostream>
using namespace std;

class Numbers
{
    public:
    int no=0;

    Numbers(int i)
    {
        no=i;
    }

    int Factorial()
    {
        int fact=1;
        int i=0;
        for ( i = 1; i <= no ; i++)
        {
            fact=fact * i;
        }
        return fact;
    }


};
int main ()
{
    int iret=0;
    int ivalue=0;
    cout<<"Enter no:\n";
    cin>>ivalue;
    Numbers obj (ivalue);

    iret=obj.Factorial();
    cout<<"Fact is:"<<iret<<"\n";


   return 0;
}