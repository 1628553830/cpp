#include<bits/stdc++.h>
using namespace std;
int main()
{
    double num[100],sum=0;int n;
    cout.precision(2);
    while (cin>>n)
    {
        for(int i=0;i<n;i++)
        {cin>>num[i];sum+=num[i];}
        sort(num,num+n);
        sum=sum-num[0]-num[n-1];
        cout<<fixed<<sum/(n-2)<<endl;
        sum=0;
    }
    
}