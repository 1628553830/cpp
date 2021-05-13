#include<iostream>
using namespace std;
int gcd(int m,int n)
{
    int r;
    while (m%n)
    {
        r=m%n;
        m=n;n=r;
    }
    return n; 
}
int main()
{
    
}