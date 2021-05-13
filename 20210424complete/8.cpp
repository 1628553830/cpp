#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    int a;
    double result;
    cout.precision(2);
    cin>>n;
    while(n--)
    {
        result=0;
        cin>>a;
        for(int i=0;i<a;i++)
        {
            result+=(1-i%2*2)*(1.0/(i+1));
        }
        cout<<fixed<<result<<endl;
    }
    cin.get();
    cin.get();
}