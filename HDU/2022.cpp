#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n,max=0,row=1,col=1,x;
    while(cin>>m>>n)
   { 
       for(int i=1;i<=m;i++)
       for(int j=1;j<=n;j++)
       {
         cin>>x;
         if(abs(max)<abs(x)){max=x;row=i;col=j;}
       }
       cout<<row<<" "<<col<<" "<<max<<endl;
       max=0;row=col=1;
   }
}
