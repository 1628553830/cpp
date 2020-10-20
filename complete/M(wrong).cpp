#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a[100];
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
       cin>>a[i];
    for(int i=0;i<n;i++)
    {
      int min=i;
      for(int j=i+1;j<n;j++)if(a[j]<a[min])min=j;
      if(min!=i)swap(a[min],a[i]);
      cout<<a[i];
    }
    cout<<endl;
    cin.get();
    cin.get();
}