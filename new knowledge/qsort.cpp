#include<stdlib.h>//qsort()函数的头文件
#include<bits/stdc++.h>
using namespace std;
int cmp1(const void *a,const void *b)
{
    int *m=(int*)a;//a在前是升序，否则是降序
    int *n=(int*)b;
    return *m-*n;
}
int cmp2(const void *a,const void *b)
{
    double *m=(double* )a;
    double *n=(double* )b;
    if(*m>*n)return 1;
    else if(*m==*n)return 0;
    return -1;
}

int main()
{
    int a[]{1,2,3,4};
    double b[]{1.0,2.1,1,2};
    qsort(a,4,sizeof(int),cmp1);//di
    qsort(b,4,sizeof(double),cmp2);
    for(int i=0;i<4;i++)printf("%-4d",a[i]);
    cout<<endl;
    for(int i=0;i<4;i++)printf("%-4.1lf",b[i]);
    cin.get();
}