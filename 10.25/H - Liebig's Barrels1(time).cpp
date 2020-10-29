#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,l,num[10000];cin>>n>>k>>l;
    long long sum=0;
    for(int i=0;i<n*k;i++)cin>>num[i];
    sort(num,num+n*k);
    if(num[0]<num[n-1]-l)cout<<0;
    else 
    {
      for(int i=0;i<n;i++)
      sum+=num[i];
      cout<<sum;
    }
    cin.get();
    cin.get();
}