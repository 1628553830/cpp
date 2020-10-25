#include<iostream>
using namespace std;
long long t[50];
void begin()
{
   t[1]=1;t[2]=2;
   for(int i=3;i<=50;i++)
   {
      t[i]=t[1]*t[i-1]+1*t[i-2];
   }

}
int main()
{
    int n,a,b;
    begin();
    cin>>n;
    for(int i=0;i<n;i++)
    {
       cin>>a>>b;
       cout<<t[b-a]<<endl;
    }
    cin.get();
    cin.get();
}