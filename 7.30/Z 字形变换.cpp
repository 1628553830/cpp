/*
将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
L   C   I   R
E T O E S I I G
E   D   H   N
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
请你实现这个将字符串进行指定行数变换的函数：
string convert(string s, int numRows);
示例 1:
输入: s = "LEETCODEISHIRING", numRows = 3
输出: "LCIRETOESIIGEDHN"
示例 2:
输入: s = "LEETCODEISHIRING", numRows = 4
输出: "LDREOEIIECIHNTSG"
解释:
L     D     R
E   O E   I I
E C   I H   N
T     S     G
思路：数学表达式
*/
#include<iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;
int main()
{
    string s,a;
    int num;bool flag;
    cin>>s>>num;
    if(num==1)
    {
        cout<<s;
        system("pause");
        return 0;
    }
    for(int i=0;i<num;i++)
    {   flag=true;
        for(int j=i;j<s.length();)
    {
       a+=s[j];
       j=i==0||i==num-1?j+(num-1)*2:flag?(num-i-1)*2+j:i*2+j;
       flag=!flag;
    }
    }
    cout<<a;
    system("pause");
    return 0;

    
}