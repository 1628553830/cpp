#include<iostream>
using namespace std;
int main()
{
    long long n,m,r,t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        //欧几里得辗转相除
        while(m%n)
        {
            r=m%n;
            m=n;n=r;   
        }
       if(t)cout<<n<<endl<<endl;
       else cout<<n<<endl;
    }
    cin.get();
    cin.get();
}