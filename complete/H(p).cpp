#include<iostream>
using namespace std;
int main()
{
   string a;bool flag=true;
   cin>>a;
   for(int i=0;i<a.length();i++)
       if(a[i]=='4'){cout<<"Danger!";flag=false;break;}
    if(flag)cout<<"Safe.";
   cin.get();
   cin.get();
}