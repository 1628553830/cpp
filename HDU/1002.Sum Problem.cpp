#include<iostream>
using namespace std;
int main()
{
    long long n;
    while(cin>>n)cout<<n*(n+1)/2<<endl<<endl;//这里的n*(n+1)可能会很大，所以要用longlong
}
/*
#include<iostream>
using namespace std;
int main()
{
    int n,sum=0;
    while(cin>>n)
    {
       for(int i=1;i<=n;i++)
       sum+=i;
       cout<<sum<<endl<<endl;
       sum=0;
    }
}
*/