#include<iostream>
using namespace std;
bool check(int a)
{
   bool flag=false;
   while(a)
   {
       if(a%10==4)return false;
       else if(a%10==2)flag=true;
       else if(flag)
       if(a%10==6)return false;
       else flag=false;
       a/=10;
   }
   return true;
}
int main()
{
    int n,m,total=0;cin>>n>>m;
    while(n||m)
    {
        for(int i=n;i<=m;i++)
        if(check(i))total++;
        cout<<total<<endl;
        total=0;
        cin>>n>>m;
    }

}