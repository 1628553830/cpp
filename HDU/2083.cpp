#include<iostream>
#include<climits>
using namespace std;
int main()
{
    int M,N,zb[501],min=INT_MAX,sum=0;
    cin>>M;
    while(M--)
    {
        cin>>N;
        for(int i=1;i<=N;i++)
        cin>>zb[i];
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            sum+=abs(zb[i]-zb[j]);
            min=min<sum?min:sum;sum=0;
        }
        cout<<min<<endl;
        min=INT_MAX;
        sum=0;
    }
    cin.get();
    cin.get();
}