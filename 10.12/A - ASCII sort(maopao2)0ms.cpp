#include<iostream>
using namespace std;
int main()
{
    char a[4];
    while(cin>>a)
    {
        for(int i=0;i<2;i++)
        {
            for(int j=2;j>i;j--)
            if(a[j]<a[j-1]){char s=a[j];a[j]=a[j-1];a[j-1]=s;}
            cout<<a[i]<<" ";
        }
        cout<<a[2]<<endl;
    }
    cin.get();
    cin.get();

}