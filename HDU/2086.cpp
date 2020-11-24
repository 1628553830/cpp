#include<iostream>
using namespace std;
int main()
{
   int n;
   double a0,an1,an,sum1=0,sum2=0;
   cout.precision(2);
   while(cin>>n)
   {
       cin>>a0>>an1;
       for(int i=0;i<n;i++)
       {
           cin>>an;
           sum1+=an;
           sum2+=sum1;
       }
       cout<<fixed<<(n*a0+an1-2*sum2)/(n+1)<<endl;
       sum1=sum2=0;
   }
}
