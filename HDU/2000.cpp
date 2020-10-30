#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[4];
    while(cin>>a)
    {
        sort(a,a+3);
        for(int i=0;i<2;i++)cout<<a[i]<<" ";
        cout<<a[2]<<endl;
    }
    cin.get();
    cin.get();

}