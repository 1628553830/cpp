#include<iostream>
using namespace std;
int ll(int);
int main()
{
    int n,count=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        if(ll(i)%2)count++;
    }
    cout<<count<<endl;
    cin.get();
    cin.get();
}
int ll(int x)
{
    int count=1;
    while(x/10)
    {
        count++;
        x/=10;
    }
    return count;
}