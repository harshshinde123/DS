#include<iostream>
using namespace std;

class Arithematic
{
    public:                  //Acceess spicifier
    int ivalue1,ivalue2;     //characterstics

    Arithematic()
    {
        ivalue1=0;            //Default constructor
        ivalue2=0;

    }

    Arithematic(int A,int B)  //parameterise constructor
    {
        ivalue1=A;            
        ivalue2=B;
    }
     
     int Addition()
        {
           int add=0;
           add= ivalue1+ivalue2;

          return add;
        }
     
};
int main ()
{
    int iret = 0;  
   Arithematic obj1;
   Arithematic obj2(10,11);
   Arithematic obj3(20,21);

   iret=obj1.Addition();
   cout<<"Addition is:"<<iret<<"\n";

   iret=obj2.Addition();
   cout<<"Addition is:"<<iret<<"\n";

   iret=obj3.Addition();
   cout<<"Addition is:"<<iret<<"\n";

   return 0;
}