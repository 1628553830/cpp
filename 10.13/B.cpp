#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int a[3]{},s=0,day[12]={31,28,31,30,31,30,31,31,30,31,30,31},sum=0;
    string date;
    while(cin>>date)
    {
        for(int i=0;i<date.length();i++)
        {
            if(date[i]=='/')s++;
            else a[s]=a[s]*10+date[i]-'0';
        }
        if(a[0]%4==0&&a[0]%100||a[0]%400==0)day[1]=29;
        for(int i=0;i<a[1]-1;i++)sum+=day[i];
        sum+=a[2];
        cout<<sum<<endl;
        sum=0;s=0;
        day[1]=28;
        memset(a,0,sizeof(a));
    }
}