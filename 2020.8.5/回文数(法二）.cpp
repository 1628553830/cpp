/*
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
示例 1:
输入: 121
输出: true
示例 2:
输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
示例 3:
输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。
*/
#include<iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;
int main()
{
    int b;
    cin>>b;
    if(b<0){cout<<false;system("pause");return 0;}
    string a;
    while(b!=0)
    {
        a=a+char(b%10+'0');
        b/=10;
    }
   for(int i=0;i<a.length()/2;i++)
      if(a[i]!=a[a.length()-1-i])
      {cout<<false;system("pause");return 0;}
   cout<<true;
   system("pause");
   return 0;
}