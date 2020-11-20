#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N,ball,pscore,oscore;
    cin>>N;
    while(N--)
    {
       cin>>ball>>pscore>>oscore;
       if(ball>=6)pscore+=(ball-6)*8+27;
       else pscore+=(15-ball)*ball/2;
       if(pscore>=oscore)cout<<"Yes\n";
       else cout<<"No\n";
    }
    cin.get();
    cin.get();
}