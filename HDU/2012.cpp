#include<bits/stdc++.h>
using namespace std;
bool isprimer(int x)
{
    x=abs(x);
    for(int i=2;i<=sqrt(x);i++)
       if(x%i==0)return 0;
    return 1;
}
int main()
{
    int x,y;bool flag=true;
    cin>>x>>y;
    while(x||y)
   {
       for(int i=x;i<=y;i++)
        if(isprimer(i*i+i+41)==false){flag=false;cout<<"Sorry"<<endl;break;}
       if(flag)cout<<"OK\n";
       flag=true;
       cin>>x>>y;
    } 
}