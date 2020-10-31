#include<bits/stdc++.h>
using namespace std;
int main()
{
    double a,b,sum=0;
    while(cin>>a>>b)
   {
        while(b--)
    {
        sum+=a;
        a=sqrt(a);
    }
    cout.precision(2);
    cout<<fixed<<sum<<endl;
    sum=0;
   }
   
}