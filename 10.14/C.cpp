//3个步骤：1.解出第一列；2.解出差；3.解出矩阵
#include<iostream>
using namespace std;
int main()
{
    bool jz[200][200],flag=true;int M,N,gl[2][200],fs[2][200],cha[201],col=0,a,t=0;
    cin>>M>>N;
    for(int i=0;i<M;i++){cin>>gl[0][i];col+=gl[0][i];}
    for(int i=0;i<M;i++){cin>>gl[1][i];col+=gl[1][i];}
    for(int i=0;i<N;i++)cin>>fs[0][i];
    for(int i=0;i<N;i++)cin>>fs[1][i];
    //1
    a=col;
    for(int i=0;i<M;i++)
    {
        int ans=gl[0][i]; 
        while(ans--)jz[--a][0]=1;
        ans=gl[1][i];
        while(ans--)jz[--a][0]=0;
    }
    //2
    for(int i=0;i<N;i++)
        while(fs[1][i]--)cha[++t]=fs[0][i];
    //3    
    for(int i=1;i<=t;i++)
    {
        for(int j=0;j<col;j++)
        jz[j][i]=cha[i]>=0?jz[(j+cha[i])%col][i-1]:jz[(j+cha[i]+col)%col][i-1];
    }
    for(int i=0;i<col;i++)
      if(jz[i][0]!=jz[i][t]){flag=false;cout<<"Can not make beautilful cloth !";break;}
    if(flag)
    for(int i=0;i<col;i++)
    {for(int j=0;j<t;j++)
     cout<<jz[i][j];
    cout<<endl;
    }

    cin.get();
    cin.get();
    


}