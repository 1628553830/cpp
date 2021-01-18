#include<stdlib.h>
#include<stdio.h>
#include<stdlib.h>
#define NUM 4
struct datas
{
   char name[1000],num[1000];
   int salary;
}a[NUM];

int main()
{
    struct datas b[NUM];
    //写入数据
    for(int i=0;i<NUM;i++)
    {
        printf("请输入第%d个职员的name,num,salary(空格隔开):",i+1);
        scanf("%s%s%d",a[i].name,a[i].num,&a[i].salary);
    }
    //写入文件
    freopen("hw1.txt","w",stdout);
    for(int i=0;i<NUM;i++)
    {
        if(i)
        printf(" %s %s %d",a[i].name,a[i].num,a[i].salary);
        else 
        printf("%s %s %d",a[i].name,a[i].num,a[i].salary);
    }
    //读取数据
    fclose(stdout);
    freopen("hw1.txt","r",stdin);
    for(int i=0;i<NUM;i++)
       scanf("%s%s%d",b[i].name,b[i].num,&b[i].salary);
    //输出数据
    freopen("CON","w",stdout);
    freopen("CON","r",stdin);
    for(int i=0;i<NUM;i++)
       printf("第%d个的name,num,salary:%s %s %d\n",i+1,b[i].name,b[i].num,b[i].salary);
    system("pause");
}