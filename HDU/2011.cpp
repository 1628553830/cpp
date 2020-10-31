#include<bits/stdc++.h>
using namespace std;
int main()
{
     int m,x,f=1;double sum=0;;
     cin>>m;
     cout.precision(2);
     while(m--)
     {
         cin>>x;
        for(int i=1;i<=x;i++)
        {
            sum+=f*1.0/i;
            f=-f;
        }
        cout<<fixed<<sum<<endl;
        sum=0;
        f=1;
     }
     cin.get();
     cin.get();
}