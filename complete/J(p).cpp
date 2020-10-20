#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int L,R;bool flag=true,used[10]{};
    cin>>L>>R;
    for(;L<=R;L++)
    {
       int x=L;
       while(x>0)
       {
           if(!used[x%10])
               used[x%10]=1;
           else    
               {flag=false;break;}
           x/=10;
       }
       if(flag){cout<<L<<endl;break;}
       flag=true;
       memset(used,0,sizeof(used));
    }
    if(L>R)cout<<-1;
    cin.get();
    cin.get();
}