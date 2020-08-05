/*
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
示例 1:
输入: 123
输出: 321
示例 2:
输入: -123
输出: -321
示例 3:
输入: 120
输出: 21
注意:
假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。
*/
#include<iostream>
#include<stdlib.h>
#include<limits.h>
using namespace std;
int main()
{
    long long a,b=0;
    cin>>a;
    while(a!=0)
    {
        b=b*10+a%10;
        a/=10;      
    }
    b=b>INT_MAX||b<INT_MIN?0:b;
    cout<<b;
    system("pause");
    return 0;
}