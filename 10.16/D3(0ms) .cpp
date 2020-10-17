#include<iostream>
#include<math.h>
using namespace std;
int check(int a)
{
   int sum=1,s=sqrt(a);
   for(int i=2;i<=s;i++)//此处必须取等，例如sqrt（110）=10，但10是110的约数
      sum=a%i?sum:sum+i+a/i;
    sum=s*s==a?sum-s:sum;//判断条件不能给错！
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