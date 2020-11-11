#include<iostream>
using namespace std;
int main()
{
    string a;
    int ans=0,n;
    cin>>n;cin.get();
    while(n--)
    {
        getline(cin,a);
        for(int i=0;i<a.length();i++)
            if(a[i]<0||a[i]>127)ans++;
        cout<<ans/2<<endl;//汉字在这里是2个字节
        ans=0;
    }
}