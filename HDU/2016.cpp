#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num[100],n,min=0;
    cin>>n;
    while(n)
    {
        
        for(int i=0;i<n;i++){cin>>num[i];min=num[i]<num[min]?i:min;}
        swap(num[min],num[0]);
        for(int i=0;i<n;i++)if(i)cout<<" "<<num[i];else cout<<num[i];
        cout<<endl;
        min=0;
        cin>>n;
    }   
}
