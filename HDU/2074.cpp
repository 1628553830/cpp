#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;bool flag,first=true;
    char a,b;
    while(cin>>N>>a>>b)
   {
    if(!first)cout<<endl;//排除最后一次输出空行的可能
    else first=false;
    if(N==1)cout<<a<<endl;
    else
    {
    if(((N-1)/2)%2)swap(a,b);
    flag=true;
    for(int i=1;i<=N;i++)
    {
        if(i-1&&i-N)
        {
           int T=(N-1)/2-abs(i-1-(N-1)/2);
           for(int j=1;j<=N;j++)
           {
               if(j<=T||j>N-T)
               {
                   cout<<(flag?a:b);
                   flag=!flag;
               }
               else 
               {
                   cout<<(flag?a:b);
                   if(j==N-T)flag=!flag;
               }
           }    
        }
        else 
        {
            for(int j=1;j<=N;j++)
            if(j-1&&j-N)cout<<a;
            else cout<<" ";
        }
        flag=true;
        cout<<endl;
    }
    }
   }
    cin.get();
    cin.get();

}