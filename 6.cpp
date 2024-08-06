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

    void Function()
    {
        
    }


};
int main ()
{
    int ivalue=0;
    cout<<"Enter no:\n";
    cin>>ivalue;
    Numbers obj (ivalue);

    obj.Function();


   return 0;
}