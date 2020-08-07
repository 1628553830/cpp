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
using namespace std;
int main()
{
    int a,b=0,c;
    bool flag=true;
    cin>>a;
    c=a;
    if(a<0){flag=false;cout<<flag;system("pause");return 0;}
    else 
       while(a!=0){b=b*10+a%10;a/=10;}
    flag=c==b;
    cout<<flag;
    system("pause");
    return 0;
}