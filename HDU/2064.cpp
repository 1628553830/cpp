#include<iostream>
using namespace std;
int main()
{
    int N;
    long long f[36]{0,2};
    for(int i=2;i<=35;i++)
    f[i]=f[i-1]*3+2;
    while(cin>>N)
    {
        cout<<f[N]<<endl;
    }
}
