/*
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
示例 1:
输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:
输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
思路：
  滚动字符串。
*/
#include<iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;
int main()
{
    string s;
    bool ascii[127]{false};
    int left=0,right=0,max=0;
    cin>>s;
    while (right<s.length())
    {
      if(!ascii[s[right]])
        ascii[s[right++]]=true;
      else 
        ascii[s[left++]]=false;
      max=right-left<max?max:right-left;
    }
    cout<<max;
    system("pause");
    return 0;
}