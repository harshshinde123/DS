#include<iostream>
using namespace std;

class Arithematic
{
    public:
  int Addition(int ivalue,int ivalue2)
{
    int add=0;

    add= ivalue+ivalue2;

    return add;
}
};
int main ()
{
    int ino1 = 0,ino2=0 ,ians=0;
  cout<<"Enter first no:\n";
  cin>>ino1;

   cout<<"Enter second no:\n";
   cin>>ino2;

  Arithematic obj;

  ians= obj.Addition(ino1,ino2);

  cout<<"Addition is:"<<ians<<"\n";

   return 0;
}