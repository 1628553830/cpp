#include<iostream>
using namespace std;
int main()
{
  int num,sum=0,s;
 while(cin>>num)
{
for(int j=0;j<num;j++)
{cin>>s;sum+=s;}
cout<<sum<<endl;
sum=0;
}
}