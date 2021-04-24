/*给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
你可以假设数组中无重复元素。
示例 1:
输入: [1,3,5,6], 5
输出: 2
示例 2:
输入: [1,3,5,6], 2
输出: 1
示例 3:
输入: [1,3,5,6], 7
输出: 4
示例 4:
输入: [1,3,5,6], 0
输出: 0
思路：
1.顺序查找
2.对分查找
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
    int nums[100],num,k,i;
    bool flag=false;
    cin>>num>>k;
    for(i=0;i<num;i++)
        cin>>nums[i];
    for(i=0;i<num&&k>nums[i];i++)
       if(nums[i]==k){cout<<i;flag=true;break;}
    if(!flag)cout<<i;
    system("pause");
    return 0;
}


