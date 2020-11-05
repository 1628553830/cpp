#include<iostream>
using namespace std;
int main()
{
    int num[56]{0,1,2,3,4},n;
    cin>>n;
    for(int i=5;i<=55;i++)
    {
        for(int j=1;j<i;j++)
             num[i]=i-j-2>0?num[i]+num[i-j-2]:num[i]+1; 
        num[i]++;
    }
    while(n)
    {
       cout<<num[n]<<endl;
       cin>>n;
    }

}