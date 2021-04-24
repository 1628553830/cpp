#include<string>
#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
string a[100005];
int main()
{
     long long n,tmp=1;
     long long result=0;
     cin>>n;
     for(int i=0;i<n;i++)
     {
         cin>>a[i];
         sort(a[i].begin(),a[i].end());
     }
     sort(a,a+n);
     for(int i=0;i<n-1;i++)
     {
         if(a[i]==a[i+1])
         {
             tmp++;
         }
         else
         {
             result+=(tmp-1)*tmp/2; //这个可能会爆！！！
             tmp=1;
         }
     }
    result+=(tmp-1)*tmp/2;
    cout<<result<<endl;
    cin.get();
    cin.get();
}