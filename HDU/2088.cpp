#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,num[50],sum=0,average;
    cin>>n;
    while(n)
    {
        for(int i=0;i<n;i++)
        {cin>>num[i];sum+=num[i];}
        average=sum/n;
        sum=0;
        sort(num,num+n);
        for(int i=0;num[i]<average;i++)
        sum+=average-num[i];
        cin>>n;
        if(n)cout<<sum<<endl<<endl;
        else cout<<sum<<endl;        
        sum=0;
    }
}