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
    string s,max="";
    int begin1,end1,begin2,end2,start=0,end=0;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        begin1=i;end1=i;
        while(begin1>=0&&end1<s.size()&&s[begin1]==s[end1]){begin1--;end1++;}
        begin1+=1;end1-=1;
        begin2=i;end2=i+1;
        while(begin2>=0&&end2<s.size()&&s[begin2]==s[end2]){begin2--;end2++;}
        begin2+=1;end2-=1;
        if(end1-begin1>end-start){start=begin1;end=end1;}
        if(end2-begin2>end-start){start=begin2;end=end2;}
    }
    max=s.substr(start,end-start+1);
    cout<<max;
    system("pause");
    return 0;
}