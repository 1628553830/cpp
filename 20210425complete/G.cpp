#include<iostream>
using namespace std;
int main()
{
    int A,B,C;
    cin>>A>>B>>C;
    if(B+C<=A)
    cout<<0<<endl;
    else
    cout<<B+C-A<<endl;
}
