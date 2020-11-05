#include<iostream>
using namespace std;
int main()
{
    double a,b;
    while(cin>>a>>b)
    {
        cout.precision(2);
        cout<<fixed<<"a/b in precision(2)"<<a/b<<endl;
        printf("a/b in printf (%%.2f) %.2f\n",a/b);
    }

}