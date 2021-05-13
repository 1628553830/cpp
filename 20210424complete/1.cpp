#include<iostream>
#include<cmath>
using namespace std;    
int a[4][4];
int direction[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int  change(int);
int main()
{
    int min=20;
    int temp;
    string b;
    for(int i=0;i<4;i++)
    {
        cin>>b;
        for(int j=0;j<4;j++)
        {
            if(b[j]=='w')
            a[i][j]=0;
            else
            a[i][j]=1;
        }
    }
    for(int i=0;i<pow(2,16);i++)
    {
         temp=change(i);
         if(temp!=-1)
         min=temp<min?temp:min;
    }
    if(min!=20)
    cout<<min<<endl;
    else
    cout<<"Impossible"<<endl;
    cin.get();
    cin.get();
}
int   change(int num)
{ 
      int temp[4][4];
      int flag;
      int count=0;
      for(int i=0;i<4;i++)
      for(int j=0;j<4;j++)
      temp[i][j]=a[i][j];
      for(int i=0;i<16;i++)
      {
           if(num%2)
           {
               temp[i/4][i%4]=!temp[i/4][i%4];
               for(int j=0;j<4;j++)
               {
                   if((i/4+direction[j][0])<4&&(i/4+direction[j][0])>=0&&(i%4+direction[j][1])<4&&(i%4+direction[j][1])>=0)
                      temp[i/4+direction[j][0]][i%4+direction[j][1]]=!temp[i/4+direction[j][0]][i%4+direction[j][1]];
               }
               count++;
           }
           num/=2;
      }
      flag=temp[0][0];
      for(int i=0;i<4;i++)
      for(int j=0;j<4;j++)
      if(temp[i][j]!=flag)return -1;
      return count;
}