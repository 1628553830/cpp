#include<iostream>
using namespace std;
int main()
{
    int n,p=1;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {int x;cin>>x;if(x%2)p*=x;}
        cout<<p<<endl;
        p=1;
    }
}