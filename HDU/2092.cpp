#include<iostream>
using namespace std;
int main()
{
    char a;int b;
    cin>>a;
    while(1)
    {  
        cin>>b;
        for(int i=1;i<=b;i++)
        {
            for(int j=1;j<=b-i;j++)
            cout<<" ";
            if(i==1||i==b)
               for(int j=1;j<=2*i-1;j++)
                   cout<<a;
            else 
               for(int j=1;j<=2*i-1;j++)
                   if(j-1&&j-2*i+1)
                   cout<<" ";
                   else 
                   cout<<a;
            cout<<endl;
        }
        cin>>a;
        if(a!='@')
        cout<<endl;
        else
        break;
    }
}