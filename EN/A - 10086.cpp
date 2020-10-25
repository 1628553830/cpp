#include<iostream>
using namespace std;
int main()
{
    double x;
    cin>>x;
    if(x>0.5)cout<<3+(x-0.5)/0.2;
    else cout<<3;
    cin.get();
    cin.get();
}