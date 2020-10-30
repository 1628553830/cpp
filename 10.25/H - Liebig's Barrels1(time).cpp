#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,l,num[100000],pos=-1,ans=0;cin>>n>>k>>l;
    long long sum=0;
    for(int i=0;i<n*k;i++)cin>>num[i];
    sort(num,num+n*k);
    if(num[0]<num[n-1]-l)cout<<0;
    else 
    {
      while(num[0]+l>=num[++pos]&&pos<n*k);
      sum=num[0];
      for(ans=0;pos-1>(ans+1)*(k-1)+n;ans++)
      sum+=num[ans*k];
      ans++;
      for(int i=pos-1;i>=pos-n+ans;i--)
      sum+=num[i];
      cout<<sum;
    }
    cin.get();
    cin.get();
}