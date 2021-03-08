#include<iostream>
using namespace std;
int main()
{
    string num;
    long long sum;
    cin>>num;
    while(num[0]!='0')
    {
         sum=0;
         for(int i=0;i<num.size();i++)
         sum+=num[i]-'0';
         int x;
         while(sum>=10)
         {
             x=0;
             while(sum)
             {
                 x+=sum%10;
                 sum/=10;
             }
             sum=x;
         }
         cout<<sum<<endl;
         cin>>num;
    }
    cin.get();
    cin.get();
}
