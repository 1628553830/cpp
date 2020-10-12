#include<iostream>
using namespace std;
int main()
{
    char a[4];
    while(cin>>a)
    {
        for(int i=0;i<2;i++)
        {
           int min=i;
           for(int j=i+1;j<3;j++)if(a[j]<a[min])min=j;
           if(min!=i){char s=a[min];a[min]=a[i];a[i]=s;}
           cout<<a[i]<<" ";
        }
        cout<<a[2]<<endl;

    }
    cin.get();
    cin.get();

}