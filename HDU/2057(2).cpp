#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    long long a,b;
    char a1,b1;
    while(cin>>hex>>a>>b)
    {
        a+=b;
        if(a<0)
       { a=-a;
        cout<<setiosflags(ios::uppercase)<<hex<<'-'<<a<<endl;}
        else 
        cout<<setiosflags(ios::uppercase)<<hex<<a<<endl;
    }
}
