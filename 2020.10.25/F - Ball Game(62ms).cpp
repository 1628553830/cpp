#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,pos=1;
    cin>>n;
    for(int i=1;i<n;i++)
    {   pos+=i;
        cout<<(pos-1)%n+1<<" ";
    }
    cin.get();
    cin.get();
}