#include<iostream>
using namespace std;
int main()
{
    int n; 
    long long sum[51]={0,3,6,6};
    for(int i=4;i<=50;i++)
     sum[i]=sum[i-1]+sum[i-2]*2;  
    while(cin>>n)
      cout<<sum[n]<<endl;
    
}
