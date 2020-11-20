#include<stdio.h>
#include<stdlib.h>
int main()
{
     int N,M,col=0,row=0;
     scanf("%d%d",&N,&M);
     int num[N][M];
     for(int i=0;i<N;i++)
     for(int j=0;j<M;j++) 
     {
         scanf("%d",&num[i][j]);
         if(num[i][j]>num[col][row])
         {
             col=i;row=j;
         }
     }
     printf("%d %d %d",num[col][row],col+1,row+1);
     system("pause");
}