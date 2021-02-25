#include<iostream>
using namespace std;
int main()
{
    int n,result,pre,temp;
    cin>>n;
    while(n)
    {
        result=pre=0;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            result=temp>pre?result+(temp-pre)*6+5:result+(pre-temp)*4+5;
            pre=temp;
        }
        cout<<result<<endl;
        cin>>n;
    }
}