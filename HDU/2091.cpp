#include<iostream>
using namespace std;
int main()
{
    string a;
    double sum=0,n,m;
    cout.precision(1);
    while(cin>>a>>n>>m)
    {
       sum+=n*m;   
    }
    cout<<fixed<<sum<<endl;
    cin.get();
    cin.get();
}