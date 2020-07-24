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
#include<queue>
using namespace std;
int main()
{
   priority_queue<int, vector<int>, greater<int> > nums3;
   int num,x;
   cin>>num;
   for(int i=0;i<num;i++)
   {
       cin>>x;nums3.push(x);
   }
   x=1;
   if(num%2)
    {
        while(x<(num+1)/2){nums3.pop();x++;}
        cout<<nums3.top();
    }
   else
   {
       while(x<num/2){nums3.pop();x++;}
       x=nums3.top();nums3.pop();
       cout<<(double)(nums3.top()+x)/2;
   }
   system("pause");
   return 0;

}