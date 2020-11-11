#include<iostream>
using namespace std;
const int T=1E5;
int main()
{
    bool lamps[T+1]{};
    int n;
    while(cin>>n)
    {
        for(int i=n;i<T;i+=n)
        lamps[i]=!lamps[i];
        cout<<lamps[n]<<endl;
    }
}