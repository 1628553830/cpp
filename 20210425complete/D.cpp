#include<iostream>
using namespace std;
int ll(int);
int main()
{
   long long A,B,X,i;
   long long left,right,mid;
   cin>>A>>B>>X;
   right=X/A<1e9?X/A:1e9;
   left=0;
   mid=(left+right)/2;
   while(left<=right)
   {
       if(A*mid+B*ll(mid)<=X)left=mid+1;
       else right=mid-1;
       mid=(left+right)/2;
   }
   if(right<0)right=0;
   cout<<right<<endl;
   cin.get();
   cin.get();
}
int ll(int x)
{
    int count=1;
    while(x/10)
    {
        count++;
        x/=10;
    }
    return count;
}