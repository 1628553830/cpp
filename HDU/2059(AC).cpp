#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int main()
{
    int L,N,C,T,num[102]{};
    double VR,VT1,VT2,dp[102]{},Min,time=0;
    while(cin>>L>>N>>C>>T>>VR>>VT1>>VT2)
    {
        for(int i=1;i<=N;i++)cin>>num[i];
        num[N+1]=L;
        for(int i=1;i<=N+1;i++)
        {
            Min=INT_MAX;
            time=0;
            for(int j=0;j<i;j++)
            {
                if(j)time=T;
                if(num[i]-num[j]<=C)
                   time+=(num[i]-num[j])/VT1;
                else 
                   time+=C/VT1+(num[i]-num[j]-C)/VT2;
                Min=min(time+dp[j],Min);
            }
            dp[i]=Min;
        }
        if(dp[N+1]<L/VR)cout<<"What a pity rabbit!\n";
        else cout<<"Good job,rabbit!\n";
    }
    


}