#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[1000],b[1000];
    int bb;
    while(cin.getline(a,1000))
    {
        bb=0;
       for(int i=0;i<strlen(a);i++)
       {
           if(a[i]=='y'&&a[i+1]=='o'&&a[i+2]=='u'){i+=2;b[bb++]='w';b[bb++]='e';}
           else {b[bb++]=a[i];}
       }
       b[bb]='\0';
       cout<<b<<endl;
    }

}