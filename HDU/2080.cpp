#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int N;
    double x1,x2,y1,y2;
    cin>>N;
    cout.precision(2);
    while(N--)
    {
        cin>>x1>>y1>>x2>>y2;
        cout<<fixed<<acos((x1*x2+y1*y2)/sqrt((x1*x1+y1*y1)*(x2*x2+y2*y2)))*180/acos(-1)<<endl;
    }
    cin.get();
    cin.get();
}