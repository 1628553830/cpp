#include<bits/stdc++.h>
using namespace std;
int num[1000000];
int main()
{
    long long T,n;
    long long sum=0;
    cin>>T;
    while(T--)
    {
       scanf("%lld",&n);
       for(int i=0;i<n;i++){scanf("%d",&num[i]);sum+=num[i];}
       sort(num,num+n);
       if(num[n-1]*2-1<=sum)cout<<"Yes"<<endl;
       else cout<<"No"<<endl;
       sum=0;
    }
    cin.get();
    cin.get();
}