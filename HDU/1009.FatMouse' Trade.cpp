#include<iostream>
#include<algorithm>
using namespace std;
struct T{double J,F;}JF[1000];
bool cmp(T,T);
int main()
{
    int M,N,i;
    double result;
    cin>>M>>N;
    while(M!=-1||N!=-1)
    {
        result=0;
        for(i=0;i<N;i++)
            cin>>JF[i].J>>JF[i].F;
        sort(JF,JF+N,cmp);  
        for(i=0;M>=JF[i].F&&i<N;i++)
            {
                result+=JF[i].J;
                M-=JF[i].F;
            }
        if(i<N)
        result+=(JF[i].J/JF[i].F)*M;
        printf("%.3lf\n",result);
        cin>>M>>N;
    }
}
bool cmp(T a,T b)
{
     return (a.J)/(a.F)>(b.J)/(b.F);
}