#include<iostream>
using namespace std;
int main()
{
    char a;
    cin>>a;
    for(int i=1;i<=3;i++)
    {
        for(int j=3-i;j>0;j--)
        cout<<" ";
        for(int j=1;j<=2*i-1;j++)
        cout<<a;
        cout<<endl;
    }
    cin.get();
    cin.get();
    
}