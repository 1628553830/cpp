#include<iostream>
using namespace std;
int main()
{
    int n,m,x;
    cin>>n>>m>>x;
    int a[n+1][m+1];
    a[0][0]=x;//若用a[i][i]=x+(i-1)*i;此处应改为a[0][0]=0;
    for(int i=1;i<=m;i++)
    {
       a[i][i]=a[i-1][i-1]+(i-1)*2;//还可以用a[i][i]=x+(i-1)*i;原式：a[i][i]=x+(0+2*(i-1))*i/2;
       for(int j=1;j<i;j++)
       {
           a[j][i]=a[i][i]-(i-j);//或者用a[j][i]=x+((i-1)*2-1)*i/2+j-1;原式：a[j][i]=x+(0+(i-1)*2-1)*i/2+j-1;还可以用a[j][i]=(i-1)*2-1+a[1][i-1]+j-1;
           a[i][j]=a[i][i]+i-j;//或者用a[i][j]=x+i*i-1-(j-1);原式：a[i][j]=x+(1+i*2-1)*i/2-1-(j-1); 还可以用a[i][j]=a[i-1][1]+i*2-1-(j-1);
       }
    }
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
        printf("%-3d",a[i][j]);
        if(!(m-j))cout<<endl;
    }
    cin.get();
    cin.get();
}