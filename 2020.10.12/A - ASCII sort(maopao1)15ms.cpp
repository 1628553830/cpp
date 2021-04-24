#include<iostream>
using namespace std;
int main()
{
    char a[4];
    while(cin>>a)
    {
        for(int i=0;i<2;i++)
        for(int j=0;j<2-i;j++)
        if(a[j]>a[j+1]){char s=a[j];a[j]=a[j+1];a[j+1]=s;}
        for(int i=0;i<3;i++)if(i!=2)cout<<a[i]<<" ";else cout<<a[i]<<endl;

    }
    cin.get();
    cin.get();

}