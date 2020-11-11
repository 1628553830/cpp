//f(1)=1 f(2)=7 f(3)=16 
//1 2  6 7  15 16  交点+1=区域数
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long num[10001]{0,1};
    int n,x;cin>>n;
    for(int i=2;i<10001;i++)
    num[i]=num[i-1]+(i-1)*4+1;
    while(n--)
    {
        cin>>x;
        cout<<num[x]+1<<endl;
    }
    cin.get();
    cin.get();
}