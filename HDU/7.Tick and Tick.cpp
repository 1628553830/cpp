#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,q=0;
    double miao=0,fen,shi,t1,t2,t3,t4,ans=0;
    cin>>n;
    while(n<=120&&n>=0)
    {
        //解多次方程
        while(720/11*(n+q*360)<259200)//用度数来解方程
        {
           t1=720/11*(n+q*360);q++;
           t2=720/11*(q*360-n);//t1,t2用来确定分针和时针开心的边界,t3,t4用来确定秒针分别与时针和分针的开心边界
           //用for循环寻找在t1-t2该区间的miao的范围
           t3=t4=0;
           

           for(int i=0;t3<259200;i++)
           {
               t3=(n+(i*360))*720/719;
               if(t1<t3&&t3<t2)break;
           }
           for(int i=0;t4<259200;i++)
           {
               t4=(360*(i+1)-n)*720/719;
           }
           
            
        }
        
    }
    cin.get();
    cin.get();
}