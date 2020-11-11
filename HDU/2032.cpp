#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[31][31]{1},n;
    for(int i=1;i<31;i++)
    for(int j=1;j<=i;j++)
        a[i][j]=a[i-1][j-1]+a[i-1][j];
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
              if(j-1)cout<<" "<<a[i][j];
              else cout<<a[i][j];
            cout<<endl;
        }
        cout<<endl;
    }
}