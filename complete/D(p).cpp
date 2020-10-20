#include<iostream>
using namespace std;
int main()
{
    int n;cin>>n;
    for(int i=1;i<=2*n-1;i++)
    {
      if(i<=n)
      {
          for(int j=1;j<=n-i;j++)
          cout<<" ";
          for(int j=1;j<=i*2-1;j++)
          cout<<"*";
          cout<<endl;
      }
      else 
      {
          for(int j=1;j<=i-n;j++)
          cout<<" ";
          for(int j=1;j<=(2*n-i)*2-1;j++)
          cout<<"*";
          cout<<endl;
      }
    }
    cin.get();
    cin.get();
}