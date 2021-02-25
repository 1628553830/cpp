#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,s1=0,s2=0,s3=0,s4=0;
    double ms[2000],fs[30],fm[2000],h1[2000],ans=0;
    cin>>n;
    while(n<=120&&n>=0)
    {
        for(int i=0;(n+360*i)*720.0/719<259200;i++)
        {
            ms[s1++]=(n+360*i)*720.0/719;
            ms[s1++]=((i+1)*360-n)*720.0/719;
        }

        for(int i=0;(n+360*i)*720.0/11<259200;i++)
        {
            fs[s2++]=(n+360*i)*720.0/11;
            fs[s2++]=((i+1)*360-n)*720.0/11;
        }

        for(int i=0;(n+360*i)*60.0/59<259200;i++)
        {
            fm[s3++]=(n+360*i)*60.0/59;
            fm[s3++]=((i+1)*360-n)*60.0/59;
        }
        //合并fs和fm,并入h1之中
        for(int i=0;i<s2;i+=2)
          for(int j=0;j<s3&&fm[j]<fs[i+1];j+=2)
          {
              if(fm[j+1]>fs[i])
              {
                  h1[s4++]=max(fm[j],fs[i]);
                  h1[s4++]=min(fm[j+1],fs[i+1]);
              }
          }
        //合并h1和ms,并入fm
        s3=0;
        for(int i=0;i<s4;i+=2)
        for(int j=0;j<s1&&ms[j]<h1[i+1];j+=2)
        {
            if(ms[j+1]>h1[i])
            {
                fm[s3++]=max(ms[j],h1[i]);
                fm[s3++]=min(ms[j+1],h1[i+1]);
            }
        }
        for(int i=0;i<s3;i+=2)ans+=fm[i+1]-fm[i];
        printf("%.3f\n",ans/259200*100);
        s1=s2=s3=s4=ans=0;
        cin>>n;
    }
    cin.get();
    cin.get();
}