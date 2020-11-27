#include<iostream>
#include<stdlib.h>
using namespace std;
void show(int,int);
int main()
{
    int x,y;
    char c;
    cin>>x>>y;
    while(1)
    {
       show(x,y);
       c=getchar();
       switch (c)
       {
       case 'w': 
       case 'W':if(y)y--;
               break;
       case 's':
       case 'S':y++;
               break;
       case 'a':
       case 'A':if(x)x--;
               break;
       case 'd':
       case 'D':x++;
               break;
       }
    }
}
void show(int x,int y)
{
    system("cls");
    for(int i=0;i<y;i++)
    cout<<endl;
    for(int j=0;j<x;j++)
    cout<<" ";
    cout<<"*";
    cout<<endl;
}