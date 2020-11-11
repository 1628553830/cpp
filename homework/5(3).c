#include<stdio.h>
#include<stdlib.h>
int main()
{
    int yh[11][11]={1};
    for(int i=1;i<=10;i++)
    {
        for(int j=1;j<=i;j++)
        {
        yh[i][j]=yh[i-1][j-1]+yh[i-1][j];
        printf("%d",yh[i][j]);
        }
        printf("\n");
    }
    system("pause");
}