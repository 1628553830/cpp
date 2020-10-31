#include<iostream>
using namespace std;
int main()
{
    int a,sum=1;
    while(cin>>a)
    {
        a--;
        while(a--)
        sum=(sum+1)*2;
        cout<<sum<<endl;
        sum=1;
    }
}