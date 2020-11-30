//getch()控制飞机+复杂的飞机图样+激光发射
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
using namespace std;
void show(int,int,bool);//定位飞机 
int T,x1=5;
bool iskill=false;
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
        if(c==' '&&isfire){T=y;while(T--)show(x,y,isfire);T=0;}
        else show(x,y,isfire);
       }       
    }
}
void show(int x,int y,bool isfire)
{   
    system("cls");
    for(int i=0;i<y;i++)
    {   
        if(!iskill&&!i)
        {
            for(int j=0;j<=max(x+2,x1);j++)
            {
               if(j==x+2&&isfire)
                 {
                     if(j==x1&&T==0)
                      iskill=1;
                     if(!T)cout<<"|";
                     else if(j==x1)cout<<"+";
                     else cout<<" ";
                 }
               else if(j==x1)
                 cout<<"+";
               else 
                 cout<<" ";
            }
        }
        else if(isfire)
        {
            if(i>=T)
            {
            for(int j=0;j<x+2;j++)
            cout<<" ";
            cout<<"|";
            }
        }
        cout<<endl;
    }
    for(int j=0;j<x;j++)
    cout<<" ";    
    cout<<"  *  "<<endl;
    for(int j=0;j<x;j++)
    cout<<" ";
    cout<<"*****"<<endl;
    for(int j=0;j<x;j++)
    cout<<" ";
    cout<<" * *"<<endl;
 }