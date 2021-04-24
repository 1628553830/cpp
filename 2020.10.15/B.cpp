#include<iostream>
#include<climits>
using namespace std;
int main()
{
    long n,m,a;
    cin>>n>>m>>a;
    n=n%a?n/a+1:n/a;
    m=m%a?m/a+1:m/a;
    cout<<(long long)n*m;
}