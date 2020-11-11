#include<stdio.h>
#include<stdlib.h>
int main()
{
    int t,max,min;
    scanf("%d",&t);
    max=min=t;
    for(int i=0;i<9;i++)
        {
            scanf("%d",&t);
            max=max<t?t:max;
            min=min>t?t:min;
        }
    printf("最大值:%d 最小值:%d",max,min);
    system("pause");
}