#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
struct T
{
    double x,y;
}num[100000];
bool   cmp1(T a,T b)
{
    return a.x<b.x;
}
bool   cmp2(T a,T b)
{
    return a.y<b.y;
}
double distance(double x1,double y1,double x2,double y2)
{
       return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
int main()
{
    int n;
    double min;
    double temp;
    scanf("%d",&n);
    while(n)
    {
         for(int i=0;i<n;i++)
         scanf("%lf%lf",&num[i].x,&num[i].y);
         sort(num,num+n,cmp1);
         min=distance(num[0].x,num[0].y,num[1].x,num[1].y);
         for(int i=0;i<n-1;i++)
         {
             temp=distance(num[i].x,num[i].y,num[i+1].x,num[i+1].y);
             min=min>temp?temp:min;
         }
         sort(num,num+n,cmp2);
         for(int i=0;i<n-1;i++)
         {
             temp=distance(num[i].x,num[i].y,num[i+1].x,num[i+1].y);
             min=min>temp?temp:min;
         }
         printf("%.2lf\n",sqrt(min)/2);
         scanf("%d",&n);
    }
}