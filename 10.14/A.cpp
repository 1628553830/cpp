#include<iostream>
using namespace std;
int main()
{
    int a[3],b[3],n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[0]>>a[1]>>a[2]>>b[0]>>b[1]>>b[2];
        a[0]+=b[0];
        a[1]+=b[1];
        a[2]+=b[2];
        for(int j=2;j>0;j--)
        {a[j-1]+=a[j]/60;a[j]%=60;}
        cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
    }
    cin.get();
    cin.get();
}