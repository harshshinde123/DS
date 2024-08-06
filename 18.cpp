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
    void MaxFreq()
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
        int maxfreq=0;
        int maxdigit=0;
        for ( icnt = 0; icnt < 10; icnt++)
        {
            if(freq[icnt]>maxfreq)
            {
                maxfreq=freq[icnt];
                maxdigit=icnt;
            }
                cout<<"max digitis"<<maxdigit<<"is"<<maxfreq<<"\n";

        }
        
        
    }
};
int main ()
{  int ivalue=0,iret=0;
 cout<<"enter no:\n";
 cin>>ivalue;
 DigitX obj (ivalue);
 obj.MaxFreq();

   return 0;
}