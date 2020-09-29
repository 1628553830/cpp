/*母牛的故事 
有一头母牛，它每年年初生一头小母牛。每头小母牛从第四个年头开始，每年年初也生一头小母牛。请编程实现在第n年的时候，共有多少头母牛？
Input
输入数据由多个测试实例组成，每个测试实例占一行，包括一个整数n(0<n<55)，n的含义如题目中描述。
n=0表示输入数据的结束，不做处理。
Output
对于每个测试实例，输出在第n年的时候母牛的数量。
每个输出占一行。
Sample Input
2
4
5
0
Sample Output
2
4
6
*/
#include<iostream>
using namespace std;
int main()
{
    /*思路一：
    int n;cin>>n;
    while(n)
    {
     long mn[101]{0,1,2,3,4};
    for(int i=5;i<=n;i++)
    {for(int j=0;j<i-1;j++)mn[i]=j>2?mn[i]+mn[j-1]:mn[i]+1;
    mn[i]++;
    }
    cout<<mn[n]<<endl;
    cin>>n;
    }
    cin.get();
    cin.get();
    */
   //思路二：
   int n;cin>>n;
   while(n)
   {
     long mn[56]{0,1,2,3,4};
     for(int i=5;i<=n;i++)
     mn[i]=mn[i-1]+mn[i-3];
     cout<<mn[n]<<endl;
     cin>>n;
   }
   cin.get();
   cin.get();
     
}