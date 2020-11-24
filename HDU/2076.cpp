#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    double hour,minute,second,T;
    int result;
    cin>>T;
    while(T--)
    {
        cin>>hour>>minute>>second;
        hour=hour-int(hour/12)*12;
        hour=hour*30+(minute*60+second)/120;
        minute=(minute*60+second)/10;
        result=abs(hour-minute)<=180?abs(hour-minute):360-abs(hour-minute);
        cout<<result<<endl;
    }
    cin.get();
    cin.get();
}