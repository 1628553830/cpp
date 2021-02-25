#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;
int calculateday(int);
int calculatesolarterm(int,int);
int main()
{
     
     for(int i=1237;i<2473;i++)
     {
         bool flag=false;
         for(int j=2000;j<2100;j++)
         {
             int temp=calculatesolarterm(j-1900,0);
             for(int k=1;k<24&&temp<calculateday(i+1);k++)
             {
                 if(temp>=calculateday(i)) 
                 {
                     if((k-1)%2)flag=true;
                 }
                 temp=calculatesolarterm(j-1900,k);
             }
         }
         if(!flag)
         {
             cout<<i<<endl;
             cout<<1.6+29.5306*i+0.4*sin(1-0.45058*i)+0.1<<endl;
         }
     }
     system("pause");
}
int calculateday(int x)
{
    double result=1.6+29.5306*x+0.4*sin(1-0.45058*x)+0.1;
    return result;
}
int calculatesolarterm(int x,int y)
{
    double result=365.242*x+6.2+15.22*y-1.9*sin(0.262*y);
    return result;
}
