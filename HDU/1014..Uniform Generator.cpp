#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int step,mod,tmp;
    bool used[100000],flag;
    while(cin>>step>>mod)
    {
        memset(used,0,sizeof(used));
        tmp=0;
        flag=false;
        printf("%10d%10d",step,mod);
        for(int i=0;i<mod;i++)
        {
            tmp=(tmp+step)%mod;
            if(used[tmp])
            {
                break;
            }
            else if(i==mod-1)
            {
                flag=true;
            }
            else
            {
                used[tmp]=true;
            }
        }
        printf("    ");
        if(flag)
        {
            printf("%10s\n\n","Good Choice");
        }
        else
        {
            printf("%10s\n\n","Bad Choice");
        }
    }
}