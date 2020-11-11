#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,h1,m1,s1,h2,m2,s2;
    cin>>n;
    while(n--)
    {
        cin>>h1>>m1>>s1>>h2>>m2>>s2;
        s1+=s2;
        m1+=m2;
        h1+=h2;
        m1+=s1/60;s1%=60;
        h1+=m1/60;m1%=60;
        cout<<h1<<" "<<m1<<" "<<s1<<endl;
    }
    cin.get();
    cin.get();
}