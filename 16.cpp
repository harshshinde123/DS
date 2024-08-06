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
        int isum=0,idigit=0,itemp=0;
        itemp=ino;
        while (itemp!=0)
        {
            idigit=itemp%10;
            if (idigit%2==0)
            {
                isum=isum+idigit;
            }
            itemp=itemp/10;
        }
       return itemp; 
    }
};
int main ()
{  int ivalue=0,iret=0;
 cout<<"enter no:\n";
 cin>>ivalue;
 DigitX obj (ivalue);
 iret=obj.SumEven();
 cout<<"sim is:"<<iret<<"\n";
  cout<<obj.ino<<"\n";


   return 0;
}