#include<stdlib.h>
#include<stdio.h>
int main()
{
    int num[6][6],sum=0;
    for(int i=1;i<=5;i++)
    for(int j=1;j<=5;j++)
    {
        scanf("%d",&num[i][j]);
        if(i==j)sum+=num[i][i];
        else if(i+j==6)sum+=num[i][j];
    }
    printf("%d",sum);
    system("pause");
    
}