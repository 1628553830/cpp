#include<iostream>
using namespace std;
int main()
{
    int n;bool flag=false;
    cin>>n;
    for(int i=1;(i+1)*i/2<=n;i++)if((i+1)*i/2==n){cout<<"YES";flag=true;break;}
    if(!flag)cout<<"NO";
    cin.get();
    cin.get();
}