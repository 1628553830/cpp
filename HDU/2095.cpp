#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int N,re,x;        
    cin>>N;
    while(N)
    {
        cin>>re;
        for(int i=1;i<N;i++)
        {
            scanf("%d",&x);
            re^=x;
        }
        cout<<re<<endl;        
        cin>>N;
    }
}