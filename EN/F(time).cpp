#include<bits/stdc++.h>
using namespace std;
bool isprime(int x)
{
   for(int i=2;i<=sqrt(x);i++)
   if(x%i==0)return false;
   return true;
}
bool ishui(int x)
{
    int t=0,m=x;
    while(x)
    {
        t=t*10+x%10;
        x/=10;
    }
    return t==m;
}
int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        a=a+1-a%2;
        for(int i=a;i<=b;i+=2)
           if(ishui(i)&&isprime(i))printf("%d\n",i);
        cout<<endl;
    }
    cin.get();
    cin.get();
}