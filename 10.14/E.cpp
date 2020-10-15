#include<bits/stdc++.h>
using namespace std;
int main()
{
    double e=1;int jiecheng=1;
    cout<<"n e"<<endl  
        <<"- -----------"<<endl
        <<"0 1"<<endl
        <<"1 2"<<endl
        <<"2 2.5"<<endl;
    for(int i=1;i<=9;i++)
    {
        jiecheng*=i;
        e+=1.0/jiecheng;
        if(i>2)printf("%d %.9f\n",i,e);
    }
    cin.get();
    cin.get();
}