#include<iostream>
#include<cmath>
using namespace std;
bool check(int);
int main()
{
   int N,total=0;
   cin>>N;
   while(N)
   {
       for(int i=2;i<N/2;i%2?i+=2:i++)
          if(check(i)&&check(N-i))total++;
       cout<<total<<endl;
       total=0;
       cin>>N;
   }
}
bool check(int a)
{
    for(int i=2;i<=sqrt(a);i++)
     if(a%i==0)return false;
     return true;
}