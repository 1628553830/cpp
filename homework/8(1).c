#include<stdio.h>
#include<stdlib.h>
int *p1,*p2;
void swap1()
{
    int *temp=p1;
    p1=p2;
    p2=temp;
}
void swap2()
{
    int a;
    a=*p1;
    *p1=*p2;
    *p2=a;
}
int main()
{
    int x=1,y=2;
    p1=&x;p2=&y;
    swap1();
    printf("*p1=%d *p2=%d x=%d y=%d\n",*p1,*p2,x,y);
    swap2();
    printf("*p1=%d *p2=%d x=%d y=%d\n",*p1,*p2,x,y);
    system("pause");
}