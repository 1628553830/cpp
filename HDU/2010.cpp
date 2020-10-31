#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;bool flag=true;
    while(cin>>a>>b)
    {
        for(int i=a;i<=b;i++)
            if(pow(i%10,3)+pow((i/10)%10,3)+pow(i/100,3)==i)
            {
                if(flag)cout<<i;
                else cout<<" "<<i;
                flag=false;
            }
        if(flag)cout<<"no";
        cout<<endl;
        flag=true;
    }
}