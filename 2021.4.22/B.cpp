#include<iostream>
using namespace std;
int main()
{
    int k,x;
    cin>>k>>x;
    for(int i=0;i<=2*k-2;i++)
    {
        if(i)cout<<" ";
        cout<<i+x-k+1;
    }
    cin.get();
    cin.get();
}