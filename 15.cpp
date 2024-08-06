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
    int SumEven()
    {
        int isum=0,idigit=0;
        while (ino!=0)
        {
            idigit=ino%10;
            if (idigit%2==0)
            {
                isum=isum+idigit;
            }
            ino=ino/10;
        }
       return isum; 
    }
};
int main ()
{  int ivalue=0,iret=0;
 cout<<"enter no:\n";
 cin>>ivalue;
 DigitX obj (ivalue);
 iret=obj.SumEven();
 cout<<"sim is:"<<iret<<"\n";

   return 0;
}