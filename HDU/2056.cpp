#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    double x1,y1,x2,y2,x3,y3,x4,y4,l1,l2,sum;
    cout.precision(2);
    while(cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4)
    {
        l1=min(max(x1,x2),max(x3,x4))-max(min(x1,x2),min(x3,x4));
        l2=min(max(y1,y2),max(y3,y4))-max(min(y1,y2),min(y3,y4));
        sum=l1<0||l2<0?0:l1*l2;
        cout<<fixed<<sum<<endl;
    }

}