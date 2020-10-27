#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
        cout<<((i+1)*i/2)%n+1<<" ";
    cin.get();
    cin.get();
}