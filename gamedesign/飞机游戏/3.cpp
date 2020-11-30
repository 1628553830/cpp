//getch()控制飞机+复杂的飞机图样
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
using namespace std;
void show(int,int);//定位飞机 
int main()
{
    int x,y;
    char c;
    cin>>x>>y;
    while(1)
    {
       show(x,y);

       if(kbhit())
       {
        c=getch();
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
       Sleep(20);
    }
}
void show(int x,int y)
{
    system("cls");
    for(int i=0;i<y;i++)
    cout<<endl;
    for(int j=0;j<x;j++)
    cout<<" ";
    cout<<"    ★    "<<endl;
    for(int j=0;j<x;j++)
    cout<<" ";
    cout<<"★★★★★"<<endl;
    for(int j=0;j<x;j++)
    cout<<" ";
    cout<<"  ★  ★  "<<endl;
}