#include<stdio.h>
#include<stdlib.h>
double zhe(double x)
{
    if(x<250)return 1;
    else if(x<500)return 0.98;
    else if(x<1000)return 0.95;
    else if(x<2000)return 0.92;
    else if(x<3000)return 0.9;
    else return 0.85;
}
int main()
{
    double s,p,w;
    scanf("%lf%lf%lf",&p,&w,&s);
    printf("%lf",p*w*s*zhe(s));
    system("pause");
}