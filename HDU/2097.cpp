#include<iostream>
using namespace std;
int check(int,int);
int main()
{
   int n;cin>>n;
   while(n)
   {
       if(check(10,n)==check(12,n)&&check(10,n)==check(16,n))
       cout<<n<<" is a Sky Number.\n";
       else 
       cout<<n<<" is not a Sky Number.\n";
       cin>>n;
   }
} 
int check(int jz,int shu)
{
   int ans=0;
   while(shu)
   {
       ans+=shu%jz;
       shu/=jz;
   }
   return ans;
}
