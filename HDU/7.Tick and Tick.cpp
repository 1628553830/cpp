#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    double a=0,t=0,miao,fen,shi;
    cin>>n;
    while(n<=120&&n>=0)
    {
        //模拟时钟
        while(shi<360)
        {
            t+=1;
            miao=t-(int)t/360*360;
            fen=t/60-(int)t/60/360*360;
            shi=t/720;
            if(abs(miao-fen)>=n&&abs(miao-fen+360)>=n&&abs(fen+360-miao)>=n)
               if(abs(miao-shi)>=n&abs(miao-shi+360)>=n&&abs(shi+360-miao)>=n)
                  if(abs(fen-shi)>=n&&abs(fen-shi+360)>=n&&abs(shi+360-fen)>=n)
                     a+=1;
        }
        printf("%.3lf\n",a/t*100);
        cin>>n;
        a=t=shi=0;
    }
    cin.get();
    cin.get();
}