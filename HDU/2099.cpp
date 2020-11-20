#include<iostream>
using namespace std;
string transfer(int a)
{
   if(!a)return "00";
   string b;
   while(a)
   {
      b=char(a%10+'0')+b;
      a/=10;
   }
   return b.length()<2?'0'+b:b;
}
int main()
{
   int n,m;
   bool flag=true;
   cin>>n>>m;
   while(n||m)
   {
      for(int i=0;i<100;i++)
      if((n*100+i)%m==0)
      {
         if(flag){cout<<transfer(i);flag=false;}
         else cout<<" "<<transfer(i);
      }
      cout<<endl;
      flag=true;
      cin>>n>>m;
   }
} 

