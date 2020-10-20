#include<iostream>
#include<climits>
#include<string.h>
using namespace std;
int main()
{
    bool flag=false;
    string s,maxs;
    int n,ans=0,max=INT_MIN;
    cin>>n;
    while(n)
    {
        pair<string,int>a[1000]{};//这里用memset来重置内存可能有点问题，会显示下标越界(在oj上)
        for(int i=0;i<n;i++)
        {
           cin>>s;
           for(int i=0;i<ans;i++)
              if(a[i].first==s)
              {
                  a[i].second++;
                  if(max<a[i].second){max=a[i].second;maxs=a[i].first;}
                  flag=true;
                  break;
              }
           if(!flag)
              {
                  a[ans]=make_pair(s,0);
                  if(max<a[ans].second){max=a[ans].second;maxs=a[ans].first;}
                  ans++;
              }
            flag=false;
        }
        cout<<maxs<<endl;
        ans=0;max=INT_MIN;
        cin>>n;
    }
    cin.get();
    cin.get();
}
  