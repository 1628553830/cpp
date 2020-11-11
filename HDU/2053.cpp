#include<iostream>
#include<string.h>
using namespace std;
const int T=1E5;
int main()
{
    bool lamps[T+1]{};
    int n,max=0;
    while(cin>>n)
    {
        if(max<n)
       { 
        for(int i=max+1;i<=n;i++)
        for(int j=i;j<=T;j+=i)
        lamps[j]=!lamps[j];
        max=n;
       }
        cout<<lamps[n]<<endl;
    }
}