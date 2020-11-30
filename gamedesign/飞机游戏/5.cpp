//getch()控制飞机+复杂的飞机图样+激光发射
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
using namespace std;
void show(int,int,bool);//定位飞机 
int T;
int main()
{
    int x,y;
    bool isfire=false;
    char c;
    cin>>x>>y;
    T=y;
    show(x,y,isfire); 
    while(1)
    {
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
       case ' ':isfire=!isfire;
               break;
       }      
        if(c==' '&&isfire){T=y;while(T--)show(x,y,isfire);}
        else show(x,y,isfire);
       }       
    }
}
void show(int x,int y,bool isfire)
{   
    system("cls");
    for(int i=0;i<y;i++)
    {   
        if(!isfire)cout<<endl;
        else 
        {
            if(i>=T)
            {for(int j=0;j<x+4;j++)
            cout<<" ";
            cout<<"||";}
            cout<<endl;
        }
    }
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