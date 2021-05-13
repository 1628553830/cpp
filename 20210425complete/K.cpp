#include<iostream>
using namespace std;
int main()
{
    int n,temp=0;    
    int V[100000],T[100000];    
    long long R[100000]{};
    cin>>n;
    for(int i=0;i<n;i++)
    {
       scanf("%d",&V[i]);
    }
    for(int i=0;i<n;i++)
    {
       scanf("%d",&T[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n&&V[i];j++)
        {
             if(V[i]>T[j])
             {
                 R[j]+=T[j];
                 V[i]-=T[j];
             }
             else
             {
                 R[j]+=V[i];
                 V[i]=0;
             }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(i)printf(" ");
        printf("%lld",R[i]);
    }
    cin.get();
    cin.get();
}