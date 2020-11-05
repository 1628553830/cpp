#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b)
{
    return abs(a)>abs(b);
}
int main()
{
    int n,num[100];
    cin>>n;
    while(n)
    {
        for(int i=0;i<n;i++)cin>>num[i];
        sort(num,num+n,cmp);
        for(int i=0;i<n;i++)
        if(i)cout<<" "<<num[i];
        else cout<<num[i];
        cout<<endl;
        cin>>n;
    }
}