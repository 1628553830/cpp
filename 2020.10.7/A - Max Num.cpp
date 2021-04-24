#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main()
{
    int t,n;float a[100],max;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    { 
        max=0;
       scanf("%d",&n);
       for(int j=0;j<n;j++)
       {scanf("%f",&a[j]);max=max<a[j]?a[j]:max;}
       printf("%.2f\n",max);
      
    }
    system("pause");
}