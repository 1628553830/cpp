/*给定一个整数数组 nums 和一个目标值 target,请你在该数组中找出和为目标值的那两个整数，并返回他们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
示例:
给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
思路：
   1.二分+排序
   2.暴力求解
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
    int nums[100],a,target;
    cin>>a>>target;
    for(int i=0;i<a;i++)cin>>nums[i];
    for(int i=0;i<a;i++)
    for(int j=i+1;j<a;j++)
    if(nums[i]+nums[j]==target)cout<<"["<<i<<","<<j<<"]";
    system("pause");
    return 0;    
}