#include<bits/stdc++.h>
using namespace std;
int main()
{
    double sum=0;bool flag=true;
    int m,x;cin>>m;
    while(cin>>x)
    {
        for(int i=1;i<=x;i++)
        {
            sum=flag?sum+1.0/i:sum-1.0/i;
            flag=!flag;
        }
        printf("%.2f\n",sum);
        sum=0;flag=true;
    }

}