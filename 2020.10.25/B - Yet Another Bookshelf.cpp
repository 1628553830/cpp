#include<iostream>
using namespace std;
int main()
{
    bool book[50],flag=false;
    int t,n,ans=0,a=0;
    cin>>t;
    while(t--)
    {
       cin>>n;
       for(int i=0;i<n;i++)
       {
         cin>>book[i];
         if(book[i]){flag=true;ans+=a;a=0;}
         else if(!book[i]&&flag)
            a++;
       }
       cout<<ans<<endl;
       ans=a=0;flag=false;
    }
}