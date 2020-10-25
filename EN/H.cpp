#include<iostream>
using namespace std;
int main()
{
    string a;
    getline(cin,a);
    for(int i=0;i<a.length();i++)
    {
        if(a[i]!=' ')cout<<a[i];
        else 
        {
            cout<<a[i];
            while (a[i++]==' ');
            i-=2;
        }
    }
    cin.get();
    cin.get();
}