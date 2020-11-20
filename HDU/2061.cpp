#include<iostream>
using namespace std;
int main()
{
    int N,K;bool flag=false;
    double GPA=0,sum=0;
    string a;
    cin>>N;
    cout.precision(2);
    while(N--)
    {
        cin>>K;
        double C[K],S[K];
        for(int i=0;i<K;i++)
        {
            cin>>a>>C[i]>>S[i];
            sum+=C[i];
            GPA+=C[i]*S[i];
            if(S[i]<60)flag=true;
        }
       GPA/=sum;
       if(flag)cout<<"Sorry!\n";
       else cout<<fixed<<GPA<<endl;
       if(N)cout<<endl;
       flag=GPA=sum=0;
    }
    cin.get();
    cin.get();
}