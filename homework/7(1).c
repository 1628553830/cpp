#include<stdio.h>
#include<stdlib.h>
#include<math.h>
bool isprimer(int a)
{
    for(int i=2;i<=sqrt(a);i++)
    if(a%i==0)return false;
    return true;
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",isprimer(n));
    system("pause");
}