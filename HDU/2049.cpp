#include<iostream>
using namespace std;
long long C(int m,int n)
{
    long long t=1,s=1;
    for(int i=0;i<n;i++)
       t*=m-i;
    for(int i=1;i<=n;i++)
       s*=i;
    return t/s;
}
int main()
{
    long long num[21]{0,0,1,2};
    int n,N,M;cin>>n;
    for(int i=4;i<21;i++)
    num[i]=(num[i-1]+num[i-2])*(i-1);
    while(n--)
    {
        cin>>N>>M;
        cout<<C(N,N-M)*num[M]<<endl;
    }
    cin.get();
    cin.get();
}

