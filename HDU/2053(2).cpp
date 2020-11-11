#include<iostream>
#include<cmath>
using namespace std;
int count(int a)
{
    int s=sqrt(a),ans=0;
    for(int i=1;i<=s;i++)
    if(a%i==0)ans+=2;
    if(s*s==a)return ans-1;
    return ans;
}
int main()
{
    int n,max=0;
    while(cin>>n)
      cout<<count(n)%2<<endl;
}