#include<iostream>
#include<stdlib.h>
using namespace std;
char* DHT11_string(char T)
{
    static char str [10];            
    char xs;                     
    float XS;                     
    char i,j;

    XS=T;
    j=0;
    while(XS>=1)
    {
       XS/=10;
       j++;
    }
    for(i=0;i<j;i++)
    {
       XS*=10;
       xs=XS;
       str [i]=xs+'0';
       XS-=xs;
    }
    str[i]='\0';
    return str;
}
int main()
{
    cout<<DHT11_string(10);
    system("pause");
}