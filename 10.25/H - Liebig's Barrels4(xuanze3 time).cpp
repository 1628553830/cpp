#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,l,num[100000],min;cin>>n>>k>>l;
    long long sum=0;
    for(int i=0;i<n*k;i++)scanf("%d",&num[i]);
    for(int i=0;i<n;i++)
    {
      min=i;
      for(int j=i+1;j<n*k;j++)min=num[j]<num[min]?j:min;
      if(min!=i)swap(num[min],num[i]);
    }
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