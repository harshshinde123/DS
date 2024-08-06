#include<iostream>
using namespace std;
class DigitX
{
  public:
  int ino;
    
    DigitX()
    {
        ino=0;
    }
    DigitX(int i)
    {
         ino=i;
    }
};
int main ()
{  int ivalue=0;
 cout<<"enter no:\n";
 cin>>ivalue;
 DigitX obj (ivalue);
 cout<<obj.ino<<"\n";

   return 0;
}