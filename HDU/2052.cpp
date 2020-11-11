#include<iostream>
using namespace std;
void draw(int a,int b)
{
  for(int i=1;i<=b+2;i++)
  {
      if(i==1||i==b+2)
      {
          cout<<"+";
          for(int j=1;j<=a;j++)cout<<"-";
          cout<<"+";
      }
      else 
      {
          cout<<"|";
          for(int j=1;j<=a;j++)cout<<" ";
          cout<<"|";
      }
      cout<<endl;
  }
}
int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        draw(a,b);
        cout<<endl;
    }
    
}