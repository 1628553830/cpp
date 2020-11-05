#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num[50][5],ans=0,sum1[50]{},sum2[5]{};
    double n,m;
    while(cin>>n>>m)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>num[i][j];
                sum1[i]+=num[i][j];
                sum2[j]+=num[i][j];
            }
            if(i)
            printf(" %.2lf",sum1[i]/m);//c++的cout.precision()函数以及setpricision()函数均不好用；
            else 
            printf("%.2lf",sum1[i]/m);
        }
        cout<<endl;
        for(int i=0;i<m;i++)
            if(i)
            printf(" %.2lf",sum2[i]/n);
            else 
            printf("%.2lf",sum2[i]/n);
        cout<<endl;
        for(int i=0;i<n;i++)
            {
                bool flag=true;
                for(int j=0;j<m;j++)
                  if(num[i][j]<sum2[j]/n){flag=false;break;}
                if(flag)ans++;
            }
        cout<<ans<<endl<<endl;
        ans=0;
        memset(sum1,0,sizeof(sum1));
        memset(sum2,0,sizeof(sum2));
    }
}
    