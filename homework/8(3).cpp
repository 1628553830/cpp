#include<stdlib.h>
#include<stdio.h>
int cmp(const void *a,const void *b)
{
    int *m=(int*)a;
    int *n=(int*)b;
    return *m-*n;
}
void sort(int*p,int n)
{
   qsort(p,n,sizeof(int),cmp);
}
int main()
{
    int num[]={4,9,2,7,6,1};
    sort(num,sizeof(num)/sizeof(int));
    for(int i=0;i<sizeof(num)/sizeof(int);i++)
    if(i)printf(" %d",num[i]);
    else printf("%d",num[i]);
    system("pause");
}