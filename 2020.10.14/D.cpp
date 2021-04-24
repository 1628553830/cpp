#include<iostream>
using namespace std;
int main()
{
    int n,m,begin,end;
    while(cin>>n>>m)
    {
        for(int i=1;i<=n/m;i++)
        {
          begin=1+(i-1)*m,end=i*m;
          if(n%m)cout<<begin+end<<" ";
          else if(i!=n/m)cout<<begin+end<<" ";
          else cout<<begin+end;
        }
        if(n%m)
        {
           begin=n/m*m+1;end=n;
           cout<<begin+end;
        }
        cout<<endl;
    }
}