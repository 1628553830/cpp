#include<iostream>
using namespace std;
int main()
{
    long long num[51]{0,1,2,3};
    int n;
    for(int i=4;i<=50;i++)
    num[i]=num[i-1]+num[i-2];
    while(cin>>n)cout<<num[n]<<endl;
    
}