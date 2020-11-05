#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num[101],n,m;
    bool flag=true;
    cin>>n>>m;
    while(n||m)
    {
        for(int i=0;i<n;i++)
        {
            cin>>num[i];
            if(num[i]>=m&&flag)
            {
                flag=false;
                if(i)cout<<" "<<m;
                else cout<<m;
            }
            if(i)cout<<" "<<num[i];
            else cout<<num[i];
        }
        cout<<endl;
        flag=true;
        cin>>n>>m;
    }
}