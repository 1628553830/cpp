#include<iostream>
using namespace std;
int main()
{
    string a,b;
    int total=0;
    cin>>a;
    while(a!="#")
    {
        cin>>b;
        for(int i=0;i<=int(a.length()-b.length());i++)
        if(a.substr(i,b.length())==b){a=a.substr(0,i)+a.substr(i+b.length());total++;i--;}
        cout<<total<<endl;
        total=0;
        cin>>a;
    }
}