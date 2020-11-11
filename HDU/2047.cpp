#include<iostream>
using namespace std;
int main()
{
    long long num[51]{0,3,8};
    int n;
    for(int i=3;i<40;i++)
    num[i]=2*num[i-1]+2*num[i-2];
    while(cin>>n)cout<<num[n]<<endl;
    
}