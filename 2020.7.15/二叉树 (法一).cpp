/*给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
示例:
输入: 3
输出: 5
解释:
给定 n = 3, 一共有 5 种不同结构的二叉搜索树:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
 思路：
 利用二叉树推导
 如 f(1)=1     
    1
    f(2)=2     
    1        2
     \      /
      2    1
    f(3)=f(2)+f(1)*f(1)+f(2)=5
    1           2          3
     \        /  \       /
      f(2)  f(1) f(1)  f(2)
    以此类推......
  实现：
  1.递归函数f（分配内存大,效率低,类似于dfs）
  2.数组递推f（分配内存小,效率高,类似于bfs）
  3.递推关系（卡塔兰数）
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
int f(int);
int main()
{
   int a;
   cin>>a;
   cout<<f(a);
   system("pause");   
   return 0;
}
int f(int a)
{
    int b=0;
    if(a==0||a==1)return 1;
    else if(a==2)return 2;
    for(int i=1;i<=a;i++)
      b+=f(i-1)*f(a-i);
    return b;
}