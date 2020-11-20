#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N,M,num[100][2],ans=0,a1;
    cin>>N>>M;
    while(N||M)
    { 
        for(int len=1;(2*M+len-len*len)/(2*len)>0;len++)
            {
                a1=(2*M+len-len*len)/(2*len);
                if((2*a1+len-1)*len/2==M&&a1+len-1<=N)
                {
                    num[ans][0]=a1;
                    num[ans++][1]=a1+len-1;
                }  
            }
        for(int i=ans-1;i>=0;i--)
           cout<<"["<<num[i][0]<<","<<num[i][1]<<"]\n";
        cout<<endl;
        ans=0;
        cin>>N>>M;          
    }
}
