#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n,sum1=0,sum2=0;
    while(cin>>m>>n)
    {
        if(m>n)swap(m,n);//这里要注意大小
        for(int i=m;i<=n;i++)
    {
        if(i%2)sum1+=pow(i,3);
        else sum2+=pow(i,2);
    }
       cout<<sum2<<" "<<sum1<<"\n";
        sum1=sum2=0;
    }
}