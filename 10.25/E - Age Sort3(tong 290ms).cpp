#include<bits/stdc++.h>
using namespace std;
int num[2000000];
int main()
{
    int n,age[100]{};
    scanf("%d",&n);
    while(n)
    {
        for(int i=0;i<n;i++){scanf("%d",&num[i]);age[num[i]]++;}
        for(int i=1;i<100;i++)
          while(age[i]--)
            {
                if(n>1)printf("%d ",i);
                else printf("%d\n",i);
                n--;
            }
        scanf("%d",&n);
        memset(age,0,sizeof(age));
    }
}