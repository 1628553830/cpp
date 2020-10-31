#include<iostream>
using namespace std;
int main()
{
    int f=0,z=0,l=0,n,m;
    float x;
    cin>>n;
    while(n)
    {
        while(n--)
        {
            cin>>x;
            m=x>0?1:x<0?-1:0;
            switch (m)
            {
            case 1:z++;
                   break;
            case 0:l++;
                   break;
            default:f++;
                
            }
        }
        cout<<f<<" "<<l<<" "<<z<<endl;
        f=l=z=0;
        cin>>n;
    }
    
}