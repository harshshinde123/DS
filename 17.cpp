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
    void DisplayFreq()
    {   int icnt=0;
        int itemp=ino;
        int digit=0;
        int freq[10]={0};
        while (itemp!=0)
        {
            digit=itemp%10;
            freq[digit]++;
            itemp=itemp/10;
        }
        for ( icnt = 0; icnt < 10; icnt++)
        {
            if(freq[icnt]>0)
            {
            cout<<icnt<<" occrs at"<<freq[icnt]<<"times"<<"\n";
            }
        }
        
        
    }
};
int main ()
{  int ivalue=0,iret=0;
 cout<<"enter no:\n";
 cin>>ivalue;
 DigitX obj (ivalue);
 obj.DisplayFreq();

   return 0;
}