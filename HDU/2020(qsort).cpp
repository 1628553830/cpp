#include<bits/stdc++.h>
using namespace std;
int cmp(const void* a,const void* b)
{
    int *m=(int *)a;
    int *n=(int *)b;
    return abs(*n)-abs(*m);
}
int main()
{
    int n,num[100];
    cin>>n;
    while(n)
    {
        for(int i=0;i<n;i++)cin>>num[i];
        qsort(num,n,sizeof(int),cmp);
        for(int i=0;i<n;i++)
        if(i)cout<<" "<<num[i];
        else cout<<num[i];
        cout<<endl;
        cin>>n;
    }
}