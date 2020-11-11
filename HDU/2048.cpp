#include<iostream>
using namespace std;
int main()
{
    double num[21]{0,0,1,2},gl;
    long long jiecheng[21]={1,1};
    int n,x;cin>>n;
    cout.precision(2);
    for(int i=2;i<21;i++)
    jiecheng[i]=jiecheng[i-1]*i;
    for(int i=4;i<21;i++)
    num[i]=(num[i-1]+num[i-2])*(i-1);
    while(n--)
    {
        cin>>x;
        gl=num[x]/jiecheng[x]*100;
        cout<<fixed<<gl<<"%"<<endl;
    }
    cin.get();
    cin.get();
}

