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
    int nums[100],xu[100],a,k,left,right,target,mid;
    cin>>a>>target;
    for(int i=0;i<a;i++)
    {cin>>nums[i];xu[i]=i;}
    for(int i=1;i<a;i++)  //排序部分
    {
        k=i;
        for(int j=i+1;j<a;j++)
          if(nums[xu[k]]>nums[xu[j]])k=j;
        if(i!=k)
        {xu[i]=xu[i]+xu[k];
        xu[k]=xu[i]-xu[k];
        xu[i]=xu[i]-xu[k];}
    }
    for(int i=0;i<a;i++)//求解部分
    {
        k=target-nums[xu[i]];
        left=i+1;right=a-1;
        while (left<=right)
        {
            mid=int((left+right)/2);
            if(k==nums[xu[mid]])break;
            else if(k<=nums[xu[mid]])right=mid-1;
            else left=mid+1;
        }
        if(target==nums[xu[i]]+nums[xu[mid]])cout<<"["<<xu[i]<<","<<xu[mid]<<"]";
    }
    system("pause");
    return 0;
}