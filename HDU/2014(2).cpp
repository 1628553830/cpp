#include<bits/stdc++.h>
using namespace std;
int cmp(const void *a,const void *b)
{
    int *m=(int*)a;
    int *n=(int*)b;
    return *m-*n;
}
int main()
{
    int num[100]{};double sum=0;int n;
    cout.precision(2);
    while (cin>>n)
    {
        for(int i=0;i<n;i++)
        {cin>>num[i];sum+=num[i];}
        qsort(num,n,sizeof(int),cmp);
        sum=sum-num[0]-num[n-1];
        cout<<fixed<<sum/(n-2)<<endl;
        sum=0;
    }
    
}