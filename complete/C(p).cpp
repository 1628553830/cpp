#include<bits/stdc++.h>
using namespace std;
int main()
{
    
    double pi=1,xiang=1;
    for(int i=1;i<=10000;i++)
    {
        xiang*=double(i/(1+2.0*i));
        pi+=xiang;
    }
    printf("%.14f",pi*2);
}