#include<iostream>
using namespace std;
int main()
{
    long long high=0,low=0,h=1,l=0;
    int n;
    cin>>n;
    while(n!=-1)
    {
        while(n--)
        {
            high=h*3+l*2;
            low=h+l;
            h=high;
            l=low;
        }
        cout<<h<<", "<<l<<endl;
        cin>>n;
        low=high=l=0;
        h=1;
    }
    
}