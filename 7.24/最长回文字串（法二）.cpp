/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
示例 1：
输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：
输入: "cbbd"
输出: "bb"
思路：
1.中心扩散
2.动态规划
*/
#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;
int main()
{
    string s;int begin=0,end=0;bool p[1000][1000]{false};
    cin>>s;
    for(int i=0;i<s.length();i++)
    for(int j=0;j<s.length()-i;j++)
    {
       if(j+i-1<j+1&&s[j]==s[j+i])p[j][j+i]=true;
       else if(j+i-1>=j+1&&p[j+1][j+i-1]&&s[j]==s[j+i])p[j][j+i]=true;
       else p[j][j+i]=false;
       if(end-begin+1<i+1&&p[j][j+i]){begin=j;end=j+i;}
    }
   cout<<s.substr(begin,end-begin+1);
    system("pause");
    return 0;
}