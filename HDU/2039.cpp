#include<iostream>
using namespace std;
int main()
{
    double n,a,b,c;
    cin>>n;
    while(n--)
    {
        cin>>a>>b>>c;
        if(a>=b+c||c>=b+a||b>=a+c)
        cout<<"NO\n";
        else 
        cout<<"YES\n";
    }
    cin.get();
    cin.get();
}