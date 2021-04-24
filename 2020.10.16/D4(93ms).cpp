#include<stdio.h>
int main()
{
    int n,a,b,sum1=0,sum2=0;//n用来存储几组数据，sum1 sum2用来存储真约数，a，b用来存输入数据。这里sum1，sum2一定要赋初值0，不然不能进行累加
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&a,&b);
        //输入完成后计算约数
        for(int i=1;i<a;i++)
          if(a%i==0)sum1+=i;//这里可以用+=方便，不管是for循环还是if语句不加{}只能管到下面一句话
        for(int i=1;i<b;i++)
          if(b%i==0)sum2+=i;
        //判断亲和数
        if(sum1==b&&sum2==a)
          printf("YES\n");
        else 
          printf("NO\n");
        //这里YES和NO要求大写，还有要换行，在if里面的执行语句写在哪个位置都行，如：
        //if(sum1==b&&sum2==a)printf("YES\n");或者：
        /*
        if(sum1==b&&sum2==a)
        printf("YES\n");
        */
        //主要是别写的太乱
        sum1=sum2=0;//这里要记得用过的东西要重置，也可以分别赋值：sum1=0;sum2=0;都行，灵活着来；
    }
}