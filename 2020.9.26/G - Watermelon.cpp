#include<iostream>
using namespace std;
int main()
{
    int w;
    cin>>w;
    if(!(w%2)&&w!=2)cout<<"YES";//取反运算符'!'优先级比%大
    else cout<<"NO";
    cin.get();
    cin.get();
}