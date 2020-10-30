#include<iostream>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        if(90<=n&&n<=100)cout<<"A"<<endl;
        else if(80<=n&&n<90)cout<<"B"<<endl;
        else if(70<=n&&n<80)cout<<"C"<<endl;
        else if(60<=n&&n<70)cout<<"D"<<endl;
        else if(0<=n&&n<60)cout<<"E"<<endl;
        else cout<<"Score is error!"<<endl;
    }
}