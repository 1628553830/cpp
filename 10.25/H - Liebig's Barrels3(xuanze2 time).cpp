#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,l,num[100000],min,max;cin>>n>>k>>l;
    long long sum=0;
    for(int i=0;i<n*k;i++)cin>>num[i];
    for(int i=0;i<n*k/2;i++)
    {
      min=i;max=n*k-i-1;//双向排序
      for(int j=i+1;j<n*k;j++){min=num[j]<num[min]?j:min;max=num[max]<num[j]?j:max;}
      if(min!=i)swap(num[i],num[min]);
      if(max==i)swap(num[max],num[min]);
      else if(max!=n*k-i-1)swap(num[max],num[n*k-i-1]);
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