#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    double D,N,C,T,VR,VT1,VT2,p[102]{},tr,tt=0,w1,w2,t,s;
    while(cin>>D)
    {
        cin>>N>>C>>T>>VR>>VT1>>VT2;
        tr=D/VR;
        if(VT1<=VT2){tt=D/VT2;goto m;}
        for(int i=1;i<=N;i++)
            cin>>p[i];
        p[int(N+1)]=D;
        s=C;
        for(int i=1;i<=N+1;i++)
        {
            if(i==1)t=0;
            else t=T;
            w1=p[i]-p[i-1]>C?C/VT1+(p[i]-p[i-1]-C)/VT2+t:(p[i]-p[i-1])/VT1+t;
            w2=s<p[i]-p[i-1]?s/VT1+(p[i]-p[i-1]-s)/VT2:(p[i]-p[i-1])/VT1;
            if(w1<w2)
            {
                tt+=w1;
                s=C-p[i]+p[i-1]<0?0:C-p[i]+p[i-1];
            }
            else 
            {
                tt+=w2;
                s=s-p[i]+p[i-1]<0?0:s-p[i]+p[i-1];
            }
        }
m:      if(tt<tr)cout<<"What a pity rabbit!\n";
        else cout<<"Good job,rabbit!\n";
        tt=0;
    }

}