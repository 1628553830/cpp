#include<bits/stdc++.h>
using namespace std;
int main()
{
   float a,b,c,d;
   cin>>a>>b>>c>>d;
   if(max(3*a/10,a-a/250*c)>max(3*b/10,b-b/250*d))
   cout<<"Misha";
   else if(max(3*a/10,a-a/250*c)<max(3*b/10,b-b/250*d))
   cout<<"Vasya";
   else
   cout<<"Tie";
   cin.get();
   cin.get();
}