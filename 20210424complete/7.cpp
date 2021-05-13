#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int T,n,m,x,min;
    cin>>T;
    while(T--)
    {
        min=150;
        cin>>n>>m;
        while(n--)
        {
            cin>>x;
            min=x<min?x:min;
        }
        cout<<(100-min)*(100-min)<<endl;
    }
    cin.get();
    cin.get();
}