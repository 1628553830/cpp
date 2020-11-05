#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    while(cin>>m>>n)
    {
        for(int i=0;i<m/n;i++)
        {
           if(i)cout<<" ";
           cout<<n+1+2*i*n;
        }
        if(m%n)
        {
            if(m/n)cout<<" ";
            cout<<m/n*n+1+m;
        }
        cout<<endl;
    }
    
}