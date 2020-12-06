#include<stdio.h>
#include<stdlib.h>
#include<math.h>
bool isprimer(int a)
{
    for(int i=2;i<=sqrt(a);i++)
    if(a%i==0)return false;
    return true;
};
int main()
{
    int n;
    for(int i=0;i<5;i++)
    {
    scanf("%d",&n);
    if(i)
    printf(" %d",isprimer(n));
    else
    printf("%d",isprimer(n));
    }
    system("pause");
}