#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,l,num[100000],x;cin>>n>>k>>l;
    long long sum=0;
    for(int i=0,j;i<n*k;i++)
      {
        cin>>num[i];x=num[i];
        for(j=i-1;j>=0&&num[j]>x;j--)
            num[j+1]=num[j];
        num[j+1]=x;
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