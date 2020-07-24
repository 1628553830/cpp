/*给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
你可以假设 nums1 和 nums2 不会同时为空。
示例 1:
nums1 = [1, 3]
nums2 = [2]
则中位数是 2.0
示例 2:
nums1 = [1, 2]
nums2 = [3, 4]
则中位数是 (2 + 3)/2 = 2.5
思路：
  1.合并两个数组，当到中间位置时停下
  2.优先队列
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
   int a,b,c,nums1[100],nums2[100],nums3[100];
   cin>>a>>b;
   for(int i=0;i<a;i++)cin>>nums1[i];
   for(int i=0;i<b;i++)cin>>nums2[i];
   c=(a+b)%2?(a+b+1)/2:(a+b+2)/2;
   for(int i=0,j=0,k=0;k<c;k++)
      if(i<a&&j<b)
      {
        if(nums1[i]<nums2[j])nums3[k]=nums1[i++];
        else nums3[k]=nums2[j++];
      }
      else if(i<a)nums3[k]=nums1[i++];
      else nums3[k]=nums2[j++];
   if((a+b)%2)cout<<(double)nums3[c-1];
   else cout<<(double)(nums3[c-1]+nums3[c-2])/2;
   system("pause");
   return 0;
}