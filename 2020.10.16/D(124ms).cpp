#include<iostream>
#include<math.h>
using namespace std;
int check(int a)
{
   int sum=0;
   for(int i=1;i<a;i++)
      sum=a%i?sum:sum+i;
    return sum;
}
int main()
{
    int n,a,b;
    
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        if (check(a)==b&&check(b)==a)
        cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}